# CentiSat  
### Modular CubeSat Platform for Communications and Systems Research

## Overview

CentiSat is a CubeSat-class spacecraft project focused on the design, implementation, and validation of a modular satellite architecture. The system is divided into four primary subsystems:

- Electrical Power System (EPS)  
- Flight Controller  
- Communications Board (VHF/UHF)  
- Payload Module  

The project emphasizes practical hardware development, RF communications design, and system-level integration.

---

## Objectives

- Develop a fully functional CubeSat hardware stack across multiple PCBs  
- Design and implement a discrete VHF communications system (2m band)  
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

---

## Communications System (In Progress)

The communications board is a discrete RF design targeting the 2m amateur band. The current architecture includes:

- Si5351-based frequency generation  
- BPSK modulation (planned DBPSK with encoding)  
- MMIC-based gain stages  
- Discrete band-pass filtering  

Development is iterative, with emphasis on measurable RF performance and clean spectral output.

---

## Analysis and Simulation

The repository includes early-stage modeling and analysis used to guide system design:

- Orbital simulations and access analysis  
- Link geometry and crossing studies (MATLAB)  
- Power and system-level trade studies  

These artifacts are retained to support traceability from requirements to implementation.

---

## Status

This project is under active development. Hardware, firmware, and RF subsystems are being developed and validated incrementally.

---

## Future Work

- Complete communications board bring-up and on-air testing  
- Implement encoding and error correction for telemetry  
- Integrate subsystem interfaces and system-level testing  
- Expand payload capabilities  

---

## License

See `LICENSE` for details.

---
