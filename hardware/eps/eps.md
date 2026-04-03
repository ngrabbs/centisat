# CeNTiSat Hardware: Electrical Power System (EPS)

## 🔋 Battery Subsystem
- [x] Select flight-rated cells (LG MJ1 18650, 2s2p)
- [ ] Add PTC or polyfuse overcurrent protection
- [ ] Implement balancing or ensure matched cells
- [ ] Design/validate battery pack mechanical mounting
- [ ] Monitor battery voltage and temperature via MCU ADC

## ☀️ Solar Panel Subsystem
- [x] Select solar panels (SM141K10TF)
- [ ] Validate max current/voltage output per panel face
- [ ] Plan for solar wiring + connector routing
- [ ] Test panel performance under various lighting angles
- [ ] Simulate orbital charging scenario using STK/EPS model

## ⚡ Power Regulation & Charging
- [x] Evaluate TPSM5D1806 step-down module
- [x] Evaluate LTC4162 for charge control
- [ ] Breadboard charging + regulation flow
- [ ] Test MPPT mode (if supported) or static Vref logic
- [ ] Add input protection (TVS diode, clamping, etc.)
- [ ] Design and test enable/disable logic for charging path

## 📐 EPS PCB Design
- [ ] Include all regulation, switching, battery interface
- [ ] Add telemetry: battery volt, charge state, current draw
- [ ] Add safety disconnect logic / pyrofuse (optional)
- [ ] Verify power-on-reset behavior
- [ ] Add test points and debug headers
- [ ] Finalize PCB layout, order from JLCPCB/PCBWay

