#include "tasks/i2c_task.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "FreeRTOS.h"
#include "task.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/gpio.h"

#include "config/pinmap.h"

#define I2C_SCAN_PERIOD_MS      10000
#define I2C_TASK_STACK_WORDS    512
#define I2C_TASK_NAME           "i2c-scan"

/* I2C reserved addresses per the spec: 000 0xxx and 111 1xxx.
 * Skip them so we don't probe weirdness like the general-call address. */
static bool i2c_addr_is_reserved(uint8_t addr) {
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

static void i2c_bus_scan(void) {
    int found = 0;
    printf("[i2c] scanning %s (sda=GP%d scl=GP%d @ %u Hz)\n",
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
            printf("[i2c]   found device at 0x%02X\n", addr);
            ++found;
        }
    }

    if (found == 0) {
        printf("[i2c] no devices responded — check pull-ups, power, wiring\n");
    } else {
        printf("[i2c] scan complete — %d device(s)\n", found);
    }
}

static void i2c_task(void *pvParameters) {
    (void)pvParameters;

    i2c_init(IHU_I2C_EPS_INSTANCE, IHU_I2C_EPS_HZ);
    gpio_set_function(IHU_I2C_EPS_SDA_GPIO, GPIO_FUNC_I2C);
    gpio_set_function(IHU_I2C_EPS_SCL_GPIO, GPIO_FUNC_I2C);
    /* On-MCU pull-ups for bench bring-up. Flight board has dedicated
     * 4.7 k pull-ups on the EPS side, but enabling these is harmless
     * because they're 50-80 k weak internal pulls. */
    gpio_pull_up(IHU_I2C_EPS_SDA_GPIO);
    gpio_pull_up(IHU_I2C_EPS_SCL_GPIO);

    /* Let the console task print its banner first. */
    vTaskDelay(pdMS_TO_TICKS(2000));

    for (;;) {
        i2c_bus_scan();
        vTaskDelay(pdMS_TO_TICKS(I2C_SCAN_PERIOD_MS));
    }
}

BaseType_t ihu_i2c_task_start(UBaseType_t priority) {
    return xTaskCreate(i2c_task, I2C_TASK_NAME,
                       I2C_TASK_STACK_WORDS, NULL, priority, NULL);
}
