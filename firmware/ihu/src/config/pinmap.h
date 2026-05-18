/*
 * Centisat IHU pin assignments.
 *
 * v0.1 proto: bare Raspberry Pi Pico on a riser above the EPS board,
 * connected to the CSKB stack header. Pin numbers reflect the planned
 * flight schematic (hardware/ihu/design/altium_ihu_schematic.md) so
 * the proto firmware ports unchanged to the real PCB.
 */

#pragma once

#include "hardware/i2c.h"

/* Standard Pico onboard LED (single green LED tied to GP25 on the
 * plain RP2040 module — Pico W is different). */
#define IHU_LED_GPIO            25

/* I2C0 to EPS LTC4162 charger via CSKB H1.41 (SDA) / H1.43 (SCL).
 * Routed to RP2040 GP4/GP5 on the IHU board. */
#define IHU_I2C_EPS_INSTANCE    i2c0
#define IHU_I2C_EPS_SDA_GPIO    4
#define IHU_I2C_EPS_SCL_GPIO    5
#define IHU_I2C_EPS_HZ          (100 * 1000)  /* 100 kHz standard mode for bring-up */
