# Modular CubeSat Senior Design Repository
### Modular CubeSat Platform for Communications and Systems Research

## Overview

This is a team-built CubeSat-class spacecraft project focused on designing,
building, and validating a modular satellite architecture.

This repository contains shared project artifacts across four primary subsystems:

- Electrical Power System (EPS)
- Flight Controller  
- Communications Board (VHF/UHF)  
- Payload Module  

The project emphasizes practical hardware development, RF communications design,
and system-level integration.

### Current Role Focus

The overall mission is team-owned, but this repo currently has the deepest
implementation focus in communications hardware. The communications subsystem
work supports the author's senior design focus area: satellite TX/RX design,
RF link performance, and bench validation.

See `docs/architecture/project_scope.md` for baseline vs exploratory scope.

---

## Objectives

- Develop a functional modular CubeSat stack across multiple PCBs
- Design and implement a discrete amateur satellite communications chain
- Validate RF performance through measurement (spectrum, filtering, link behavior)
- Establish a reproducible architecture for future research and expansion

---

## Repository Structure

- `hardware/` — PCB designs, schematics, and fabrication assets  
- `firmware/` — Embedded software for each subsystem  
- `rf/` — RF design, simulations, and measured results  
- `analysis/` — Orbit modeling, link analysis, and trade studies  
- `system/` — Interfaces and subsystem integration  
- `test/` — Validation procedures and test results  
- `docs/` — Supporting documentation and design references  

### Canonical Layout

```plaintext
analysis/
  orbit/
    stk/
    matlab/
    results/
  link_budget/
  power/
  trade_studies/

test/
  hardware/
  rf/
  integration/
  environmental/
  validation.md

system/
  interfaces/
  protocols/
  integration/

rf/
  filters/
  matching/
  gain_stages/
  simulations/
  measurements/

firmware/
  comms/
    tx/
    rx/
    encoding/
    drivers/
  flight_controller/
  payload/
  common/

hardware/
  eps/{design,kicad,components,bringup,releases}
  flight_controller/{design,kicad,bringup,releases}
  comms/{design,kicad,bom,bringup,releases}
  payload/{design,kicad,bringup,releases}
  pci104/{template,proto}
  pv_panel/{design,kicad,manufacturing,releases}
  CAD/

docs/
  architecture/
  comms/
  hardware/
  firmware/
  research/
  reports/
```

---

## Communications System (In Progress)

The communications board is a discrete RF design using a conventional amateur
satellite split:

- UHF downlink TX: ~437 MHz (70 cm), BPSK/DBPSK telemetry path
- VHF uplink RX: ~145.9 MHz (2 m), command receiver path

Current architecture includes:

- Si5351A-based frequency generation
- RP2040 control and baseband processing
- BPSK modulation (planned DBPSK with encoding)
- MMIC-based gain stages
- Discrete band-pass filtering

Development is iterative, with emphasis on measurable RF performance and clean spectral output.

See `hardware/comms/design/overview.md` for detailed architecture and design rationale.

---

## Analysis and Simulation

The repository includes early-stage modeling and analysis used to guide system design:

- Orbital simulations and access analysis
- Link geometry and crossing studies
- Power and system-level trade studies

Some D2C/NTN modem work is intentionally retained as exploratory payload research.
It is not the current senior-design baseline communications architecture.

These artifacts are retained to support traceability from requirements to implementation.

---

## Status

This project is under active development. Hardware, firmware, and RF subsystems are being developed and validated incrementally.

---

## Future Work

- Complete communications board bring-up and on-air testing
- Implement encoding and error correction for telemetry
- Integrate subsystem interfaces and system-level testing
- Evaluate optional NTN/D2C payload path as a follow-on effort

---

## License

See `LICENSE` for details.

---
