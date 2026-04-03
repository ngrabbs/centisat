# Electrical Power System (EPS)

## Purpose

This directory contains the EPS design baseline, implementation status, and
bench validation plan for the modular CubeSat platform.

## Current Architecture Baseline

- Battery: 2S2P LG MJ1 18650 pack
- Solar input: SM141K10TF panel set (3S/3S2P under evaluation)
- Charge control: LTC4162 (MPPT + telemetry)
- Regulation: TPSM5D1806 dual buck module for 5 V and 3.3 V rails

## Design and Implementation Status

### Battery Subsystem

- Completed: selected LG MJ1 18650 cells in 2S2P configuration
- Pending: add PTC/polyfuse overcurrent protection
- Pending: finalize balancing strategy or cell-matching process
- Pending: finalize battery pack mounting and retention
- Pending: add battery voltage/temperature telemetry to MCU interface

### Solar Subsystem

- Completed: selected SM141K10TF panels
- Pending: characterize max current/voltage per panel face
- Pending: finalize wiring and connector routing
- Pending: validate panel behavior vs illumination angle
- Pending: connect orbital charging assumptions to EPS model inputs

### Charge and Regulation Subsystem

- Completed: selected LTC4162 charge controller
- Completed: selected TPSM5D1806 dual buck module
- Pending: validate breadboard charging/regulation flow
- Pending: characterize MPPT behavior for expected panel conditions
- Pending: finalize input protection (TVS/clamping and fault handling)
- Pending: implement and verify charge-path enable/disable logic

### EPS PCB and Integration

- Pending: complete integrated EPS schematic and layout details
- Pending: add telemetry points (battery voltage, charge state, load current)
- Pending: evaluate optional safety disconnect/pyrofuse approach
- Pending: verify power-on reset and startup behavior
- Pending: add test points and debug headers for bring-up
- Pending: finalize layout and release manufacturing package

## Phase 1 Bench Validation Plan

### Test 1: LTC4162 Eval Board (MPPT Charger)

Objective:
- Evaluate solar-powered Li-ion charging with 2S2P pack assumptions
- Validate MPPT behavior and charge-state telemetry
- Confirm CC/CV transition behavior

Procedure:
1. Connect representative 2S2P battery pack to BAT terminals
2. Connect representative 3S panel input to VIN
3. Sweep light/input conditions and observe MPPT response
4. Log battery voltage/current, charge status, and input power over time
5. Remove solar input and observe PowerPath transition behavior
6. Apply thermistor boundary conditions and observe charging response

Primary Measurements:
- VIN, VBAT, ICHARGE
- MPPT tracking behavior vs input condition
- Charging time and stability under controlled load

### Test 2: TPSM5D1806 Eval Board (Dual Buck)

Objective:
- Validate 5 V and 3.3 V rail stability from battery/charger source
- Characterize load regulation and thermal behavior

Procedure:
1. Drive VIN from battery-equivalent source or charger output
2. Load CH1 (5 V) across 1 A, 2 A, and 3 A points
3. Load CH2 (3.3 V) across 0.5 A and 1 A points
4. Measure voltage regulation, ripple, and thermal rise at each point

Primary Measurements:
- VIN, VOUT1, VOUT2, IIN, IOUT, temperature
- Efficiency and ripple across load profile

### Test 3: SM141K10TF Panel Characterization

Objective:
- Validate panel behavior under realistic illumination and loading
- Select best series/parallel configuration for charger input

Procedure:
1. Measure VOC and ISC for single panel conditions
2. Build 3-series configuration and measure open-circuit and loaded behavior
3. Capture I-V points with resistive/electronic load sweep
4. Connect to charger input and observe startup/charging interactions

Primary Measurements:
- VOC, ISC, VMP, IMP
- Delivered charging power under representative conditions

### Test 4: Dynamic Load Validation

Objective:
- Validate rail robustness under subsystem-like load profiles
- Evaluate transient response and regulation recovery

Procedure:
1. Apply electronic load to 5 V and 3.3 V rails
2. Sweep from 0.1 A to 3 A where applicable
3. Introduce load-step transients and capture response
4. Record droop, overshoot, and thermal behavior

Primary Measurements:
- V, I, and derived power
- Ripple, droop, overshoot, and thermal rise

## Directory Structure

```plaintext
hardware/eps/
├── README.md
├── eps/
│   ├── eps.kicad_pro
│   ├── eps.kicad_sch
│   └── eps.kicad_pcb
└── components/
    ├── LTC4162/
    ├── TPSM5D1806/
    ├── SM141K10TF/
    └── FDMC8327L/
```
