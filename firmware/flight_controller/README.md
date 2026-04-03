# Flight Controller Firmware Roadmap

## Purpose

Track firmware architecture and implementation milestones for the RP2040-based
flight controller.

## Core Responsibilities

- System mode manager (safe, nominal, high-duty)
- Command parser, validation, and dispatch
- Subsystem link supervision (I2C/SPI, later CAN)
- Telemetry aggregation and framing handoff to comms
- Fault handling, retry policy, and recovery coordination

## Workstreams

### Workstream A: Runtime and State Machine

- [ ] Define explicit state machine for mode transitions
- [ ] Implement boot sequence and health gating checks
- [ ] Enforce default safe mode at boot until EPS I2C and comms SPI links are
  both healthy for N consecutive checks
- [ ] Implement safe-mode entry/exit conditions and actions

### Workstream B: Interface Drivers and Link Management

- [ ] Implement EPS housekeeping I2C client
- [ ] Implement FC-comms SPI packet transport with CRC and sequence counter
- [ ] Implement link heartbeat and timeout handling
- [ ] Add CAN transport abstraction for Iteration 2

### Workstream C: Command and Telemetry Services

- [ ] Implement command schema decode and dispatch table
- [ ] Implement ACK/NACK and execution result reporting
- [ ] Implement telemetry collection scheduler and queueing
- [ ] Implement priority policy (preserve safety alerts under congestion)

### Workstream D: Reliability and Diagnostics

- [ ] Integrate watchdog and reset-reason reporting
- [ ] Add structured fault/event log
- [ ] Add debug CLI/UART diagnostics for bring-up

## Phase 1 Exit Criteria

- [ ] FC boots to deterministic safe state and reports reset reason
- [ ] Stable I2C polling and SPI packet exchange with bounded retry behavior
- [ ] Command/telemetry loop closes with reproducible test results

## Related Documents

- FC hardware architecture: `hardware/flight_controller/design/overview.md`
- FC interfaces: `hardware/flight_controller/design/interfaces.md`
- FC bring-up tests: `hardware/flight_controller/bringup/phase1_validation.md`
