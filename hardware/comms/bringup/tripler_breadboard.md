# Frequency Tripler Breadboard Build

## Objective
Verify 3rd harmonic generation: 145.667 MHz in → 437 MHz out, using a 2N3904
in class-C configuration. This test skips the XOR modulator (not yet available)
and drives the tripler directly from the Si5351A CLK0 output.

## Schematic

```
Si5351A CLK0                     Vcc (3.3V from Pico)
(145.667 MHz)                     |
     |                          RFC (220 nH)
     |                            |
     +──[100nF]──┬────────────── Collector ──[100nF]──→ SMA → TinySA
                 |                |
              10kΩ              (2N3904)
              to GND              |
                 |              Emitter
                 +────────────── GND
                Base
```

Simplified for clarity:
- Input coupling cap: 100 nF (DC blocks, passes RF)
- Base bias: 10 kΩ to GND (sets class-C — transistor off at DC, conducts on
  positive peaks only)
- Collector: RFC to Vcc, AC-coupled output through 100 nF
- Emitter: directly to GND

## 2N3904 Pinout (TO-92, flat side facing you)

```
   ┌───┐
   │   │
  E  B  C
```
Left = Emitter, Center = Base, Right = Collector.
**Verify with your datasheet** — some manufacturers swap E/C.

## Parts List

| Part | Value | Notes |
|------|-------|-------|
| Q1 | 2N3904 | NPN, TO-92. ft = 300 MHz |
| C1 (input coupling) | 100 nF | Ceramic. Blocks DC from Si5351 output |
| C2 (output coupling) | 100 nF | Ceramic. Blocks DC from collector bias |
| R1 (base bias) | 10 kΩ | Sets class-C operating point. Start here, adjust later |
| L1 (RFC) | 220 nH | RF choke — blocks RF from entering power supply |
| Power | 3.3V | From Pico 3V3 pin, or separate 3.3V supply |

### What's an RFC?

RFC = Radio Frequency Choke. It's just an inductor used to block RF signals
from reaching the DC power supply. At 145 MHz, 220 nH presents ~200 Ohms of
impedance (Z = 2 * pi * f * L), so RF "sees" a wall and goes out the output
cap instead. DC current flows through it freely to bias the collector.

If you don't have a 220 nH inductor specifically, anything in the 100-330 nH
range will work for this test. Even a small ferrite bead might do in a pinch.
What matters is that it has high impedance at 145 MHz and low impedance at DC.

### What if I don't have 100 nF caps?

Any value from 10 nF to 1 uF works fine. These are just DC blocking caps —
at 145 MHz even 1 nF has < 2 Ohms impedance. Use whatever ceramic caps you
have handy.

## Build Procedure

### Step 1 — Check your parts

Verify you have: 2N3904, 10 kΩ resistor, two capacitors (~100 nF), an
inductor (~220 nH), and a way to get CLK0 from the Si5351A to the breadboard.

For CLK0 connection: the Adafruit breakout has header pins for CLK0. Use a
short jumper wire (< 2 inches / 50 mm) from the CLK0 header pin to the
breadboard. Shorter is better at VHF — every inch of wire is an antenna.

### Step 2 — Build the circuit

On the RF proto board or breadboard:

1. Place the 2N3904. Identify E, B, C pins.
2. Connect Emitter to ground.
3. Connect 10 kΩ from Base to ground.
4. Connect input coupling cap (100 nF) from Si5351A CLK0 to Base.
5. Connect RFC (220 nH) from Vcc to Collector.
6. Connect output coupling cap (100 nF) from Collector to your output SMA /
   test point.
7. Add a bypass cap (100 nF) from Vcc to GND close to the RFC — keeps RF out
   of the power supply.

### Step 3 — Power up and measure

1. Power up the Pico + Si5351A (from the previous bring-up test).
2. Confirm CLK0 is running at 145.667 MHz (`s` in serial console).
3. Connect TinySA to the tripler output (through SMA cable or probe).
4. Set TinySA span: **100 MHz to 800 MHz** to see the full harmonic spectrum.

### Step 4 — What to look for

You should see peaks at:

| Harmonic | Frequency | Expected relative level | Notes |
|----------|-----------|------------------------|-------|
| 1st (fundamental) | 145.67 MHz | Strongest | This is what we want to filter out |
| 2nd | 291.3 MHz | -6 to -10 dB below fundamental | Even harmonic, lower in class-C |
| **3rd** | **437.0 MHz** | **-10 to -20 dB below fundamental** | **This is our target** |
| 4th | 582.7 MHz | Weak | Will be filtered |
| 5th | 728.3 MHz | Very weak | Will be filtered |

With a 2N3904 (ft = 300 MHz), the 3rd harmonic will be weaker than with a
higher-ft transistor. Expect roughly **-15 to -10 dBm** at 437 MHz if
input is +10 dBm. This is fine — the MMIC amplifier adds 15-20 dB later.

If you see NO 3rd harmonic:
- Check that the collector has DC voltage (should be near Vcc through the RFC)
- Check that the base is getting signal (probe with scope)
- Try reducing R1 to 4.7 kΩ — this increases conduction angle which may help
  if the Si5351A output swing isn't enough to turn on the transistor cleanly

### Step 5 — Optimize bias

The 10 kΩ base resistor sets the class-C bias point. Tuning it trades off
between total output power and harmonic content:

- **Higher R (22 kΩ, 47 kΩ):** Deeper class-C. Transistor barely conducts →
  more harmonics relative to fundamental, but less total power.
- **Lower R (4.7 kΩ, 2.2 kΩ):** Shallower class-C, approaching class-B.
  More total power but more fundamental, less 3rd harmonic relative to total.
- **Goal:** Maximize the absolute power at 437 MHz. Not the ratio — the
  absolute level.

Try a few values and record the 437 MHz power level on TinySA:

| R1 value | 145.67 MHz | 291.3 MHz | 437.0 MHz | Notes |
|----------|------------|-----------|-----------|-------|
| 4.7 kΩ   |            |           |           |       |
| 10 kΩ    |            |           |           |       |
| 22 kΩ    |            |           |           |       |
| 47 kΩ    |            |           |           |       |

### Step 6 — Frequency sweep test

Use the serial console `+`/`-` commands to shift CLK0 and verify the 3rd
harmonic tracks: a 100 kHz step at 145.67 MHz should produce a 300 kHz step
at 437 MHz. This confirms you're looking at a real 3rd harmonic and not a spur.

### Step 7 — Document results

Record in this file or a separate log:
- TinySA screenshots (if possible)
- Power levels at each harmonic for your best bias point
- Which R1 value gave the best 437 MHz output
- Any unexpected spurs or behavior

## What Comes After This

Once you have a 437 MHz signal:
1. **BPF** — Add a 437 MHz bandpass filter to clean up the harmonics
2. **MMIC** — SPF5189Z amplifier to boost the signal to +5 to +15 dBm
3. **Modulator** — 74LVC1G86 XOR gate between Si5351A and tripler for BPSK

## Notes on Breadboard vs RF Proto Board

A standard breadboard will work for this test — the frequencies are VHF/UHF
but the signal levels are low and we're just looking for "does the harmonic
exist." For the BPF tuning step later, you'll want the RF proto boards with
proper ground plane. For this tripler test, just keep wires short.
