# STK and Orbit Analysis

This file tracks exploratory D2C/NTN payload analysis. It is not the baseline
communications architecture for the current senior design build.

## Orbit Modeling (Shared Foundation)
- [ ] Define initial TLE or orbital parameters (LEO, sun-synchronous preferred)
- [ ] Set up the mission satellite object in STK
- [ ] Configure attitude (nadir pointing or passive tumble)

## D2C/NTN Payload Modeling (Exploratory)
- [ ] Add sensor volume for LTE modem concept (e.g., 60 degree cone)
- [ ] Create synthetic network objects for candidate providers:
  - AST SpaceMobile
  - Lynk Global
  - Starlink D2C (speculative)
- [ ] Define representative transmit patterns (beams or hemisphere)
- [ ] Approximate LTE band behavior in antenna/access model

## Contact Window Prediction
- [ ] Generate access reports between the mission satellite and NTN objects
- [ ] Log contact duration, look angles, and revisit times
- [ ] Correlate predicted contact with modem scan schedule assumptions

## Visualization and Outputs
- [ ] Plot expected vs actual contact timelines
- [ ] Overlay GPS coverage vs LTE detections
- [ ] Produce global heatmap of detections by orbital position
- [ ] Archive contact stats summary and STK scenario file (.vdf)
