# Flight Controller Hardware

## Purpose

This directory tracks flight-controller architecture, board interfaces, and
bring-up validation for the RP2040-based system controller.

## Architecture Snapshot

- MCU baseline: RP2040
- Primary role: command authority, mode management, and telemetry aggregation
- Near-term interconnects: I2C (EPS housekeeping), SPI (comms data path)
- Planned expansion: CAN control plane (Iteration 2)

## Documentation Map

- Architecture and rationale: `hardware/flight_controller/design/overview.md`
- Electrical and logical interfaces: `hardware/flight_controller/design/interfaces.md`
- Bring-up and acceptance criteria: `hardware/flight_controller/bringup/phase1_validation.md`

## Status Summary

- Completed: FC role and interconnect direction defined in system docs
- In progress: detailed interface closure, boot/runtime behavior, and bring-up plan
- Open items: pin-map freeze, watchdog policy, safe-mode entry/exit behavior

## Layout

- `design/`: architecture and design notes
- `kicad/`: PCB design source files
- `bringup/`: bring-up plans and bench notes
- `releases/`: fabrication and release artifacts
