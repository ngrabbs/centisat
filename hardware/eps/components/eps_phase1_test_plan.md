
# 🧪 Test Plan: EPS Subsystem Evaluation (Phase 1)

## 🔋 1. LTC4162 Eval Board (MPPT Charger)

**Objective**:
- Evaluate solar-powered Li-ion charging using 2S2P pack
- Understand MPPT operation and I²C telemetry
- Validate CC/CV charging profile and battery voltage behavior

**Steps**:
1. Connect 2S2P battery pack to BAT terminals
2. Connect 3S solar panel array to VIN
3. Observe MPPT behavior under different light levels
4. Use I²C USB adapter to log:
   - Battery voltage/current
   - Charge status
   - Input power
5. Disconnect solar input and observe PowerPath behavior
6. Simulate cold or hot battery with NTC thermistor

**Measurements**:
- VIN, VBAT, ICHARGE
- MPPT tracking behavior over time
- Charging time to full under ~500mA

**What to Learn**:
- How MPPT adapts to lighting
- How CC/CV transitions occur
- How telemetry reports system health

---

## ⚙️ 2. TPSM5D1806 Eval Board (Dual Buck Regulator)

**Objective**:
- Generate 5V and 3.3V regulated rails from battery or solar power
- Validate load regulation and thermal performance

**Steps**:
1. Connect input VIN to either:
   - Battery output (8.4V max)
   - LTC4162 output
2. Connect outputs to dummy load:
   - CH1: 5V, set dummy load to 1A, 2A, 3A
   - CH2: 3.3V, set dummy load to 0.5A, 1A
3. Monitor output voltage and thermal response
4. Measure efficiency at each current step

**Measurements**:
- VIN, VOUT1, VOUT2, IIN, IOUT, Temp
- Ripple under dynamic loads
- Efficiency % at 1A, 2A, 3A

**What to Learn**:
- How voltage holds under load
- How frequency affects ripple/thermal
- Whether current demands match design expectations

---

## ☀️ 3. SM141K10TF Solar Panels

**Objective**:
- Validate panel voltage/current under various lighting
- Determine best 3S configuration for LTC4162 input

**Steps**:
1. Measure VOC and VMP of a single cell in full sunlight
2. Wire 3 in series and measure open circuit & loaded voltage
3. Apply load (resistive or electronic) and plot I-V curve
4. Connect to LTC4162 input and observe startup behavior

**Measurements**:
- VOC, ISC, VMP, IMP
- Solar-to-battery power transfer during charging

**What to Learn**:
- Real-world panel performance
- Best orientation and wiring configuration
- How partial shading affects output

---

## 🧪 4. Adjustable Constant Current Dummy Load

**Objective**:
- Validate load regulation of buck converter and charger
- Simulate CubeSat subsystems like radios or cameras

**Steps**:
1. Connect load to:
   - 5V rail from TPSM5D1806
   - 3.3V rail
   - Directly to battery output (carefully!)
2. Sweep from 100 mA to 3A
3. Monitor voltage ripple, thermal output, efficiency
4. Test response to sudden load changes (on/off toggle)

**Measurements**:
- V, I, P = V × I
- Ripple under dynamic load
- Voltage droop or overshoot

**What to Learn**:
- How robust your regulators are
- How stable your power rails are under CubeSat-like loads
