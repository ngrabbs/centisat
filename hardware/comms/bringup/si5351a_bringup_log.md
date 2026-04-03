# Si5351A Bring-Up Log

## Date: 2026-04-03

## Summary
Si5351A clock generator successfully brought up on Adafruit STEMMA QT breakout
board with Raspberry Pi Pico 2. Both clock outputs verified at correct
frequencies. One register configuration bug found and fixed during bring-up.

## Hardware
- **Board:** Adafruit Si5351A Clock Generator STEMMA QT breakout
- **Controller:** Raspberry Pi Pico 2 (RP2350)
- **Test instruments:** TinySA (spectrum analyzer), oscilloscope
- **Connections:** I2C on GP4/GP5, powered from Pico 3V3

## Results

### CLK1 (RX LO — SMA output)
- **Frequency:** 145.913 MHz (within expected tolerance of 145.900 MHz)
- **Power:** -6.1 dBm at TinySA input (through SMA cable)
- **Enable/disable:** Working, peak appears and disappears on command

### CLK0 (TX carrier — header pin)
- **Frequency:** 145.667 MHz (confirmed via frequency stepping)
- **Radiated level:** -30.6 dBm on TinySA (coupling through board, not conducted)
- **Frequency stepping:** +/- 100 kHz steps track correctly
- Scope verification of CLK0 header pin: not yet tested with corrected firmware

## Bug Found and Fixed

### Symptom
Si5351A initialized without I2C errors. PLLs were running (weak radiated
energy visible on TinySA that tracked frequency changes). But no signal on
CLK0 or CLK1 output pins — oscilloscope showed flat line, TinySA showed only
very weak radiated emissions (-71 to -94 dBm).

### Root Cause
Clock control registers (reg 16, 17) bits 3:2 select the clock source for
the output pin:
- `00` = XTAL passthrough (25 MHz crystal)
- `01` = CLKIN
- `11` = Multisynth divider output

The driver was not setting bits 3:2, leaving them at the default `00` (XTAL).
The PLLs and multisynth dividers were configured and running correctly, but
their outputs were never routed to the output pins.

### Fix
Added `SI5351_CLK_SRC_MS` (0x0C, bits 3:2 = 11) to the clock control register
writes in `si5351a.c`. This routes the multisynth divider output to the pins.

```c
// Before (broken): reg value = 0x43 / 0x63
SI5351_CLK_SRC_PLLA | SI5351_CLK_INT_MODE | SI5351_CLK_DRV_8MA

// After (working): reg value = 0x4F / 0x6F
SI5351_CLK_SRC_PLLA | SI5351_CLK_INT_MODE | SI5351_CLK_SRC_MS | SI5351_CLK_DRV_8MA
```

### Lesson
Always check the output source mux bits when writing Si5351 clock control
registers. AN619 documents these as CLK_SRC[1:0] in the register description.
Many example drivers online include this implicitly but don't call it out.

## Files
- Driver: `firmware/comms/drivers/si5351a.c`, `si5351a.h`
- Test app: `firmware/comms/drivers/si5351a_bringup.c`
- Build: `firmware/comms/drivers/CMakeLists.txt`
