# EPS Phase 1 Validation Plan

## Scope

Phase 1 validates EPS source, charging, and regulation behavior at bench level
before full subsystem integration.

## Provisional Numeric Criteria (Rev A)

These limits are intentionally conservative placeholders so testing can proceed
before final subsystem current budgets are locked.

- `5V_RAIL` steady-state: 4.85 V to 5.15 V for 0.1 A to 2.0 A load
- `3V3_RAIL` steady-state: 3.20 V to 3.40 V for 0.1 A to 2.0 A load
- Ripple target (20 MHz bandwidth limit):
  - 5 V rail: <= 100 mVpp
  - 3.3 V rail: <= 75 mVpp
- Dynamic step response target (25% to 75% load step):
  - Peak droop/overshoot <= +/-5% of nominal rail
  - Recovery to within +/-2% in <= 2 ms
- Thermal screening target:
  - < 40 C rise above ambient on hottest observed component during 10-minute
    hold at 2.0 A per rail equivalent load case

## Test 1: LTC4162 MPPT Charger Bring-Up

### Objective

- Validate solar-to-battery charging behavior for 2S assumptions
- Verify MPPT response under changing input conditions
- Verify charger telemetry observability

### Procedure

1. Connect representative 2S2P battery pack to BAT terminals
2. Connect representative 3S panel input to VIN
3. Sweep light/input condition and observe MPPT behavior
4. Log battery voltage/current, charge state, and input power over time
5. Remove solar input and observe PowerPath transition behavior
6. Exercise thermistor boundary conditions and record behavior

### Measurements

- `VIN`, `VBAT`, `ICHARGE`
- MPPT tracking behavior over changing input
- Charge-state transitions and stability

### Initial Acceptance Criteria

- Charger enters valid charge state and transitions are observable
- No unexpected oscillation or dropout in nominal test range
- PowerPath behavior transitions cleanly when input source is removed

## Test 2: TPSM5D1806 Dual-Buck Validation

### Objective

- Validate 5 V and 3.3 V rail stability from representative EPS input
- Characterize load regulation, ripple, and thermal behavior

### Procedure

1. Drive VIN from battery-equivalent source or charger output
2. Apply load profile on CH1 (5 V): 0.5 A, 1 A, 2 A
3. Apply load profile on CH2 (3.3 V): 0.5 A, 1 A, 2 A
4. Measure regulation behavior and thermal rise at each step

### Measurements

- `VIN`, `VOUT1`, `VOUT2`, `IIN`, `IOUT`, temperature
- Ripple and efficiency across load points

### Initial Acceptance Criteria

- 5 V and 3.3 V rails remain inside provisional steady-state limits
- Ripple remains within provisional targets
- Thermal rise remains within provisional screening target
- Transient response meets provisional step-response target

## Test 3: SM141K10TF Panel Characterization

### Objective

- Establish realistic panel behavior under expected illumination variation
- Select preferred 3S/3S2P wiring for charger input

### Procedure

1. Measure `VOC` and `ISC` for representative panel conditions
2. Build series configuration and measure open-circuit and loaded behavior
3. Capture I-V points with resistive/electronic load sweep
4. Connect panel configuration to charger input and observe startup behavior

### Measurements

- `VOC`, `ISC`, `VMP`, `IMP`
- Delivered charging power into EPS path

### Initial Acceptance Criteria

- Measured panel performance supports selected charge architecture assumptions
- Startup and charging behavior are repeatable under equivalent conditions

## Test 4: Dynamic Load Behavior

### Objective

- Validate EPS output robustness under load-step conditions
- Characterize droop/overshoot and recovery behavior

### Procedure

1. Apply programmable electronic load to 5 V and 3.3 V rails
2. Sweep from 0.1 A to applicable max current points
3. Execute step-load transitions and capture waveforms
4. Record droop, overshoot, ripple, and thermal response

### Measurements

- Voltage, current, derived power
- Ripple, droop, overshoot, recovery time

### Initial Acceptance Criteria

- Rails recover to within +/-2% in <= 2 ms after defined load steps
- Peak droop/overshoot remains <= +/-5% of nominal rail
- No unsafe thermal or stability behavior under defined profiles

## Evidence Capture Requirements

- Save scope screenshots and instrument logs per test case
- Record test setup (sources, load settings, ambient conditions)
- Store outputs under `hardware/eps/bringup/` with date/version labels

## Exit Condition for Phase 1

- Core charge and regulation behavior is repeatable and documented
- Open EPS risks are narrowed to integration-level items
- Inputs are ready for integrated system validation planning
