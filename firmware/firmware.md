# Software and Firmware Roadmap

## Baseline Senior Design Track (Primary)

### Communications Board Firmware (RP2040)
- [ ] Configure Si5351A outputs for TX and RX operation
- [ ] Implement TX path control (idle, beacon, packet transmit)
- [ ] Implement bitstream handling for BPSK/DBPSK framing path
- [ ] Implement RX sampling and command packet decode flow
- [ ] Add half-duplex TX/RX state control and fault recovery

### System Firmware Framework
- [ ] Decide runtime approach: bare metal or FreeRTOS
- [ ] Add watchdog timer and recovery flow
- [ ] Define boot state machine (safe mode, nominal, high-duty)
- [ ] Define board health telemetry schema and logging interface

### Ground and Bring-Up Tooling
- [ ] Serial CLI for comms board bring-up and diagnostics
- [ ] RF test helper scripts for repeatable bench procedures
- [ ] Ground decode utility for captured telemetry frames

## Exploratory Payload Track (Optional, Not Baseline)

### D2C/NTN Modem Experiments
- [ ] Power modem on/off via GPIO-controlled rail
- [ ] Implement AT command parser (TinyGSM or custom)
- [ ] Log RSSI, cell ID, MCC/MNC, and band scan results
- [ ] Attempt registration and record success/failure timing
- [ ] Evaluate minimal uplink event (HTTP POST or SMS beacon)

### GPS via Modem (Exploratory)
- [ ] Poll GPS from modem
- [ ] Validate NMEA or AT GPS report parsing
- [ ] Log time/location fields for later coverage analysis
