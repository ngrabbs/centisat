# Altium Schematic Instructions — EPS Board

## Design Summary

This EPS board implements a solar-charged, battery-buffered power system for a
2S2P Li-Ion CubeSat stack. The architecture is:

```
Solar (4x face PCBs, 4S SM141K10TF each)
  ├─ X+ ──→ Schottky D1 ──┐
  ├─ X- ──→ Schottky D2 ──┤
  ├─ Y+ ──→ Schottky D3 ──┤  SOLAR_BUS (~18V Vmp)
  └─ Y- ──→ Schottky D4 ──┘
                           │
                    Impedance comp network
                    (2.5 Ohm + 150uF)
                           │
                    ┌──────┴──────┐
                    │  LTC4162-L  │
                    │  LADM (2S)  │
                    │  MPPT ON    │
                    └──────┬──────┘
                           │
                    VOUT (PowerPath, up to ~18V when solar present)
                    VBAT (Battery Bus, 6.0–8.4V)
                           │
                    VOUT_PP feeds both buck regulators
                           │
              ┌────────────┼────────────┐
              │            │            │
        ┌─────┴─────┐  ┌── ┴──────┐ ┌───┴──┐
        │ TPS62933F │  │TPS62933F │ │ I2C  │
        │   3.3V    │  │   5.0V   │ │to FC │
        │  500 kHz  │  │  500 kHz │ └──┬───┘
        └─────┬─────┘  └────┬─────┘    │
              │             │          │
          3V3_RAIL       5V_RAIL    SCL/SDA
              │             │          │
              └─────────────┴──────────┘
                     To PCI-104 stack
```

Key design decision: both buck regulators are fed directly from VOUT_PP
(LTC4162 PowerPath output, 6–18V), not from VBAT. The TPS62933F's
3.8–30 V input range covers the full PowerPath swing — including the
~18 V peak when the solar input is at MPPT — so the PowerPath topology
is preserved end-to-end. This avoids the round-trip efficiency loss
that would come from forcing the load through the battery, and removes
the need for a separate 5 V LDO entirely.

---

## Altium Project Setup

1. Create a new PCB project: `EPS_Board.PrjPcb`
2. Add three schematic sheets:
   - `Solar_Charger.SchDoc`
   - `Regulation.SchDoc`
   - `Connectors_Telemetry.SchDoc`
3. Each sheet uses A3 landscape format (gives more room than A4)
4. Set the project's designator scope to "Flat" so R1, C1, etc. are unique
   across all sheets

### Net Name Convention

Use these global net names consistently across all sheets. Use **power port
symbols** (not net labels) for supply rails so they are global automatically.

| Net Name | Type | Description |
|---|---|---|
| `SOLAR_BUS` | Net label | Solar input after blocking diodes |
| `VIN_CHG` | Net label | LTC4162 VIN pin, after impedance network |
| `VOUT_PP` | Net label | LTC4162 PowerPath output (pins 27, 28) |
| `VBAT` | Power port | Battery+ bus, feeds regulators |
| `+3V3` | Power port | 3.3V regulated rail (global) |
| `+5V` | Power port | 5.0V regulated rail (global) |
| `GND` | Power port | Ground (global) |
| `I2C_SCL` | Net label | I2C clock to flight controller |
| `I2C_SDA` | Net label | I2C data to flight controller |
| `INTVCC` | Net label | LTC4162 internal 5V LDO output |
| `VCC2P5` | Net label | LTC4162 internal 2.5V LDO output |
| `DVCC` | Net label | LTC4162 I2C logic supply |
| `SW_NODE` | Net label | LTC4162 inductor switch node |
| `SMBALERT_N` | Net label | LTC4162 alert output (only discrete health signal) |

---

## Sheet 1: Solar Input & Charger

This sheet contains the solar input interface, blocking diodes, impedance
compensation, and the complete LTC4162-L application circuit.

### Section A: Solar Input (Top-Left of Sheet)

#### Text Frame (Place > Text Frame, top of this section):

> SOLAR INPUT — 4 face PCBs (X+, X-, Y+, Y-), each with 4x SM141K10TF
> in series (~18.4V Vmp, ~23.6V Voc, ~41mA Imp per face). Faces are
> paralleled through blocking diodes on this board. Realistic orbit
> current: 40–80mA depending on attitude. Bench supply can simulate
> any condition through any single JST connector.

#### Components

**J1–J4: Solar Face Connectors (4x JST-PH 2-pin, B2B-PH-K-S or equivalent)**

Search Manufacturer Part Search for "JST PH 2-pin" or "B2B-PH-K-S".
Place four of them in a vertical column.

| Connector | Label | Pin 1 | Pin 2 |
|---|---|---|---|
| J1 | SOLAR_XP | `SOLAR_XP+` | `GND` |
| J2 | SOLAR_XN | `SOLAR_XN+` | `GND` |
| J3 | SOLAR_YP | `SOLAR_YP+` | `GND` |
| J4 | SOLAR_YN | `SOLAR_YN+` | `GND` |

**D1–D4: Blocking Schottky Diodes (4x)**

Use a Schottky rated >= 30V, >= 500mA in SOD-123 or SMA package.
Suggested: SS14 (1A/40V SMA) or B5819W (1A/40V SOD-123).
Pick from JLCPCB basic parts stock.

| Diode | Anode | Cathode |
|---|---|---|
| D1 | `SOLAR_XP+` | `SOLAR_BUS` |
| D2 | `SOLAR_XN+` | `SOLAR_BUS` |
| D3 | `SOLAR_YP+` | `SOLAR_BUS` |
| D4 | `SOLAR_YN+` | `SOLAR_BUS` |

All four cathodes connect to the common `SOLAR_BUS` net.

#### Note (Place > Note, next to the diodes):

> Blocking diodes prevent shadowed/unlit face PCBs from sinking current
> from illuminated faces. Forward drop ~0.3V at 50mA. For bench testing,
> connect bench supply to any single JST connector — the diode on that
> input conducts and the other three are reverse-biased.

---

### Section B: Input Impedance Compensation (Center-Left)

This network is required by the LTC4162 for solar panel MPPT stability.
Without it, the high-impedance constant-current region of the solar panel
can cause the MPPT control loop to oscillate. See LTC4162-L datasheet
Figure 8 and the discussion on pages 33–34.

#### Components

| Ref | Value | Package | Connection | Purpose |
|---|---|---|---|---|
| R1 | 2.5 Ohm, 1%, 1/4W | 0805 | Series: `SOLAR_BUS` → `VIN_CHG` | Impedance flattening |
| C1 | 150uF, 25V, Al-polymer | Radial or SMD | `SOLAR_BUS` to `GND` | Impedance comp, parallel with panel |
| C2 | 0.1uF, 50V, X7R ceramic | 0402 or 0603 | `VIN_CHG` to `GND` | HF bypass at LTC4162 VIN |

#### Circuit

```
SOLAR_BUS ──→ R1 (2.5 Ohm) ──→ VIN_CHG ──→ to LTC4162 VIN (pin 7)
                │                     │
               C1 (150uF)           C2 (0.1uF)
                │                     │
               GND                   GND
```

#### Note (Place > Note, next to R1/C1):

> Solar panel impedance compensation per LTC4162-L datasheet Fig. 8.
> 2.5 Ohm + 150uF maintains ~2.5 Ohm real impedance in the 1–10kHz band
> where the MPPT loop operates. Required for panels with high dynamic
> impedance in the constant-current region. The 150uF should be solid
> polymer or aluminum-polymer (not wet electrolytic) for stable ESR
> over temperature. Panasonic ZA hybrid series recommended.

---

### Section C: LTC4162-L and Power Path (Center of Sheet)

This is the main charger IC with its external MOSFETs, inductor, and
sense resistors.

#### LTC4162-L Symbol

Search Manufacturer Part Search for "LTC4162EUFD" or place from the
downloaded symbol in `hardware/eps/components/LTC4162/`. The IC is a
28-pin QFN (4mm x 5mm) with exposed pad (AGND, pin 29).

Place the LTC4162-L symbol in the center of the sheet with room for
support components on all sides.

#### Pin-by-Pin Connections

**Input Power Path (Top-Left of IC):**

| Pin | Name | Connect To | Notes |
|---|---|---|---|
| 7 | VIN | `VIN_CHG` (from impedance network) | 0.1uF ceramic C2 already at this node |
| 6 | INFET | MN1 gate | Input MOSFET gate drive |
| 5 | CLP | R_SNSI high side | Input current sense + |
| 4 | CLN | R_SNSI low side → `VOUTA_INT` | Input current sense - |
| 3 | VOUTA | `VOUTA_INT`, 0.1uF to GND | Analog supply output |

**Input MOSFET MN1 (FDMC8327L, N-channel):**

```
VIN_CHG ──→ MN1 drain
             MN1 gate ← INFET (pin 6)
             MN1 source ──→ CLP (pin 5)
                             │
                         R_SNSI (10m Ohm, 0805)
                             │
                            CLN (pin 4) ──→ VOUTA (pin 3)
```

| Ref | Value | Package | Connection |
|---|---|---|---|
| MN1 | FDMC8327L | WDFN-8 (5x3.3mm) | Drain=`VIN_CHG`, Gate=INFET(pin6), Source=`CLP_NODE` |
| RS1 | 10m Ohm, 1%, 1/2W | 0805 (Kelvin) | Between CLP (pin 5) and CLN (pin 4) |

#### Note (Place > Note, next to MN1 and RS1):

> MN1: Input reverse-blocking MOSFET. LTC4162 drives gate via INFET
> charge pump. FDMC8327L selected per DC2038A reference design.
> RS1: Input current sense. I_IN(MAX) = 32mV / 10mOhm = 3.2A.
> Sized for bench supply flexibility — actual solar panels deliver
> only ~80mA. Use Kelvin connection (4-pad footprint preferred,
> sense traces from inner pads to CLP/CLN pins). See LTC4162-L
> datasheet Figure 5.

**Switching Regulator (Right Side of IC):**

| Pin | Name | Connect To | Notes |
|---|---|---|---|
| 27, 28 | VOUT | `VOUT_PP`, 10uF ceramic to GND | PowerPath output node |
| 25, 26 | SW | `SW_NODE`, through L1 to CSP | Switch node |
| 1 | BOOST | 22nF ceramic to `SW_NODE` | Bootstrap for high-side gate |

```
VOUT (pins 27,28)  ──┬── C_VOUT (10uF, 25V, X5R) ── GND
                     │
                     └── to MN2 drain (battery MOSFET)

SW (pins 25,26) ── L1 (4.7uH) ── CSP (pin 21)

BOOST (pin 1) ── C_BST (22nF, 10V, X7R) ── SW_NODE
```

| Ref | Value | Package | Connection |
|---|---|---|---|
| C3 | 10uF, 25V, X5R ceramic | 0805 or 1206 | `VOUT_PP` to `GND` |
| L1 | 4.7uH, >4.2A sat | Shielded power inductor | `SW_NODE` to `CSP_NODE` |
| C4 | 22nF, 10V, X7R ceramic | 0402 | `BOOST` (pin 1) to `SW_NODE` |

#### Note (Place > Note, next to L1):

> L1 = 4.7uH per LTC4162-L solar application (datasheet p.49).
> L = 0.3 x VIN(MAX) / fOSC = 0.3 x 23.6 / 1.5 = 4.7uH.
> Saturation current >= 1.3 x 3.2A = 4.2A. Ferrite core required
> for low core loss at 1.5MHz. Coilcraft XAL5030-472MEC or equivalent.

**Battery Path (Right Side of IC):**

| Pin | Name | Connect To | Notes |
|---|---|---|---|
| 22 | BATFET | MN2 gate | Battery MOSFET gate drive |
| 21 | CSP | R_SNSB high side (from L1) | Charge current sense + |
| 20 | CSN | R_SNSB low side → `VBAT` | Charge current sense - |
| 19 | BATSENS+ | `VBAT` (Kelvin sense) | Battery voltage sense, 10uF ceramic |

**Battery MOSFET MN2 (FDMC8327L, N-channel):**

```
VOUT_PP ──→ MN2 drain
             MN2 gate ← BATFET (pin 22)
             MN2 source ──→ VBAT
```

**Charge Current Sense:**

```
L1 output ──→ CSP (pin 21)
               │
           RS2 (10m Ohm, 0805, Kelvin)
               │
              CSN (pin 20) ──→ VBAT
```

| Ref | Value | Package | Connection |
|---|---|---|---|
| MN2 | FDMC8327L | WDFN-8 (5x3.3mm) | Drain=`VOUT_PP`, Gate=BATFET(pin22), Source=`VBAT` |
| RS2 | 10m Ohm, 1%, 1/2W | 0805 (Kelvin) | Between CSP (pin 21) and CSN (pin 20) |
| C5 | 10uF, 10V, X5R ceramic | 0805 | `VBAT` (BATSENS+ side) to `GND` |

#### Note (Place > Note, next to MN2 and RS2):

> MN2: Battery reverse-blocking MOSFET. Prevents battery back-feeding
> the input when VIN is absent. FDMC8327L per DC2038A reference.
> RS2: Charge current sense. I_CHG(MAX) = 32mV / 10mOhm = 3.2A.
> With solar panels, actual charge current is panel-limited (~80mA).
> 10mOhm keeps headroom for bench supply testing at full 3.2A.
> BATSENS+ (pin 19) must Kelvin-sense to battery+ terminal, separate
> from the current-carrying inductor path.

**Internal Regulators and Oscillator (Bottom of IC):**

| Pin | Name | Connect To | Notes |
|---|---|---|---|
| 2 | INTVCC | `INTVCC`, 4.7uF to GND | Internal 5V LDO, >= 6.3V rated cap |
| 8 | VCC2P5 | `VCC2P5`, 1uF to GND | Internal 2.5V LDO, >= 4V rated cap |
| 11 | RT | 63.4k resistor to GND | Sets fOSC = 1.5MHz |
| 16 | SYNC | `GND` | No external sync, tie to ground |

| Ref | Value | Package | Connection |
|---|---|---|---|
| C6 | 4.7uF, 10V, X5R ceramic | 0805 | `INTVCC` to `GND` |
| C7 | 1uF, 6.3V, X5R ceramic | 0402 | `VCC2P5` to `GND` |
| R2 | 63.4k, 1%, 1/10W | 0603 | RT (pin 11) to `GND` |

#### Note (Place > Note, next to R2):

> R2 = 63.4k sets switching frequency: fOSC = 94 / R_T(kOhm)
> = 94 / 63.4 = 1.48MHz (nominal 1.5MHz). Optimized for efficiency
> and inductor size per LTC4162-L datasheet recommendation.
> Place C6 and C7 as close to pins 2 and 8 as possible — these are
> LDO bypass caps and must return to the analog ground plane.

**Cell Count Configuration (Bottom-Left of IC):**

| Pin | Name | Connect To | Notes |
|---|---|---|---|
| 17 | CELLS0 | `VCC2P5` | 2S Li-Ion config: CELLS0 = VCC2P5 |
| 18 | CELLS1 | `INTVCC` | 2S Li-Ion config: CELLS1 = INTVCC |

These are direct wire connections (no resistors needed). The pin strapping
sets the cell count to 2 cells per the LTC4162-L datasheet Table 5.

#### Note (Place > Note, next to CELLS0/CELLS1):

> Cell count = 2S Li-Ion: CELLS1 = INTVCC, CELLS0 = VCC2P5.
> Matches DC2038A demo board jumper configuration for 2-cell Li-Ion.
> Full charge voltage = 2 x 4.2V = 8.4V.
> See LTC4162-L datasheet Table 5 (p.48) and DC2038A Table 1 (p.5).

**NTC Thermistor Network (Bottom-Right of IC):**

| Pin | Name | Connect To | Notes |
|---|---|---|---|
| 9 | NTCBIAS | Through R_NTCBIAS to NTC pin | Thermistor bias output (1.2V) |
| 10 | NTC | Thermistor junction | Thermistor voltage sense input |

```
NTCBIAS (pin 9) ── R3 (10k)  ──┬── NTC (pin 10)
                               │
                           R_NTC (10k NTC thermistor)
                               │
                              GND
```

| Ref | Value | Package | Connection |
|---|---|---|---|
| R3 | 10k, 1%, low TC | 0402 | NTCBIAS (pin 9) to NTC node |
| RT1 | 10k NTC, B=3490K | 0402 | NTC node to `GND` |

Suggested thermistor: Vishay NTCS0402E3103FHT (10k, beta=3950K, 0402).
This is the same part used on the DC2038A demo board.

#### Note (Place > Note, next to thermistor network):

> NTC thermistor senses battery temperature for JEITA charge safety.
> LTC4162 applies 1.2V to NTCBIAS and reads the voltage divider on NTC.
> R3 = R_NTCBIAS = 10k matches the thermistor nominal value at 25C.
> For higher accuracy over 0–60C, add R_SERIES = 549 Ohm in series
> with the thermistor and R_PARALLEL = 187k across it (see LTC4162-L
> datasheet p.29, Figure 3). For prototype bring-up without a real
> thermistor attached, place a 10k fixed resistor in the RT1 position
> to simulate 25C and allow charging.

**I2C and Alert (Bottom of IC):**

| Pin | Name | Connect To | Notes |
|---|---|---|---|
| 15 | DVCC | `DVCC`, connected to `INTVCC` | I2C logic level reference |
| 13 | SCL | `I2C_SCL`, 10k pullup to `DVCC` | I2C clock (open-drain) |
| 14 | SDA | `I2C_SDA`, 10k pullup to `DVCC` | I2C data (open-drain) |
| 12 | SMBALERT | `SMBALERT_N`, 10k pullup to `DVCC` | Alert output (open-drain) |

| Ref | Value | Package | Connection |
|---|---|---|---|
| R4 | 10k | 0402 | `I2C_SCL` to `DVCC` (pullup) |
| R5 | 10k | 0402 | `I2C_SDA` to `DVCC` (pullup) |
| R6 | 10k | 0402 | `SMBALERT_N` to `DVCC` (pullup) |

Connect DVCC (pin 15) directly to INTVCC with a short trace. The datasheet
requires DVCC to be the same supply as the I2C pull-up resistors.

#### Note (Place > Note, next to I2C pullups):

> I2C address: 0x68 (7-bit). Up to 400kHz (Fast Mode).
> DVCC = INTVCC (~5V) sets I2C logic levels. The flight controller
> must be 5V-tolerant on I2C or use a level shifter. If FC runs at
> 3.3V I2C, either: (a) connect DVCC to 3.3V instead of INTVCC
> (works per datasheet if DVCC >= 2.667V), or (b) add a bidirectional
> I2C level shifter. Decision TBD during integration — for now, wire
> DVCC to INTVCC and note the open item.

**Ground Pins:**

| Pin | Name | Connect To | Notes |
|---|---|---|---|
| 23, 24 | PGND | `GND` | Power ground, connect to copper pour |
| 29 (exposed pad) | AGND | `GND` | Analog ground, thermal pad, MUST be soldered |

AGND (exposed pad) must connect to PGND at a single point on the PCB.
On the schematic, connect both to the `GND` power port.

---

### Section D: VOUT and VBAT Port Exits (Right Edge of Sheet)

Place **sheet entry ports** (or off-sheet connectors) on the right edge:

| Port Name | Direction | Net | Goes To |
|---|---|---|---|
| `VBAT` | Output | `VBAT` | Sheet 3 (battery connector, test point) |
| `VOUT_PP` | Output | `VOUT_PP` | Sheet 2 (regulator input) and Sheet 3 (test point) |
| `I2C_SCL` | Bidirectional | `I2C_SCL` | Sheet 3 (PCI-104 connector) |
| `I2C_SDA` | Bidirectional | `I2C_SDA` | Sheet 3 (PCI-104 connector) |
| `SMBALERT_N` | Output | `SMBALERT_N` | Sheet 3 (PCI-104 connector) |
| `GND` | Passive | `GND` | Global power port (auto-connects) |

---

### Sheet 1 Schematic Layout Suggestion

```
┌────────────────────────────────────────────────────────────────────────┐
│  [Text Frame: Solar Input Description]                                 │
│                                                                        │
│  J1 ──D1──┐                                                            │
│  J2 ──D2──┤                   ┌──────────────┐                         │
│  J3 ──D3──┼── SOLAR_BUS ─R1─  │  LTC4162-L   │ ── VOUT_PP ──→ port     │
│  J4 ──D4──┘    │              │              │                         │
│               C1(150u)        │   VIN  VOUT  │ ── MN2 ── VBAT → port   │
│                │              │   INFET SW   │    │                    │
│               GND    C2(0.1u) │   CLP  CSP   │   RS2  C5(10u)          │
│                       │       │   CLN  CSN   │    │      │             │
│                      GND      │   VOUTA BST  │   VBAT   GND            │
│                               │              │                         │
│              MN1(FDMC8327L)   │  CELLS0/1    │                         │
│              RS1(10mOhm)      │  INTVCC VCC  │   RT1(NTC)              │
│                               │  RT   SYNC   │   R3(10k)               │
│                               │  DVCC SCL    │   R4,R5,R6 pullups      │
│                               │  SDA  SMBA   │                         │
│                               │  PGND  AGND  │                         │
│                               └──────────────┘                         │
│                                     │                                  │
│                              L1(4.7uH)  C4(22nF)                       │
│                              R2(63.4k)  C6(4.7u) C7(1u)                │
│                                                                        │
│  [Notes throughout as specified above]                                 │
└────────────────────────────────────────────────────────────────────────┘
```

### Sheet 1 Ports Checklist

- [ ] `VBAT` — battery+ bus, from CSN/BATSENS+ node
- [ ] `VOUT_PP` — PowerPath output, from VOUT pins 27/28
- [ ] `I2C_SCL` — from pin 13 with pullup
- [ ] `I2C_SDA` — from pin 14 with pullup
- [ ] `SMBALERT_N` — from pin 12 with pullup
- [ ] `GND` — power port (global)

---
---

## Sheet 2: Regulation

This sheet takes `VOUT_PP` from the LTC4162 PowerPath output and
produces the two regulated rails using two TPS62933F synchronous buck
converters: 3.3V at up to 3A and 5.0V at up to 3A.

### Text Frame (Place > Text Frame, top of sheet):

> REGULATION — Both rails are produced by TPS62933F 3A synchronous
> buck converters fed from VOUT_PP (LTC4162 PowerPath output, 6–18V).
> The TPS62933F has a 3.8–30V input range, which comfortably accepts
> the full PowerPath swing from battery-only (~6V) to peak solar
> charging (~18V), preserving proper PowerPath topology.
>
> Why TPS62933F (forced CCM variant) over the standard TPS62933:
> - Fixed switching frequency at all loads (no PFM transitions)
> - Predictable EMI spectrum — important since the comms board peer
>   is RF-sensitive at 145 MHz and 437 MHz
> - Lower output ripple under light load
> - Cost: ~30% the price of TPSM5D1806, no LDO needed for 5V rail

---

### Common Notes for Both Buck Stages

Both regulators are identical TPS62933F devices in SOT-583 (8-pin)
packages. Place them side-by-side on the sheet so the layout mirrors
the PCB placement and reviewers can compare the two stages at a glance.
Datasheet references in this section are to TI document SLUSEA4D
(June 2021, revised August 2022).

**Pinout (TPS62933F, SOT-583):**

| Pin | Name | Function |
|---|---|---|
| 1 | RT | Switching frequency program (float = 500 kHz) |
| 2 | EN | Enable, with optional VIN UVLO divider |
| 3 | VIN | Power input (3.8–30 V) |
| 4 | GND | Ground |
| 5 | SW | Switch node, to inductor |
| 6 | BST | Bootstrap cap to SW (100 nF) |
| 7 | SS | Soft-start cap to GND (33 nF) |
| 8 | FB | Feedback, to top of divider |

**Common feedback equation:** R_FBT = ((VOUT − 0.8) / 0.8) × R_FBB,
with R_FBB = 10 kΩ recommended (datasheet Equation 1, §10.2.2.2).

**Common switching frequency choice:** 500 kHz, set by floating the
RT pin (datasheet Table 9-1). Rationale: 500 kHz is the lowest standard
setting and gives the best efficiency, lowest switching losses, and
the cleanest fundamental away from any sensitive baseband bands.
The two converters are not synchronized — the RP2040 GPIOs on the
flight-controller and comms boards filter their own supply locally,
so beat tones between the two buck stages are not a concern.

---

### Section A: TPS62933F — 3.3V Rail (Left Half of Sheet)

#### TPS62933F Symbol — U2 (3.3V Stage)

Search Manufacturer Part Search for "TPS62933F". JLCPCB stocks the
TPS62933FDRLR (SOT-583, tape and reel). Place centrally in the left
half of the sheet.

#### Pin Connections

| Pin | Name | Connect To | Notes |
|---|---|---|---|
| 1 | RT | Leave floating (no connect) | Selects 500 kHz |
| 2 | EN | EN UVLO divider midpoint (R20/R21) | Optional UVLO; see note |
| 3 | VIN | `VOUT_PP` via C30 + C31 | 3.8–30 V input range |
| 4 | GND | `GND` | Connect to thermal pad |
| 5 | SW | L20 (4.7 µH) | Switch node |
| 6 | BST | C32 (100 nF) to SW pin | Bootstrap |
| 7 | SS | C33 (33 nF) to `GND` | ~5 ms soft-start |
| 8 | FB | R23 / R24 divider midpoint | Output sense |

#### Input Capacitors

Per datasheet §10.2.2.9: 10 µF X7R + 100 nF X7R, both placed directly
at VIN/GND with the shortest possible loop. Voltage rating must clear
the maximum VOUT_PP excursion (~18 V) with healthy derating.

| Ref | Value | Package | Connection |
|---|---|---|---|
| C30 | 10 µF, 35 V, X7R ceramic | 1210 | `VOUT_PP` to `GND` |
| C31 | 100 nF, 50 V, X7R ceramic | 0402 | `VOUT_PP` to `GND` |

#### Note (Place > Note, next to C30/C31):

> Input bypass per TPS62933F datasheet §10.2.2.9. C31 (100 nF) MUST
> be placed directly across the VIN and GND pins with the shortest
> possible trace — this is the high-frequency loop and is the single
> most layout-critical component on the buck. C30 (10 µF) is the
> bulk input cap. Both rated 35 V or higher to allow the X7R DC bias
> derating headroom against VOUT_PP peaks of ~18 V.

#### Inductor

Datasheet Table 10-2: 4.7 µH at 500 kHz, 3.3 V output. Saturation
current rating must comfortably exceed peak inductor current. With
K = 0.4 ripple ratio and Iout = 3 A, peak current is approximately
3.6 A; specify a part rated ≥ 5 A saturation.

| Ref | Value | Package | Notes |
|---|---|---|---|
| L20 | 4.7 µH, ≥ 5 A Isat, ≤ 30 mΩ DCR | Shielded SMD (e.g., 5 × 5 mm) | Würth 74438357047 or equivalent |

#### Feedback Divider for 3.3V

```
+3V3 ── R23 (31.6k, 1%) ──┬── FB (pin 8 of U2)
                          │
                       R24 (10k, 1%)
                          │
                         GND
```

Calculation (datasheet §10.2.2.2):
R_FBT = ((3.3 − 0.8) / 0.8) × 10 kΩ = 31.25 kΩ → nearest E96 = **31.6 kΩ**.

Resulting VOUT = 0.8 × (1 + 31.6 / 10) = **3.328 V** (within ±1% target).

| Ref | Value | Package | Notes |
|---|---|---|---|
| R23 | 31.6 kΩ, 1%, 100 ppm/°C | 0603 | Top feedback resistor |
| R24 | 10 kΩ, 1%, 100 ppm/°C | 0603 | Bottom feedback resistor |

#### Note (Place > Note, next to R23/R24):

> Feedback divider for 3.3V rail. Vref = 0.8 V (TPS62933F internal
> bandgap). R_FBT = ((Vout − Vref) / Vref) × R_FBB.
> R_FBB = 10 kΩ is the datasheet recommendation (§10.2.2.2) — lower
> values waste current at light load, higher values become noise-
> susceptible. Place R23/R24 directly at the FB pin with a short trace.

#### Output Capacitors

Datasheet Table 10-2 calls for 40 µF typical effective capacitance at
3.3 V / 500 kHz. Apply ~2× DC-bias derating for X7R 25 V parts at
3.3 V (loss is small, but conservative).

| Ref | Value | Package | Connection |
|---|---|---|---|
| C34 | 22 µF, 25 V, X7R ceramic | 1210 | `+3V3` to `GND` |
| C35 | 22 µF, 25 V, X7R ceramic | 1210 | `+3V3` to `GND` |
| C36 | 100 nF, 16 V, X7R ceramic | 0402 | `+3V3` to `GND` (HF) |

#### Bootstrap and Soft-Start

| Ref | Value | Package | Connection |
|---|---|---|---|
| C32 | 100 nF, 16 V, X5R ceramic | 0402 | BST (pin 6) to SW (pin 5) |
| C33 | 33 nF, 16 V, X7R ceramic | 0402 | SS (pin 7) to `GND` |

#### Note (Place > Note, next to C32/C33):

> C32 is the bootstrap cap — provides gate drive for the high-side FET.
> 100 nF X5R 16 V minimum, placed directly between BST and SW pins
> per datasheet §10.2.2.5. Do NOT substitute X7R 0.1 µF in a different
> package; matching the example design avoids loop-area surprises.
>
> C33 sets soft-start time. tSS = (Css × Vref) / Iss = (33 nF × 0.8 V)
> / 5.5 µA ≈ 4.8 ms. Datasheet §10.2.2.4 minimum is 6.8 nF.
> Soft-start prevents inrush surge into the LTC4162 PowerPath when
> the regulator first enables.

#### EN / VIN UVLO Divider (Optional but Recommended)

The TPS62933F can be enabled by floating EN, but adding an external
UVLO divider per datasheet §9.3.6 / §10.2.2.6 prevents the regulator
from attempting to start (or oscillating in current limit) when
VOUT_PP collapses below a usable level — for example during a deep
battery discharge before the LTC4162 latches off.

Target: VSTART = 5.5 V (rising), VSTOP = 5.0 V (falling). This sits
well below the LTC4162's normal battery operating range and acts as
a hard backstop.

Calculation per datasheet equations 3 and 4 (Ip = 0.7 µA, Ih = 1.4 µA,
Ven_fall = 1.17 V, Ven_rise = 1.21 V):

- R20 (top, VIN to EN) ≈ **226 kΩ** (E96)
- R21 (bottom, EN to GND) ≈ **61.9 kΩ** (E96)

| Ref | Value | Package | Connection |
|---|---|---|---|
| R20 | 226 kΩ, 1% | 0603 | `VOUT_PP` to EN (pin 2) |
| R21 | 61.9 kΩ, 1% | 0603 | EN (pin 2) to `GND` |

#### Note (Place > Note, next to R20/R21):

> EN UVLO divider: VSTART ≈ 5.5 V rising, VSTOP ≈ 5.0 V falling.
> Backstop against deep-discharge oscillation if the LTC4162 LVD ever
> fails to disconnect the load. Calculated per TPS62933F datasheet
> §9.3.6 equations 3 and 4. R20 and R21 are SHARED between U2 and U3
> (single divider, both EN pins tap the same midpoint) — the EN
> hysteresis currents are summed and the resulting threshold shift is
> well within budget for this conservative target.

---

### Section B: TPS62933F — 5V Rail (Right Half of Sheet)

#### TPS62933F Symbol — U3 (5V Stage)

Identical part to U2. Place mirroring U2 on the right half of the
sheet. The 5V rail feeds the comms board RF gain stages (SA612,
ADL5602) and any other 5V housekeeping.

#### Pin Connections

| Pin | Name | Connect To | Notes |
|---|---|---|---|
| 1 | RT | Leave floating | 500 kHz |
| 2 | EN | Same midpoint as U2 (R20/R21 shared) | Common UVLO |
| 3 | VIN | `VOUT_PP` via C40 + C41 | Same input rail as U2 |
| 4 | GND | `GND` | Thermal pad |
| 5 | SW | L21 (6.8 µH) | Switch node |
| 6 | BST | C42 (100 nF) to SW pin | Bootstrap |
| 7 | SS | C43 (33 nF) to `GND` | ~5 ms soft-start |
| 8 | FB | R25 / R26 divider midpoint | Output sense |

#### Input Capacitors

| Ref | Value | Package | Connection |
|---|---|---|---|
| C40 | 10 µF, 35 V, X7R ceramic | 1210 | `VOUT_PP` to `GND` |
| C41 | 100 nF, 50 V, X7R ceramic | 0402 | `VOUT_PP` to `GND` |

#### Inductor

Datasheet Table 10-2: 6.8 µH at 500 kHz, 5 V output. Same ≥ 5 A
saturation requirement.

| Ref | Value | Package | Notes |
|---|---|---|---|
| L21 | 6.8 µH, ≥ 5 A Isat, ≤ 35 mΩ DCR | Shielded SMD | Würth 74439346068 (datasheet reference part) |

#### Feedback Divider for 5V

Calculation: R_FBT = ((5.0 − 0.8) / 0.8) × 10 kΩ = 52.5 kΩ → nearest
E96 = **52.3 kΩ**.

Resulting VOUT = 0.8 × (1 + 52.3 / 10) = **4.984 V** (within ±0.4%).

| Ref | Value | Package | Notes |
|---|---|---|---|
| R25 | 52.3 kΩ, 1%, 100 ppm/°C | 0603 | Top feedback resistor |
| R26 | 10 kΩ, 1%, 100 ppm/°C | 0603 | Bottom feedback resistor |

#### Note (Place > Note, next to R25/R26):

> Feedback divider for 5V rail. Same Vref/equation as the 3.3V stage.
> Datasheet Table 10-2 lists R_top = 52.5 kΩ for this rail; 52.3 kΩ
> (E96) is the closest 1% standard value and gives 4.984 V output.

#### Output Capacitors

Datasheet Table 10-2: 20 µF typical effective at 5 V / 500 kHz.

| Ref | Value | Package | Connection |
|---|---|---|---|
| C44 | 22 µF, 25 V, X7R ceramic | 1210 | `+5V` to `GND` |
| C45 | 22 µF, 25 V, X7R ceramic | 1210 | `+5V` to `GND` |
| C46 | 100 nF, 16 V, X7R ceramic | 0402 | `+5V` to `GND` (HF) |

#### Bootstrap and Soft-Start

| Ref | Value | Package | Connection |
|---|---|---|---|
| C42 | 100 nF, 16 V, X5R ceramic | 0402 | BST (pin 6) to SW (pin 5) |
| C43 | 33 nF, 16 V, X7R ceramic | 0402 | SS (pin 7) to `GND` |

---

### Section C: Output Bulk Bypass and Pi-Filter Option (Bottom of Sheet)

The two 22 µF ceramics on each rail handle the buck-stage transient
response. Add board-level bulk to keep the rail quiet downstream of
the regulator footprint.

| Ref | Value | Package | Connection | Purpose |
|---|---|---|---|---|
| C50 | 10 µF, 16 V, X7R | 0805 | `+3V3` to `GND` | Board-level bulk, 3.3V |
| C51 | 100 nF, 16 V, X7R | 0402 | `+3V3` to `GND` | HF decoupling, 3.3V |
| C52 | 10 µF, 16 V, X7R | 0805 | `+5V` to `GND` | Board-level bulk, 5V |
| C53 | 100 nF, 16 V, X7R | 0402 | `+5V` to `GND` | HF decoupling, 5V |

#### Note (Place > Note, next to C50–C53):

> Board-level bulk bypass at the rail aggregation point. Local
> bypass at each consumer (RP2040, RF stages, etc.) is the
> responsibility of the consuming subsystem. These caps cover the
> board-level transient response and any trace inductance between
> the buck stages and the PCI-104 connector.

---

### Sheet 2 Port Exits (Right Edge)

| Port Name | Direction | Net | Goes To |
|---|---|---|---|
| `+3V3` | Output | `+3V3` | Sheet 3 (PCI-104, LEDs, test points) |
| `+5V` | Output | `+5V` | Sheet 3 (PCI-104, test points) |
| `GND` | Passive | `GND` | Global power port |

Sheet 2 Port Entries (Left Edge):

| Port Name | Direction | Net | Comes From |
|---|---|---|---|
| `VOUT_PP` | Input | `VOUT_PP` | Sheet 1 (LTC4162 PowerPath output) |

> Note on PGOOD: the TPS62933F variant (SS pin) does not provide a
> PGOOD output. If a power-good telemetry signal is required for the
> flight controller, swap one or both stages to TPS62933P (PG pin)
> and route an open-drain PGOOD net to Sheet 3. For the prototype,
> the LTC4162's I2C telemetry already exposes input/charger health
> and is the primary monitoring path.

---

### Sheet 2 Schematic Layout Suggestion

```
┌──────────────────────────────────────────────────────────────────────┐
│  [Text Frame: Regulation Description]                                │
│                                                                      │
│  VOUT_PP (port) ──┬─────────────────────────┬───────────────         │
│                   │                         │                        │
│              C30,C31                    C40,C41                      │
│                   │                         │                        │
│            ┌──────┴──────┐           ┌──────┴──────┐                 │
│            │  TPS62933F  │           │  TPS62933F  │                 │
│            │     U2      │           │     U3      │                 │
│            │  (3.3V)     │           │   (5.0V)    │                 │
│            │             │           │             │                 │
│            │ VIN     SW ─┼─ L20 ─┐   │ VIN     SW ─┼─ L21 ─┐         │
│            │ EN     BST ─┤(C32)  │   │ EN     BST ─┤(C42)  │         │
│            │ RT      FB ─┤       │   │ RT      FB ─┤       │         │
│            │ SS     GND  │       │   │ SS     GND  │       │         │
│            └──┬──┬──┬────┘       │   └──┬──┬──┬────┘       │         │
│               │  │  │            │      │  │  │            │         │
│              C33 R23│           +3V3   C43 R25│           +5V        │
│                   R24            │           R26            │        │
│                                C34-36                    C44-46      │
│                                  │                         │         │
│                                 GND                       GND        │
│                                                                      │
│      EN UVLO divider (shared):  R20 (VOUT_PP→EN), R21 (EN→GND)       │
│                                                                      │
│      Bulk bypass: C50/C51 on +3V3, C52/C53 on +5V                    │
│                                                                      │
│      +3V3 ──→ port            +5V ──→ port                           │
│                                                                      │
│  [Notes throughout as specified above]                               │
└──────────────────────────────────────────────────────────────────────┘
```

### Sheet 2 Ports Checklist

- [ ] `VOUT_PP` — input from Sheet 1 (LTC4162 PowerPath)
- [ ] `+3V3` — output to Sheet 3 / global power port
- [ ] `+5V` — output to Sheet 3 / global power port
- [ ] `GND` — power port (global)

---
---

## Sheet 3: Connectors & Telemetry

This sheet holds the battery connector, PCI-104 stack header, status
LEDs, and test points.

### Text Frame (Place > Text Frame, top of sheet):

> CONNECTORS & TELEMETRY — Battery interface, PCI-104 stack connector
> for inter-board power and signal distribution, status LEDs, and test
> points for bench validation. All subsystem power and I2C telemetry
> routes through the PCI-104 header.

---

### Section A: Battery Connector (Top-Left)

#### Components

| Ref | Description | Package | Connection |
|---|---|---|---|
| J5 | 2-pin JST-PH (battery+, battery-) | B2B-PH-K-S | Pin 1 = `VBAT`, Pin 2 = `GND` |
| J6 | 2-pin header, 2.54mm (bench supply alt) | 1x2 pin header | Pin 1 = `VBAT`, Pin 2 = `GND` |

Provide both a JST for the battery holder and a pin header for bench
supply clip leads. They connect in parallel to the same `VBAT` and `GND`
nets.

#### Note (Place > Note, next to battery connectors):

> Battery: 2S2P LG MJ1 18650 (7000mAh total, 6.0–8.4V).
> J5 (JST): permanent battery holder connection.
> J6 (header): bench supply input for bring-up without battery.
> WARNING: Do not connect bench supply and battery simultaneously
> unless bench supply is set to match battery voltage. The LTC4162
> PowerPath handles source arbitration, but bench supply on VBAT
> bypasses the charger path.

---

### Section B: PCI-104 Stack Connector (Center of Sheet)

#### Connector Selection

**Part: Samtec MMS-130-02-L-DV-A** — 2×30 (60-pin), 2.00mm pitch,
through-hole vertical socket. This is the standard PCI-104 pin socket.

The PCI-104 spec allows two 2×30 connectors (J1 and J2) for 120 total
pins. For the EPS prototype, **populate only one connector (J1)** — 60
pins is more than sufficient for the current signal count (~12 used).
Leave the J2 footprint in the PCB layout unpopulated for future
expansion.

The mating male header on the adjacent board in the stack is the
**Samtec TMM-130-02-L-DV** (2×30 pin header, 2.00mm, vertical).

Search Manufacturer Part Search for "MMS-130-02-L-DV-A" or place a
generic 2×30 pin socket symbol (2.00mm pitch) and assign the Samtec
MPN in the component properties. The footprint should match the KiCad
template: `PinSocket_2x30_P2.00mm_Vertical` (0.8mm drill, 1.35mm pad).

#### Provisional Pin Assignment (EPS-Relevant Subset, J1 Only)

This table defines the EPS-side pins on J1. Pin numbering follows
row-letter-first convention (a1–a30 on one row, b1–b30 on the other)
per the PCI-104 spec. Coordinate with the flight controller and comms
board teams for the complete pin map.

| Pin | Net Name | Direction | Function |
|---|---|---|---|
| a1 | `+3V3` | Power Out | 3.3V regulated rail |
| a2 | `+3V3` | Power Out | 3.3V (parallel for current sharing) |
| a3 | `GND` | Power | Ground return for 3.3V |
| a4 | `+5V` | Power Out | 5.0V regulated rail |
| a5 | `+5V` | Power Out | 5.0V (parallel for current sharing) |
| a6 | `GND` | Power | Ground return for 5V |
| a7 | `VBAT` | Power Out | Unregulated battery bus (6.0–8.4V) |
| a8 | `GND` | Power | Ground return for VBAT |
| a9 | `I2C_SCL` | Bidirectional | EPS telemetry I2C clock |
| a10 | `I2C_SDA` | Bidirectional | EPS telemetry I2C data |
| a11 | `SMBALERT_N` | Output | LTC4162 interrupt/alert |
| a12 | `GND` | Power | Ground (signal reference) |
| a13–a30 | TBD | — | Reserved |
| b1–b30 | TBD | — | Reserved (FC, comms, payload signals) |

Note: power pins are doubled (a1/a2 for 3.3V, a4/a5 for 5V) with
adjacent GND returns. This reduces connector pin resistance and
provides low-impedance current return paths. The remaining ~48 pins
are available for FC SPI, CAN bus, payload signals, and spares.

#### Note (Place > Note, next to PCI-104):

> PCI-104 stack connector: Samtec MMS-130-02-L-DV-A (2×30, 2.00mm,
> through-hole socket). Only J1 populated for prototype; J2 footprint
> reserved for future expansion. Mate with TMM-130-02-L-DV on
> adjacent board. Pin assignment is provisional — full pin map must
> be coordinated across all subsystem boards before PCB layout.
> Single GND plane, star-connected at the connector — no separate
> analog/digital ground returns.

#### Bulk Bypass at Stack Connector

Place bypass caps at the PCI-104 connector for the distributed rails:

| Ref | Value | Package | Connection |
|---|---|---|---|
| C60 | 10uF, 10V, X5R | 0805 | `+3V3` to `GND` at connector |
| C61 | 100nF, 10V, X7R | 0402 | `+3V3` to `GND` at connector |
| C62 | 10uF, 10V, X5R | 0805 | `+5V` to `GND` at connector |
| C63 | 100nF, 16V, X7R | 0402 | `+5V` to `GND` at connector |

---

### Section C: Status LEDs (Bottom-Left)

| Ref | Color | Connection | Indicates |
|---|---|---|---|
| D10 | Green | `+3V3` → R30 (1k) → D10 → `GND` | 3.3V rail active |
| D11 | Green | `+5V` → R31 (1k) → D11 → `GND` | 5.0V rail active |
| D12 | Red | `SMBALERT_N` inverted or via FET | Charger alert active (optional) |

D12 (optional for prototype): SMBALERT is active-low open-drain.
Simplest approach: connect through a PNP inverter or skip for prototype
and read SMBALERT via I2C instead.

Note: the TPS62933F (SS variant) has no PGOOD output, so the only
discrete rail-health LED would have to come from a comparator on the
3.3V or 5V rail. For the prototype, the two "rail active" LEDs above
are sufficient — actual fault diagnostics happen via the LTC4162 I2C
telemetry path.

| Ref | Value | Package |
|---|---|---|
| R30 | 1k | 0402 |
| R31 | 1k | 0402 |
| D10 | Green LED | 0603 |
| D11 | Green LED | 0603 |
| D12 | Yellow LED | 0603 |

#### Note (Place > Note, next to LEDs):

> LED brightness at 3.3V: I = (3.3 - 2.0) / 1k = 1.3mA (dim but visible).
> LED brightness at 5.0V: I = (5.0 - 2.0) / 1k = 3.0mA.
> For brighter LEDs, reduce resistor to 470 Ohm. For flight, remove
> LED population or use DNP (Do Not Populate) — LEDs waste power
> in orbit. Mark all LED resistors as DNP-optional in BOM.

---

### Section D: Test Points (Bottom-Right)

In Altium, place test points as single-pin components. Search Manufacturer
Part Search for "test point" or use a generic 1-pin symbol and assign a
test point pad footprint (e.g., a 1.5mm round pad or Keystone 5019 loop).

#### How to Place Test Points in Altium

1. Place > Part > search "Test Point" in Manufacturer Part Search
2. Or: create a generic 1-pin schematic symbol called "TP"
3. Assign a footprint: use a round pad (1mm–2mm diameter) or a loop
   footprint (Keystone 5000-series)
4. Label each test point with its net name in the Comment field
5. On the PCB, test points appear as pads — probe them with scope/DMM

#### Test Point List

| Ref | Net | Purpose | Measurement |
|---|---|---|---|
| TP1 | `SOLAR_BUS` | Solar bus after diodes | Vpanel under load |
| TP2 | `VIN_CHG` | LTC4162 VIN (after impedance comp) | Charger input voltage |
| TP3 | `VOUT_PP` | PowerPath output | VOUT tracking behavior |
| TP4 | `VBAT` | Battery bus | Battery voltage |
| TP5 | `+3V3` | 3.3V regulated rail | Rail voltage, ripple |
| TP6 | `+5V` | 5.0V regulated rail | Rail voltage, ripple |
| TP7 | `SW_NODE` | LTC4162 switch node | Switching waveform, frequency |
| TP8 | `GND` | Ground reference | Scope ground clip point |

Place TP8 (GND) as a large pad or loop — you always need a convenient
ground reference for scope probing. Consider placing two GND test points
on opposite sides of the board.

#### Note (Place > Note, next to test points):

> All test points are single-pad footprints accessible from the top
> side. TP7 (SW_NODE) is critical for validating switching behavior —
> use a short probe lead to minimize inductance. TP8 (GND) should be
> a loop-style test point for easy scope ground clip attachment.
> For production/flight boards, test points can be reduced to TP4-TP6
> (VBAT, 3V3, 5V) plus GND.

---

### Section E: Sheet 3 Port Entries (Left Edge)

| Port Name | Direction | Net | Comes From |
|---|---|---|---|
| `VBAT` | Input | `VBAT` | Sheet 1 |
| `VOUT_PP` | Input | `VOUT_PP` | Sheet 1 |
| `+3V3` | Input | `+3V3` | Sheet 2 |
| `+5V` | Input | `+5V` | Sheet 2 |
| `I2C_SCL` | Bidirectional | `I2C_SCL` | Sheet 1 |
| `I2C_SDA` | Bidirectional | `I2C_SDA` | Sheet 1 |
| `SMBALERT_N` | Input | `SMBALERT_N` | Sheet 1 |

---

### Sheet 3 Schematic Layout Suggestion

```
┌──────────────────────────────────────────────────────────────────────┐
│  [Text Frame: Connectors & Telemetry Description]                    │
│                                                                      │
│  ┌──────────────────┐        ┌─────────────────────────────┐         │
│  │ Battery          │        │ J1: MMS-130-02-L-DV-A       │         │
│  │                  │        │ PCI-104 (2x30, 2mm, J1 only)│         │
│  │ J5 (JST)    VBAT ├────────┤ a1,a2  +3V3    C60,C61      │         │
│  │ J6 (header) GND  ├────────┤ a3     GND                  │         │
│  │                  │        │ a4,a5  +5V     C62,C63      │         │
│  └──────────────────┘        │ a6     GND                  │         │
│                              │ a7     VBAT                 │         │
│                              │ a8     GND                  │         │
│                              │ a9     I2C_SCL              │         │
│                              │ a10    I2C_SDA              │         │
│                              │ a11    SMBALERT_N           │         │
│                              │ a12    GND                  │         │
│                              │ a13-a30, b1-b30  (reserved) │         │
│                              └─────────────────────────────┘         │
│                              [J2 footprint: DNP for prototype]       │
│                                                                      │
│  ┌─ ─────────────┐          ┌──────────────────────────┐             │
│  │ Status LEDs   │          │ Test Points              │             │
│  │               │          │                          │             │
│  │ D10 3.3V PWR  │          │ TP1 SOLAR_BUS            │             │
│  │ D11 5.0V PWR  │          │ TP2 VIN_CHG              │             │
│  │ D12 ALERT(opt)│          │ TP3 VOUT_PP              │             │
│  │               │          │ TP4 VBAT                 │             │
│  └── ────────────┘          │ TP5 +3V3                 │             │
│                             │ TP6 +5V                  │             │
│                             │ TP7 SW_NODE              │             │
│                             │ TP8 GND (x2)             │             │
│                             └──────────────────────────┘             │
│                                                                      │
│  [Notes throughout as specified above]                               │
└──────────────────────────────────────────────────────────────────────┘
```

### Sheet 3 Ports Checklist

- [ ] `VBAT` — from Sheet 1, to battery connector and TP4
- [ ] `VOUT_PP` — from Sheet 1, to TP3 (also routed to Sheet 2 regulators)
- [ ] `+3V3` — from Sheet 2, to PCI-104, LED, test point
- [ ] `+5V` — from Sheet 2, to PCI-104, LED, test point
- [ ] `I2C_SCL` — from Sheet 1, to PCI-104
- [ ] `I2C_SDA` — from Sheet 1, to PCI-104
- [ ] `SMBALERT_N` — from Sheet 1, to PCI-104 (and optional D12)

---
---

## After All Three Sheets Are Done

### 1. Annotate

Tools > Annotate Schematic Quietly (or Annotate Schematic for manual
control). Assign unique designators across all sheets: R1, R2, ... C1,
C2, ... etc.

### 2. Compile and Validate

Project > Compile PCB Project. Check the Messages panel for:
- **Net mismatch** between sheet entry ports (names must match exactly)
- **Unconnected pins** — add no-connect X markers on any intentionally
  unconnected pins on the LTC4162 or other ICs
- **Duplicate designators** — fix before proceeding
- **Power port direction warnings** — these are usually benign but review

### 3. Fill in Title Blocks

On each sheet, double-click the title block and fill in:

| Field | Sheet 1 | Sheet 2 | Sheet 3 |
|---|---|---|---|
| Title | CubeSat EPS — Solar Input & Charger | CubeSat EPS — Regulation | CubeSat EPS — Connectors & Telemetry |
| Revision | 0.1 | 0.1 | 0.1 |
| Drawn By | Nick Grabbs | Nick Grabbs | Nick Grabbs |
| Date | (today) | (today) | (today) |

### 4. Export PDF

File > Smart PDF (or File > Print > PDF).
Save to `hardware/eps/releases/EPS_schematic_v0.1.pdf` for review.

---

## Complete BOM Summary

### Sheet 1: Solar Input & Charger

| Ref | Value | Description | Qty |
|---|---|---|---|
| J1–J4 | JST-PH 2-pin | Solar face connectors | 4 |
| D1–D4 | SS14 or B5819W | Blocking Schottky diodes, >= 30V/500mA | 4 |
| R1 | 2.5 Ohm, 1%, 1/4W | Impedance comp resistor | 1 |
| C1 | 150uF, 25V, Al-polymer | Impedance comp cap | 1 |
| C2 | 0.1uF, 50V, X7R | VIN HF bypass | 1 |
| U1 | LTC4162EUFD-LADM#PBF | MPPT charger IC, QFN-28 | 1 |
| MN1, MN2 | FDMC8327L | N-ch MOSFET, PowerPath | 2 |
| RS1, RS2 | 10m Ohm, 1%, 1/2W | Current sense resistors | 2 |
| L1 | 4.7uH, >= 4.2A sat | Power inductor (shielded) | 1 |
| C3 | 10uF, 25V, X5R | VOUT bypass | 1 |
| C4 | 22nF, 10V, X7R | BOOST cap | 1 |
| C5 | 10uF, 10V, X5R | BATSENS+ bypass | 1 |
| C6 | 4.7uF, 10V, X5R | INTVCC bypass | 1 |
| C7 | 1uF, 6.3V, X5R | VCC2P5 bypass | 1 |
| R2 | 63.4k, 1% | RT oscillator frequency | 1 |
| R3 | 10k, 1%, low TC | NTC bias resistor | 1 |
| RT1 | 10k NTC, B=3490K | Battery temperature sense | 1 |
| R4, R5, R6 | 10k | I2C/SMBALERT pullups | 3 |

### Sheet 2: Regulation

| Ref | Value | Description | Qty |
|---|---|---|---|
| U2, U3 | TPS62933FDRLR | 3A sync buck, FCCM, SOT-583 | 2 |
| L20 | 4.7 µH, ≥ 5 A Isat | 3.3V power inductor (shielded) | 1 |
| L21 | 6.8 µH, ≥ 5 A Isat | 5V power inductor (Würth 74439346068 ref) | 1 |
| C30, C40 | 10 µF, 35 V, X7R | Buck input bulk caps | 2 |
| C31, C41 | 100 nF, 50 V, X7R | Buck input HF caps (placed at VIN/GND pins) | 2 |
| C32, C42 | 100 nF, 16 V, X5R | Bootstrap caps | 2 |
| C33, C43 | 33 nF, 16 V, X7R | Soft-start caps (~5 ms) | 2 |
| C34, C35 | 22 µF, 25 V, X7R | 3.3V output caps | 2 |
| C36 | 100 nF, 16 V, X7R | 3.3V output HF cap | 1 |
| C44, C45 | 22 µF, 25 V, X7R | 5V output caps | 2 |
| C46 | 100 nF, 16 V, X7R | 5V output HF cap | 1 |
| C50 | 10 µF, 16 V, X7R | 3.3V bulk bypass | 1 |
| C51 | 100 nF, 16 V, X7R | 3.3V HF bypass | 1 |
| C52 | 10 µF, 16 V, X7R | 5V bulk bypass | 1 |
| C53 | 100 nF, 16 V, X7R | 5V HF bypass | 1 |
| R20 | 226 kΩ, 1% | EN UVLO top (shared U2/U3) | 1 |
| R21 | 61.9 kΩ, 1% | EN UVLO bottom (shared U2/U3) | 1 |
| R23 | 31.6 kΩ, 1%, 100 ppm | 3.3V FB top resistor | 1 |
| R24 | 10 kΩ, 1%, 100 ppm | 3.3V FB bottom resistor | 1 |
| R25 | 52.3 kΩ, 1%, 100 ppm | 5V FB top resistor | 1 |
| R26 | 10 kΩ, 1%, 100 ppm | 5V FB bottom resistor | 1 |

### Sheet 3: Connectors & Telemetry

| Ref | Value | Description | Qty |
|---|---|---|---|
| J5 | JST-PH 2-pin | Battery connector | 1 |
| J6 | 1x2 pin header | Bench supply alt connector | 1 |
| J7 (J1) | Samtec MMS-130-02-L-DV-A | PCI-104 2×30 socket, 2.00mm, vertical | 1 |
| D10 | Green LED, 0603 | 3.3V power indicator | 1 |
| D11 | Green LED, 0603 | 5.0V power indicator | 1 |
| D12 | Red LED, 0603 | SMBALERT indicator (optional) | 1 |
| R30, R31 | 1k | LED current limit | 2 |
| C60 | 10uF, 10V, X5R | 3.3V bypass at connector | 1 |
| C61 | 100nF, 10V, X7R | 3.3V HF bypass at connector | 1 |
| C62 | 10uF, 10V, X5R | 5V bypass at connector | 1 |
| C63 | 100nF, 16V, X7R | 5V HF bypass at connector | 1 |
| TP1–TP8 | Test point pads | Probe points | 8 |

---

## Design Notes Summary (For Title Block or Separate Note Sheet)

These are the key design decisions documented in this schematic. Place
a condensed version in the title block "Notes" field or as a text frame
on Sheet 1.

1. **Battery**: 2S2P LG MJ1 18650 Li-Ion, 7.2V nom, 6.0–8.4V range
2. **Charger**: LTC4162-LADM, I2C adjustable voltage, MPPT ON by default
3. **Cell config**: 2S Li-Ion (CELLS1=INTVCC, CELLS0=VCC2P5)
4. **Solar input**: 4x face PCBs (4S SM141K10TF each), paralleled via
   blocking diodes. Vmp ~18.4V, Isc ~52mA per face.
5. **Regulators fed from VOUT_PP** (LTC4162 PowerPath output, 6–18V).
   The TPS62933F's 3.8–30V input range covers the full range, so the
   PowerPath topology is preserved end-to-end (no need to bypass to VBAT).
6. **3.3V**: TPS62933F (forced CCM), 500 kHz, 31.6k/10k feedback,
   4.7 µH inductor, 2× 22 µF X7R output
7. **5.0V**: TPS62933F (forced CCM), 500 kHz, 52.3k/10k feedback,
   6.8 µH inductor, 2× 22 µF X7R output
8. **F variant chosen** (forced CCM, no PFM transitions) for
   predictable EMI spectrum next to the 145 MHz / 437 MHz comms board
9. **Shared EN UVLO divider** on both buck stages: VSTART ≈ 5.5 V,
   VSTOP ≈ 5.0 V — backstop against deep-discharge oscillation
10. **No PGOOD output** — TPS62933F (SS variant) has no PG pin.
    Health monitoring is via LTC4162 I2C telemetry. If a discrete PG
    signal is later required, swap to TPS62933P.
11. **Sense resistors**: 10mOhm for both input and charge — sized for 3.2A
    bench flexibility, actual solar current is ~80mA
12. **I2C level**: DVCC = INTVCC (~5V). FC must be 5V-tolerant or use
    level shifter. Open integration item.

---

## Related Documents

- LTC4162-L datasheet: `hardware/eps/components/LTC4162/LTC4162-L.pdf`
- DC2038A demo manual: `hardware/eps/components/LTC4162/DC2038A.pdf`
- TPS62933F datasheet: TI SLUSEA4D (June 2021, rev August 2022)
- TPSM5D1806 datasheet (deprecated for this design): `hardware/eps/components/TPSM5D1806/tpsm5d1806.pdf`
- EPS architecture: `hardware/eps/design/overview.md`
- EPS interfaces: `hardware/eps/design/interfaces.md`
- Bring-up plan: `hardware/eps/bringup/phase1_validation.md`
- Comms board Altium guide (reference format): `hardware/comms/design/altium_digital_power_sheets.md`
