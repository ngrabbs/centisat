# CeNTiSat - Cellular Non-Terrestrial Investigation Satellite

> A focused CubeSat mission to explore the feasibility and performance of direct-to-cell (D2C) satellite communication using commercial LTE modems in low Earth orbit.

---

## 🚀 Mission Overview

**CeNTiSat** is a 1U CubeSat designed to perform a 30-day on-orbit study of cellular network signals available in space, particularly from direct-to-cell satellite providers (e.g., AST SpaceMobile, Lynk, Starlink D2C). It utilizes a commercial LTE modem as a passive and active signal sensor to scan, log, and attempt connections to visible cell networks.

In addition to D2C experimentation, the satellite will provide fallback telemetry via UHF downlink for data recovery and status tracking.

---

## 🎯 Objectives

* Detect and log LTE/4G/5G signals in orbit using a SIM7600-class modem
* Attempt network registration and minimal data uplink
* Correlate cellular signal visibility with orbit, time, and orientation
* Downlink data via a low-rate UHF beacon
* Provide a minimal, reproducible framework for future D2C CubeSat experiments

---

## 📊 System Architecture

* **Platform**: 1U CubeSat, EnduroSat mechanical spec
* **Power**: 2s2p LG MJ1 18650 battery pack, SM141K10TF solar panels, custom EPS (LTC4162, TPSM5D1806)
* **OBC**: Microcontroller-based (ESP32 or STM32)
* **Modem**: SIM7600 LTE module (or compatible)
* **GPS**: Integrated with modem
* **UHF Beacon**: Fallback telemetry using LoRa or AX.25
* **Structure**: Custom-milled aluminum, JLCPCB fabrication
* **Software**: Custom firmware, FreeRTOS or lightweight loop, log + transmit stack

---

## 📦 Repository Structure

```
CeNTiSat/
├── hardware/
│   ├── CAD/                 # Onshape / exported mechanical parts
│   ├── EPS/                 # Power system design, datasheets, schematics
│   └── antenna/             # UHF downlink design
├── software/
│   ├── firmware/            # OBC firmware (C/C++/Arduino)
│   ├── ground-station/      # Log parser, CLI, Flask tools
│   └── utils/               # Tools for log replay, packet inspector
├── analysis/
│   ├── stk_modeling.md      # STK scenario design & results
│   ├── link_predictions/    # Scripts, CSVs, plots
│   └── power_budget/        # EPS simulations
├── testing/
│   ├── validation.md        # Test plans and procedures
│   └── logs/                # Bench test output and screenshots
├── docs/
│   └── theory.md            # Theory of ops, modem config, etc.
├── hardware.mm.md           # Markdown mind map of all selected parts
└── README.md                # This file
```

---

## 📊 Key Logs & Outputs

* LTE modem scan results: MCC/MNC, cell ID, RSSI, SINR
* GPS time and location tagging
* UHF beacon log samples
* STK-modeled access windows vs. actual detections
* Thermal and power performance over mission duration

---

## 🧪 Project Status

| Subsystem    | Status                                            |
| ------------ | ------------------------------------------------- |
| Structure    | 🛠 In Progress (Onshape modeling complete)        |
| EPS          | 🔬 Prototyping (breadboarding LTC4162/TPSM5D1806) |
| Firmware     | 🧠 Initial design planned                         |
| UHF Downlink | 🖜 Not yet implemented                            |
| STK Modeling | 📈 Setup in progress                              |
| Ground Tools | ⌨️ CLI & telemetry tools in design                |

---

## 📚 Acknowledgments

* Inspired by the emerging field of NTN (Non-Terrestrial Networks)
* Developed by \[Your University CubeSat Team Name]
* Guidance from academic advisors and industry whitepapers on D2C viability

---

## 📜 License

\[Creative Commons BY-SA]

---

## 📬 Contact

Questions, collaboration inquiries, or launch partnership interest?

Email: `dng127@msstate.edu`
Project Lead: **\[Nick Grabbs]**
