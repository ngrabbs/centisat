---
markmap:
  initialExpandLevel: 4
---
# CubeSat

## Hardware

### Electrical Power System (EPS)

#### Energy Sources

##### Solar Panels
- ⭐ [SM141K10TF](https://www.digikey.com/en/products/detail/anysolar-ltd/SM141K10TF/14311415)
  - Monocrystalline, high-efficiency
  - Vmp ≈ 3.5V/cell
  - Use 3S or 3S2P configuration for ~10.5V input

##### Batteries
- ⭐ 2S2P 18650 Li-ion
  - LG MJ1 3500mAh cells
  - Nominal Voltage: 7.2V
  - Capacity: ~7000 mAh
  - Max current: 20A

##### Battery Holder
- ⭐ 2S2P 18650 battery holder
  - Allows hot swapping and secure mounting

#### Charging Systems

##### ⭐ LTC4162 
- [LTC4162EUFD-LADM#PBF](https://www.digikey.com/en/products/detail/analog-devices-inc/LTC4162EUFD-LADM-PBF/9446107)
- [DC2038A-A Eval Board](https://www.digikey.com/en/products/detail/analog-devices-inc/DC2038A-A/9996133?s=N4IgTCBcDaICIGEwAYDMAOAggWkyAugL5A)
- Smart charger with MPPT and I²C telemetry
- Supports 1–4S Li-ion
- Pros:
  - Adaptive MPPT
  - Full I²C telemetry (voltage, current, health)
  - JEITA-compliant thermal regulation
- Cons:
  - Slightly more complex integration
  - Needs MCU for config/monitoring

##### BQ24650
- Standalone Li-ion charger with fixed MPPT
- Pros: Simple, effective for 2S packs
- Cons: Manual MPPT voltage tuning, no telemetry

##### LTC4015
- Multi-chemistry charger with I²C
- Pros: Very configurable, fuel gauge support
- Cons: Higher complexity and cost

##### LT3652
- Analog charger with input voltage regulation (pseudo-MPPT)
- Pros: Simple to use, solar-aware
- Cons: No telemetry, not true MPPT

#### Buck Converters

##### ⭐ TPSM5D1806
- [TPSM5D1806RDBR](https://www.digikey.com/en/products/detail/texas-instruments/TPSM5D1806RDBR/14004345)
- [TPSM5D1806EVM Eval Board](https://www.digikey.com/en/products/detail/texas-instruments/TPSM5D1806EVM/13563013?s=N4IgTCBcDaICoAUDKBZArAEQIwA4AMAbCALoC%2BQA)
- Type: Dual Buck Power Module
- Input Voltage: 4.5V – 15V
- Output Voltage: 0.5V – 5.5V (x2)
- Max Output Current: 6A per rail
- Switching Frequency: 500 kHz – 1.2 MHz
- Integrated Inductor: ✅ Yes
- Efficiency: Up to 95%
- Ideal Use:
  - 7.2V battery input
  - Regulate to 5V and 3.3V
  - Compact, low-noise CubeSat systems

##### LM25116MHX/NOPB
- Type: Buck Controller (not a regulator)
- Input Voltage: 6V – 75V
- Output Voltage: Configurable
- Requires external:
  - Power FETs
  - Inductor
  - Diode (optional)
- Best For:
  - Custom power buses
  - High-power rails
- Notes:
  - More complex, but space-qualified variants exist

##### MP2307
- Type: Synchronous Buck Regulator
- Input Voltage: 4.75V – 23V
- Output Voltage: Adjustable (typically fixed 5V)
- Max Current: 3A
- Efficiency: Good (~90%)
- Common Use: Quick prototype 5V rail from 2S Li-ion

##### LM2596
- Type: Classic Buck Regulator
- Input Voltage: 4V – 40V
- Output Voltage: Adjustable/fixed (3.3V, 5V, 12V)
- Max Current: 3A
- Notes:
  - Older design
  - Large module
  - Moderate efficiency

##### TPS5430
- Type: Buck Regulator
- Input Voltage: 5.5V – 36V
- Output Voltage: Adjustable
- Max Output Current: 3A
- Features:
  - Thermal shutdown
  - Short-circuit protection
- Use Case:
  - Great for 5V rail from 2S battery
  - More compact than LM2596

##### TPS62125
- Type: Buck Regulator
- Input Voltage: 3V – 17V
- Output Voltage: Adjustable
- Max Output Current: 300mA
- Features:
  - Low quiescent current
  - Very small footprint (QFN)
- Ideal Use:
  - Microcontroller logic rail
  - Always-on 3.3V standby rail

##### AP63205
- Type: Buck Regulator
- Input Voltage: 3.8V – 32V
- Output Voltage: Adjustable
- Max Current: 2A
- Efficiency: Very good
- Notes:
  - Modern alternative to LM2596
  - Smaller and better performance

#### Supporting Hardware

##### Battery Management System (BMS)
- ⭐ 2S BMS
  - Protects from over/under voltage
  - Ensures safe charging/discharging
  - Required if LTC4162 isn’t sole safety

##### Thermistor
- ⭐ 10k NTC Thermistor
  - For temperature-based charge regulation (JEITA)
  - Connects to LTC4162

##### I²C USB Adapter
- ⭐ Qwiic USB or FTDI USB-I2C bridge
  - Enables monitoring LTC4162 telemetry via serial
  - Useful for prototyping and dev logging

##### Inline Fuse or Polyfuse
- ⭐ 1–2A fuse on solar input and battery output
  - Prevents damage from shorts or reverse connection

##### Dummy Loads
- ⭐ Adjustable or resistive dummy loads
  - [150W 20A Adjustable Constant Current Electronic Load](https://www.amazon.com/KKnoon-Adjustable-Constant-Electronic-Discharge/dp/B0BZYLSP6V/)
  - Simulate CubeSat power draw
  - Useful for load response testing

#### Development Aids

##### Breadboarding and Prototyping
- ⭐ Perfboard, headers, jumpers
- Multimeter & Oscilloscope (already owned)