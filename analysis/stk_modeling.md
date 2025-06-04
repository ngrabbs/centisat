# CeNTiSat D2C Analysis & STK Modeling

## �� CeNTiSat Orbit Modeling
- [ ] Define initial TLE or orbital parameters (LEO, sun-synch preferred)
- [ ] Set up CeNTiSat as a satellite object in STK
- [ ] Configure attitude (e.g., nadir pointing or passive tumble)
- [ ] Add sensor volume for LTE modem (e.g., 60° cone)

## 📡 D2C Network Modeling
- [ ] Create synthetic satellites representing:
  - AST SpaceMobile
  - Lynk Global
  - Starlink D2C (speculative, if needed)
- [ ] Define representative transmit patterns (e.g., beams or full hemisphere)
- [ ] Approximate LTE frequency bands in antenna model

## 🕓 Contact Window Prediction
- [ ] Generate access reports between CeNTiSat and D2C sats
- [ ] Log contact durations, angles, and revisit times
- [ ] Correlate expected contact with modem scan schedule

## 📊 Visualization
- [ ] Plot expected vs. actual contact timelines
- [ ] Overlay GPS coverage vs. LTE detections
- [ ] Produce global heatmap of signal detections (by orbit position)

## 🧾 Outputs for Mission Report
- [ ] Contact stats summary
- [ ] Sample power/signal graphs over time
- [ ] STK scenario file (.vdf) for archiving

