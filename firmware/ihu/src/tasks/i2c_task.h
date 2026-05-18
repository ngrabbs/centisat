/*
 * I2C task — periodically scans the EPS I2C bus (i2c0 on GP4/GP5) and
 * prints any detected slave addresses to the console.
 *
 * Phase 1 (now): bus scan only — confirms the bus is wired correctly
 * and that pull-ups + EPS LTC4162 are present. Phase 2 (later): decode
 * LTC4162 charger telemetry; see firmware/ihu/README.md Workstream B.
 */

#pragma once

#include "FreeRTOS.h"
#include "task.h"

BaseType_t ihu_i2c_task_start(UBaseType_t priority);
