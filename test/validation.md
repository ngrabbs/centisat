# CeNTiSat Testing & Validation Plan

## 🔌 Subsystem Bench Testing
- [ ] Power rail voltage/current draw validation
- [ ] Solar + battery charge curve testing
- [ ] Thermal dissipation and heat sink checks
- [ ] Battery overcharge and undervoltage protections

## 📶 Modem Behavior Testing
- [ ] AT command set script coverage
- [ ] Simulate D2C lock: rooftop LTE tests with limited visibility
- [ ] Simulated GSM jammers to test fallback logic
- [ ] GPS performance in weak signal conditions

## 📻 UHF Beacon Testing
- [ ] Verify radio works with external SDR
- [ ] Confirm message structure and timing
- [ ] Confirm demodulated messages match onboard logs

## 🧊 Environmental Testing (As Available)
- [ ] Thermal cycling chamber
- [ ] Vacuum chamber or bell jar test
- [ ] Vibration or shake test (DIY or lab partner)

## 🧪 Integration Testing
- [ ] Full stack test (EPS + OBC + Modem + Radio)
- [ ] Burn-in test: 24+ hour operation in enclosure
- [ ] Simulated eclipse/power-loss cycles
- [ ] Final launch configuration test (separation, boot logic, safe mode)

## 🛠 Debug & Telemetry Tools
- [ ] Serial interface tools for log inspection
- [ ] RF sniffing tools (RTL-SDR, SDRplay)
- [ ] Log parser for CSV/JSON comparison vs. ground truth

