#include "tasks/eps_monitor_task.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "FreeRTOS.h"
#include "task.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/gpio.h"

#include "config/pinmap.h"
#include "drivers/ltc4162.h"

#define EPS_POLL_PERIOD_MS      5000
#define EPS_TASK_STACK_WORDS    768       /* printf with floats eats stack */
#define EPS_TASK_NAME           "eps-mon"

/* ------------------------------------------------------------------
 * One-shot bus diagnostics — useful at boot, then we stop scanning.
 * ----------------------------------------------------------------*/

/* I2C reserved addresses per the spec: 000 0xxx and 111 1xxx.
 * Skip them so we don't probe weirdness like the general-call address. */
static bool i2c_addr_is_reserved(uint8_t addr) {
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

static void i2c_bus_scan_once(void) {
    int found = 0;
    printf("[eps] scanning %s (sda=GP%d scl=GP%d @ %u Hz)\n",
           IHU_I2C_EPS_INSTANCE == i2c0 ? "i2c0" : "i2c1",
           IHU_I2C_EPS_SDA_GPIO, IHU_I2C_EPS_SCL_GPIO,
           (unsigned)IHU_I2C_EPS_HZ);

    for (uint8_t addr = 0; addr < 0x80; ++addr) {
        if (i2c_addr_is_reserved(addr)) {
            continue;
        }
        uint8_t rx;
        int ret = i2c_read_blocking(IHU_I2C_EPS_INSTANCE, addr, &rx, 1, false);
        if (ret >= 0) {
            printf("[eps]   found device at 0x%02X%s\n", addr,
                   addr == IHU_EPS_LTC4162_ADDR ? " (LTC4162)" : "");
            ++found;
        }
    }

    if (found == 0) {
        printf("[eps] no devices responded — check pull-ups, power, wiring\n");
    } else {
        printf("[eps] scan complete — %d device(s)\n", found);
    }
}

/* ------------------------------------------------------------------
 * LTC4162 telemetry pretty-printer
 * ----------------------------------------------------------------*/
static void print_telemetry(const ltc4162_telemetry_t *t) {
    printf("[ltc4162] state=%s  charge=%s  sys=0x%04X\n",
           ltc4162_state_string(t->charger_state),
           ltc4162_charge_status_string(t->charge_status),
           t->system_status);
    printf("[ltc4162]   V_IN=%6.3f V   V_OUT=%6.3f V   V_BAT=%6.3f V\n",
           t->v_in, t->v_out, t->v_bat);
    printf("[ltc4162]   I_IN=%+7.1f mA  I_BAT=%+7.1f mA  (positive = charging)\n",
           t->i_in_ma, t->i_bat_ma);

    /* Surface system_status conditions. cell_count_err and no_rt
     * intentionally suppressed here — per datasheet pp. 44-45 both
     * assert any time the charger isn't enabled (e.g. battery-only
     * operation), so they're noise unless VIN is actually present. */
    if (t->system_status & LTC4162_SYS_THERMAL_SHUTDOWN) {
        printf("[ltc4162]   ALERT: thermal shutdown\n");
    }
    if (t->system_status & LTC4162_SYS_VIN_OVLO) {
        printf("[ltc4162]   ALERT: VIN over-voltage lockout (>38.6V)\n");
    }
    if (t->system_status & LTC4162_SYS_VIN_GT_VBAT) {
        if (t->system_status & LTC4162_SYS_CELL_COUNT_ERR) {
            printf("[ltc4162]   ALERT: cell-count mismatch (expected %dS)\n",
                   IHU_EPS_BATTERY_CELLS);
        }
        if (t->system_status & LTC4162_SYS_NO_RT) {
            printf("[ltc4162]   ALERT: no Rt resistor detected\n");
        }
    } else {
        printf("[ltc4162]   note: VIN <= VBAT, running on battery (no charge input)\n");
    }
}

/* ------------------------------------------------------------------
 * Task body
 * ----------------------------------------------------------------*/
static void eps_monitor_task(void *pvParameters) {
    (void)pvParameters;

    i2c_init(IHU_I2C_EPS_INSTANCE, IHU_I2C_EPS_HZ);
    gpio_set_function(IHU_I2C_EPS_SDA_GPIO, GPIO_FUNC_I2C);
    gpio_set_function(IHU_I2C_EPS_SCL_GPIO, GPIO_FUNC_I2C);
    /* On-MCU pull-ups for bench bring-up. Flight EPS has dedicated
     * 4.7 k pull-ups; enabling these is harmless (they're 50-80 k weak). */
    gpio_pull_up(IHU_I2C_EPS_SDA_GPIO);
    gpio_pull_up(IHU_I2C_EPS_SCL_GPIO);

    /* Let the console task print its banner first. */
    vTaskDelay(pdMS_TO_TICKS(2000));

    i2c_bus_scan_once();

    if (!ltc4162_present(IHU_I2C_EPS_INSTANCE, IHU_EPS_LTC4162_ADDR)) {
        printf("[eps] LTC4162 not detected at 0x%02X — telemetry polling disabled\n",
               IHU_EPS_LTC4162_ADDR);
        /* Park the task — keeps it visible in uxTaskGetNumberOfTasks. */
        for (;;) {
            vTaskDelay(pdMS_TO_TICKS(60000));
        }
    }

    if (ltc4162_init(IHU_I2C_EPS_INSTANCE, IHU_EPS_LTC4162_ADDR)) {
        printf("[eps] LTC4162 init OK (force_telemetry_on set, fault state cleared)\n");
    } else {
        printf("[eps] LTC4162 init write FAILED — telemetry may stay at zero\n");
    }

    printf("[eps] starting telemetry poll @ %d s cadence\n",
           EPS_POLL_PERIOD_MS / 1000);

    uint32_t poll = 0;
    for (;;) {
        ltc4162_telemetry_t t;
        if (ltc4162_read_telemetry(IHU_I2C_EPS_INSTANCE,
                                   IHU_EPS_LTC4162_ADDR, &t)) {
            printf("[ltc4162] poll #%lu\n", (unsigned long)poll);
            print_telemetry(&t);
        } else {
            printf("[ltc4162] poll #%lu — read failed (I2C error)\n",
                   (unsigned long)poll);
        }
        ++poll;
        vTaskDelay(pdMS_TO_TICKS(EPS_POLL_PERIOD_MS));
    }
}

BaseType_t ihu_eps_monitor_task_start(UBaseType_t priority) {
    return xTaskCreate(eps_monitor_task, EPS_TASK_NAME,
                       EPS_TASK_STACK_WORDS, NULL, priority, NULL);
}
