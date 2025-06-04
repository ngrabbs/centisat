# CeNTiSat: Mission Checklist

## 1. Mission Definition
- [x] Define primary mission objective (D2C signal characterization)
- [x] Select modem module (e.g., SIM7600 or alternative)
- [ ] Define success criteria (e.g., # D2C detections, successful registrations, telemetry downlinked)

## 2. Satellite Structure & Integration
- [x] Choose structure format (1U, EnduroSat standard spacing)
- [x] CAD all mechanical parts in Onshape
- [ ] Confirm clearances and mounting compatibility
- [ ] Select deployment hardware (rails, separation switches, etc.)
- [ ] Plan thermal dissipation strategy

## 3. Electrical Power System (EPS)
- [x] Select solar cells (SM141K10TF)
- [x] Select battery chemistry (LG MJ1, 2s2p, NASA accepted)
- [x] Acquire TPSM5D1806, LTC4162 eval kits
- [ ] Breadboard & test power regulation paths
- [ ] Design custom EPS PCB (charge management, regulation, protections)
- [ ] Simulate power budget for worst-case scenario
- [ ] Validate MPPT or passive regulation logic
- [ ] Design and order flight PCB

## 4. OBC & Comms
- [ ] Select microcontroller/SoC (ESP32 / STM32 / Pi CM4 / etc.)
- [ ] Select modem breakout or embed directly
- [ ] Design GPIO-level interface for power cycling, modem control
- [ ] Add UHF/VHF radio (e.g., low-rate LoRa, AX.25, or COTS)
- [ ] Define message structure & protocol for telemetry

## 5. Software / Firmware
- [ ] OBC firmware framework (RTOS, watchdog, tasks)
- [ ] LTE modem scan + log + transmit logic
- [ ] UHF beacon / fallback telemetry logic
- [ ] GPS parsing and timestamp tagging
- [ ] Onboard storage strategy (e.g., SD card buffer)
- [ ] Bootup state machine and fault recovery
- [ ] Command & telemetry encoding

## 6. Ground Segment
- [ ] Design simple ground station (UHF RX, modem test sim)
- [ ] Build Flask-based or CLI telemetry parser
- [ ] Add C2 commands if bidirectional comms possible
- [ ] Define log format and analytics (JSON/CSV)

## 7. Simulation & Analysis
- [ ] Load CeNTiSat orbit in STK
- [ ] Load TLEs or approximate coverage for AST, Lynk, Starlink D2C sats
- [ ] Predict contact opportunities
- [ ] Simulate signal levels, modem duty cycling strategy
- [ ] Plot expected vs. observed links (for report)

## 8. Environmental Testing
- [ ] Vibe testing (as available)
- [ ] Thermal cycling (passive box, peltier, etc.)
- [ ] Vacuum chamber (if available)
- [ ] Functional tests post-stress

## 9. Documentation & Outreach
- [x] Maintain hardware.mm.md mind map
- [ ] Add theory-of-operations documentation
- [ ] Document all PCB designs (KiCAD, Altium, etc.)
- [ ] Keep mission operations log
- [ ] Prepare final presentation/report or publish to GitHub

## 10. Launch Preparation
- [ ] Build final stack
- [ ] Conduct full integration test
- [ ] Battery safety compliance docs
- [ ] Confirm deployment rail compatibility
- [ ] Burn image + final firmware + ground station tooling
- [ ] Submit for rideshare / deployment booking

