# CeNTiSat Software & Firmware

## 🧠 Firmware Framework
- [ ] Choose MCU OS: Baremetal, FreeRTOS, or Arduino-style loop
- [ ] Setup watchdog timer and recovery flow
- [ ] Design boot state machine (Safe mode / Nominal / High-duty)

## 📡 LTE Modem Functions
- [ ] Power on/off via GPIO control
- [ ] AT command parser (TinyGSM or custom)
- [ ] Periodic scan + log (RSSI, cell ID, MCC/MNC, band)
- [ ] Attempt registration (log success/fail/time)
- [ ] If registered, attempt minimal HTTP POST or SMS beacon

## 🛰️ GPS Interface
- [ ] Poll GPS from modem
- [ ] Validate NMEA string parsing or AT GPS reports
- [ ] Log time, location, SNR if available

## 📻 UHF Beacon Functions
- [ ] Implement fallback beacon (AX.25/LoRa/FSK)
- [ ] Transmit time-stamped log snippets periodically
- [ ] Tune beacon interval based on power budget

## 💾 Logging and Storage
- [ ] Define CSV or JSON schema for onboard logs
- [ ] Write to SD/eMMC with log rotation
- [ ] Include time, GPS, modem output, signal metrics
- [ ] Protect log integrity (e.g., write flush / power loss handling)

## 🧪 Ground Test Tools
- [ ] Serial CLI for manual testing (modem, GPS, power)
- [ ] Logging playback tool
- [ ] Minimal WebSocket or Flask tool for ground telemetry decoding

