# **Jetson Orin Nano Developer Kit Carrier Board**

Specification

### Document History

### SP-11324-001\_v1.3

| Version | Date              | Description of Change                                                                                                                         |
|---------|-------------------|-----------------------------------------------------------------------------------------------------------------------------------------------|
| 1.0     | March 20, 2023    | Initial release                                                                                                                               |
| 1.1     | May 17, 2023      | ><br>Updated Note in Chapter 1: Introduction with VDD_IN<br>related information.                                                              |
|         |                   | ><br>Updated Pin #13 in Table 2-5: DisplayPort Connector Pin<br>Description – J8.                                                             |
|         |                   | ><br>Updated Pin #55 and Pin #57 in Table 2-6: M.2 Key E<br>Expansion Slot Pin Description – J10.                                             |
|         |                   | ><br>Added developer kit weight.                                                                                                              |
|         |                   | ><br>Updated Figure 5-1: Power Diagram.                                                                                                       |
|         |                   | ><br>Updated VDD_5V_SYS in Table 5-2: Interface Supply<br>Current Capabilities.                                                               |
|         |                   | ><br>Updated Table 5-3: Supply Current Capabilities per<br>Connector per Supply; replaced VDD_IN with<br>VDD_5V_SYS.                          |
| 1.2     | April 12, 2024    | ><br>Updated Figure 1-4. Jetson Orin Nano Carrier Board<br>Placement – Top View: corrected Pin 1 location on J20 and<br>J21 camera connectors |
| 1.3     | December 20. 2024 | ><br>Introduction: updated note - Orin NX 40W (MAXN_SUPER)<br>is NOT supported on the developer kit carrier board.                            |
|         |                   | ><br>Jetson Orin Nano Module Feature List: updated Memory<br>to reflect MAXN_SUPER performance                                                |
|         |                   | ><br>CAN Bus Header: corrected typo; reference to a 2.45 mm<br>pitch header (J17) was corrected to say 2.54 mm pitch<br>header (J17)          |

### **Table of Contents**

| Chapter 1 | . Introduction                                     | I  |
|-----------|----------------------------------------------------|----|
| 1.1       | Jetson Orin Nano Module Feature List               | 2  |
| 1.2       | Carrier Board Feature List                         | 2  |
| 1.3       | Jetson Orin Nano Carrier Board Block Diagram       | 3  |
| Chapter 2 | . Jetson Nano Carrier Board Standard Connectors    | 7  |
| 2.1       | USB Ports                                          | 7  |
| 2.2       | Gigabit Ethernet                                   | 10 |
| 2.3       | DisplayPort                                        | 11 |
| 2.4       | M.2 Key E Expansion Slot                           | 12 |
| 2.5       | M.2 Key M Expansion Slot                           | 14 |
| Chapter 3 | . Carrier Board Custom Expansion IF Connections    | 18 |
| 3.1       | Jetson Orin Nano Module Connector                  | 18 |
| 3.2       | Camera Connector                                   | 18 |
| 3.3       | 40-Pin Expansion Header                            | 21 |
| 3.4       | Button Header                                      | 24 |
| 3.5       | Optional CAN Bus Header                            | 25 |
| 3.6       | Fan Connector                                      | 25 |
| 3.7       | Optional Battery Back-up Coin Cell Holder          | 26 |
| 3.8       | DC Power Jack                                      | 26 |
| 3.9       | Optional Power-Over Ethernet and Backpower Headers | 27 |
| Chapter 4 | . Mechanical Specification                         | 29 |
| Chapter 5 | . Interface Power                                  | 31 |

### List of Figures

| Figure 1-1.    | Jetson Orin Nano Block Diagram                                | 4 |
|----------------|---------------------------------------------------------------|---|
| Figure 1-2.    | Jetson Orin Nano –<br>Top View (Envelope)                     | 4 |
| Figure 1-3.    | Jetson Orin Nano –<br>Bottom View (Envelope)                  | 5 |
| Figure 1-4.    | Jetson Orin Nano Carrier Board Placement –<br>Top View<br>    | 5 |
| Figure 1-5.    | Jetson Orin Nano Carrier Board Placement –<br>Bottom View     | 6 |
| Figure 3-1.    | Expansion Header Connections<br>21                            |   |
| Figure 3-2.    | Jack Connector26                                              |   |
| Figure 3-3.    | PoE Alternative Power Input27                                 |   |
| Figure 4-1.    | Developer Kit Carrier Board Mechanical Dimensions29           |   |
| Figure 4-2.    | Developer Kit Mechanical Dimensions<br>30                     |   |
| Figure 5-1.    | Power Diagram31                                               |   |
| List of Tables |                                                               |   |
| Table 2-1.     | USB 3.2 Type C Connector Pin Description –<br>J5              | 7 |
| Table 2-2.     | USB 3.2 Type A Connector Pin Descriptions –<br>J6             | 8 |
| Table 2-3.     | USB 3.2 Type A Connector Pin Description –<br>J7              | 9 |
| Table 2-4.     | Ethernet RJ45 Connector Pin Description –<br>J1510            |   |
| Table 2-5.     | DisplayPort Connector Pin Description –<br>J8<br>11           |   |
| Table 2-6.     | M.2 Key E Expansion Slot Pin Description –<br>J1012           |   |
| Table 2-7.     | M.2 Key M Expansion Slot Pin Description –<br>J11 (x4 PCIe)14 |   |
| Table 2-8.     | M.2 Key M Expansion Slot Pin Description –<br>J24 (x2 PCIe)16 |   |
| Table 3-1.     | Camera #0 Connector Pin Description –<br>J2019                |   |
| Table 3-2.     | Camera #1 Connector Pin Description –<br>J2120                |   |
| Table 3-3.     | Expansion Header Pin Description –<br>J1222                   |   |
| Table 3-4.     | Button Header Description –<br>J14<br>24                      |   |
| Table 3-5.     | Optional CAN Header Pin Description –<br>J17<br>25            |   |
| Table 3-6.     | Fan Connector Pin Description –<br>J1325                      |   |
| Table 3-7.     | RTC Backup Batter Connector Pin Description –<br>J326         |   |
| Table 3-8.     | DC Jack Pin Description –<br>J1627                            |   |
| Table 3-9.     | PoE Header –<br>J19<br>27                                     |   |
| Table 3-10.    | PoE Backpower Header –<br>J1828                               |   |
| Table 5-1.     | Interface Power Supply Allocation32                           |   |
| Table 5-2.     | Interface Supply Current Capabilities32                       |   |
| Table 5-3.     | Supply Current Capabilities per Connector per Supply<br>33    |   |

## <span id="page-4-0"></span>**Chapter 1. Introduction**

This specification contains recommendations and guidelines for engineers to follow to create modules for the expansion connectors on the NVIDIA® Jetson Orin™ Nano carrier board. As well as understand the capabilities of the other dedicated interface connectors and associated power solutions on the platform.

The Jetson Orin Nano carrier board is ideal for software development within the Linux environment. Standard connectors are used to access Jetson Orin Nano features and interfaces, enabling a highly flexible and extensible development platform. Go to <https://developer.nvidia.com/embedded/develop> or r contact your NVIDIA representative for access to software updates and the developer SDK supporting the OS image and host development platform that you want to use. The developer SDK includes an OS image that you will load onto your Jetson Orin Nano device, supporting documentation, and code samples to help you get started.

The Jetson Orin Nano carrier board supports all the Jetson Orin Nano Series and Jetson Orin NX Series modules.

[Figure: A warning symbol with an exclamation mark inside a circle.]

**Caution:** ALWAYS CONNECT JETSON ORIN NANO and ALL EXTERNAL PERIPHERAL DEVICES BEFORE CONNECTING THE POWER SUPPLY TO THE AC POWER JACK. Connecting a device while powered on may damage the developer kit carrier board, Jetson Orin Nano, or peripheral device. In addition, the carrier board should be powered down and the power removed before plugging or unplugging devices or add-on modules into the headers. Wait for the red power VDD\_IN LED to turn off or wait for 5 minutes if your system does not have a power LED. This includes the Jetson Orin Nano module, the camera connector, the M.2 connector, and the other expansion headers.

The Jetson Orin Nano developer board contains ESD-sensitive parts. Always use appropriate anti-static and grounding techniques when working with the system. Failure to do so can result in ESD discharge to sensitive pins, and irreparably damage your Jetson Orin Nano board. NVIDIA will not replace units that have been damaged due to ESD discharge.

**Note:** The developer kit carrier board has been modified to only support 5V to the module. The MODULE\_ID signal is not pulled up on the carrier board. This means that regardless of the capability of the module, VDD\_IN will be 5V only. Custom carrier boards can still be designed to support 5V and 19V and use the MODULE\_ID to identify a 5V vs. 19V Input. Orin NX 40W (MAXN\_SUPER) is NOT supported on the developer kit carrier board.

# <span id="page-5-0"></span>1.1 Jetson Orin Nano Module Feature List

The following is a list of features for the Jetson Orin Nano module.

- > Applications processor (AP)
  - NVIDIA Orin™
- > Memory
  - 8 GB 128-bit wide LPDDR5 DRAM (up to 68 GB/s; 102GB/s MAXN\_SUPER)
  - Micro SD card socket (UHS-1)
- > Networking
  - 10/100/1000 BASE-T Ethernet
- > Advanced power management (APM)
- > Dynamic voltage and frequency scaling
- <span id="page-5-1"></span>> Multiple clock and power domains

## 1.2 Carrier Board Feature List

The following is a list of features for the carrier board.

- > Connection to Jetson Orin Nano
  - 260-pin SO-DIMM connector
- > USB
  - USBC: Supports Recovery Mode
  - USB 3.2 (Gen2x1) Hub to 4x Type A (host only)
- > Wired network
  - Gigabit Ethernet (RJ45 connector with LEDs and optional PoE header)
- > Display
  - VESA® DisplayPort™ (DP v1.2 (+MST) and eDP v1.4)
- > Camera connectors
  - 2x 22-position flex connectors
  - CSI (2.5 Gbps per pair): 1, x2 or x4 and 1, x2
  - Camera CLK, I2C, and control
- > M.2 Key E connector
  - PCIe (Gen3) x1 Lane, USB 2.0
  - I2S, UART, I2C
  - Control

- > M.2 Key M connector (x2)
  - #1) PCIe (Gen3) x4 lane, control
  - #2) PCIe (Gen3) x2 lane, control
- > Expansion header
  - 40-pin (2x20) header
  - I2C (x2), SPI (x2), UART
  - I2S, audio clock, GPIOs, PWMs
- > UI and indicators
  - Button header: Power, reset, force recovery, debug UART, Auto-Power-On disable
  - LEDs: Power
- > Miscellaneous
  - Fan connector: 5V, PWM, and tach
  - Optional RTC back-up connector
  - Optional CAN header
- > Power
  - DC Jack: 9-20 V (19V supply provided)
  - Optional Ethernet PoE and back power headers
  - Main 5.0 V Pre-regulator: GS9230 (or A0Z2264)
    - Provides VDD\_IN to module
  - Main 3.3V supply: GS9230 (or A0Z2264)
  - Main 1.8V supply: GS7116S5
  - 3.3V AO (always on) supply: GS7116S5
  - USB VBUS load switches: AP22811AW5-7 (x2)
  - DP 3.3V power switch: APL3552ABI-TRG
- <span id="page-6-0"></span>> Developer kit operating temperature range
  - 0⁰C to 35⁰C

# 1.3 Jetson Orin Nano Carrier Board Block Diagram

[Figure 1-1](#page-7-0) through [Figure 1-5](#page-9-0) show the block diagram and various placement views for Jetson Orin Nano and the carrier board.

[Figure: A block diagram of the Jetson Orin Nano carrier board's internal components and connections.]

<span id="page-7-0"></span>Figure 1-1. Jetson Orin Nano Block Diagram

<span id="page-7-1"></span><span id="page-8-1"></span>Image /page/8/Picture/1 description: A gray box with a gray line running through it, containing a gray line with a circle at each end.

Figure 1-3. Jetson Orin Nano - Bottom View (Envelope)

<span id="page-8-0"></span>Figure 1-4. Jetson Orin Nano Carrier Board Placement - Top View

[Figure: A technical diagram of a Jetson Orin Nano carrier board placement, providing a detailed view of the board's layout and component placement.]

[J10] M.2, Key E Socket [J11] M.2, Key M Socket (4-lane) [J24] M.2, Key M Socket (2-lane) [J3] Optional RTC Battery Connector **J3** Optional: RTC Back-up Coin Cell Socket (CR1225) **J11** M.2 Key M Slot (75-pin)

<span id="page-9-0"></span>Figure 1-5. Jetson Orin Nano Carrier Board Placement – Bottom View

- **J10** M.2 Key E Connectivity Slot (75-pin) **J24** M.2 Key M Slot (75-pin)

# <span id="page-10-0"></span>**Chapter 2. Jetson Nano Carrier Board Standard Connectors**

The Jetson Orin Nano carrier board provides several connectors with industry standard pinouts to support additional functionality beyond what is integrated on the main platform board. This includes:

- > USB 3.2: Type C connector
- > USB 3.2: 2 x Type A stacked connectors
- > Gigabit Ethernet: RJ45 connector
- > DisplayPort connector
- > M.2, Key E socket
- > M.2, Key M socket (4-lane PCIe)
- <span id="page-10-1"></span>> M.2, Key M socket (2-lane PCIe)

## 2.1 USB Ports

The carrier board supports five USB connectors. One is a USB 3.2 Type C connector (J5) supporting host, device, and USB Recovery. In addition, there are two, dual stacked USB 3.2 Type A connectors (J6 and J7). Each connector supports host mode only. A load switch supplying VBUS is provided for each of the USB 3.2 ports per stack and is limited to 3A of output current.

<span id="page-10-2"></span>Table 2-1. USB 3.2 Type C Connector Pin Description – J5

| Pin # | Connector Pin<br>Name | Associated Module Pin<br>Name (See Note 1 and 2) | Module<br>Pin # | Usage/Description          | Type/Dir |
|-------|-----------------------|--------------------------------------------------|-----------------|----------------------------|----------|
| A1    | GND_A                 | –                                                | –               | Ground                     | Ground   |
| A2    | TX1_P                 | USBSS1_TX_P                                      | G23             | USB 3.2 #1 Transmit 1 from |          |
| A3    | TX1_N                 | USBSS1_TX_N                                      | G22             | mux                        | Output   |
| A4    | –                     | –                                                | –               | USB VBUS_A Power           | Power    |
| A5    | CC1                   | –                                                | –               | CC 1 from CC Controller    | Output   |
| A6    | D1_P                  | USB0_D_P                                         | F12             | USB 2.0 #0 Data 1          | Bidir    |

| Pin # | Connector Pin<br>Name | Associated Module Pin<br>Name (See Note 1 and 2) | Module<br>Pin # | Usage/Description          | Type/Dir |
|-------|-----------------------|--------------------------------------------------|-----------------|----------------------------|----------|
| A7    | D1_N                  | USB0_D_N                                         | F13             |                            |          |
| A8    | SBU1                  | –                                                | –               | Unconnected                | –        |
| A9    | –                     | –                                                | –               | USB VBUS_A Power           | Power    |
| A10   | RX2_N                 | USBSS1_RX_P                                      | C22             | USB 3.2 #1 Receive 2 from  |          |
| A11   | RX2_P                 | USBSS1_RX_N                                      | C23             | mux                        | Input    |
| A12   | GND_A                 | –                                                | –               | Ground                     | Ground   |
| B1    | GND_B                 | –                                                | –               | Ground                     | Ground   |
| B2    | TX2_P                 | USBSS1_TX_P                                      | G23             | USB 3.2 #1 Transmit 2 from |          |
| B3    | TX2_N                 | USBSS1_TX_N                                      | G22             | mux                        | Output   |
| B4    | –                     | –                                                | –               | USB VBUS_A Power           | Power    |
| B5    | CC2                   | –                                                | –               | CC 2 from CC Controller    | Output   |
| B6    | D2_P                  | USB0_D_P                                         | F12             |                            |          |
| B7    | D2_N                  | USB0_D_N                                         | F13             | USB 2.0 #0 Data 2          | Bidir    |
| B8    | SBU2                  | –                                                | –               | Unconnected                | –        |
| B9    | –                     | –                                                | –               | USB VBUS_A Power           | Power    |
| B10   | RX1_N                 | USBSS1_RX_P                                      | C22             | USB 3.2 #1 Receive 1 from  |          |
| B11   | RX1_P                 | USBSS1_RX_N                                      | C23             | mux                        | Input    |
| B12   | GND_B                 | –                                                | –               | Ground                     | Ground   |

- 1. USB 3.2 module pin names are using the Orin NX and Orin Nano function names.
- 2. The module pins for the USB 3.2 ports are not directly connected to the USB connector pins but are routed through a multiplexer.
- 3. In the Type/Dir column, Output is to USB connectors. Input is from USB connectors. Bidir is for bidirectional signals.

<span id="page-11-0"></span>

| Legend   | Ground   | Power    | Reserved |
|----------|----------|----------|----------|
| Ground   | Power    | Reserved | Ground   |
| Power    | Reserved | Ground   | Power    |
| Reserved | Ground   | Power    | Reserved |

Table 2-2. USB 3.2 Type A Connector Pin Descriptions – J6

| Pin # | Module Pin Name<br>(see Note 1 and 2) | Module Pin # | Usage/Description                | Type/Dir |
|-------|---------------------------------------|--------------|----------------------------------|----------|
|       | USB 3.0 Type A (2)                    |              |                                  |          |
| 1     | –                                     | –            | VBUS Supply                      | Power    |
| 2     | USB1_D_N                              |              |                                  |          |
| 3     | USB1_D_P                              |              | USB 2.0 #2 Data from hub         | Bidir    |
| 4     | –                                     | –            | Ground                           | Ground   |
| 5     | USBSS0_RX_N                           | 161          | USB 3.1 Receive #2 Data from hub | Input    |

| Pin #              | Module Pin Name<br>(see Note 1 and 2) | Module Pin # | Usage/Description                 | Type/Dir |
|--------------------|---------------------------------------|--------------|-----------------------------------|----------|
| 6                  | USBSS0_RX_P                           | 163          |                                   |          |
| 7                  | –                                     | –            | Ground                            | Ground   |
| 8                  | USBSS0_TX_N                           | 166          |                                   |          |
| 9                  | USBSS0_TX_P                           | 168          | USB 3.1 Transmit #2 Data from hub | Output   |
| USB 3.0 Type A (1) |                                       |              |                                   |          |
| 10                 | –                                     | –            | VBUS Supply                       | Power    |
| 11                 | USB1_D_N                              | 115          |                                   |          |
| 12                 | USB1_D_P                              | 117          | USB 2.0 Data #1 Data from hub     | Bidir    |
| 13                 | –                                     | –            | Ground                            | Ground   |
| 14                 | USBSS0_RX_N                           | 161          |                                   |          |
| 15                 | USBSS0_RX_P                           | 163          | USB 3.1 Receive #1 Data from hub  | Input    |
| 16                 | –                                     | –            | Ground                            | Ground   |
| 17                 | USBSS0_TX_N                           | 166          |                                   |          |
| 18                 | USBSS0_TX_P                           | 168          | USB 3.1 Transmit #1 Data from hub | Output   |

- 1. USB 3.2 module pin names are using the Orin NX and Orin Nano function names.
- 2. The module pin names not directly connected to the USB connector pins but are routed to the input of the USB hub.
- 3. In the Type/Dir column, Output is to USB connectors. Input is from USB connectors. Bidir is for bidirectional signals.

<span id="page-12-0"></span>

| Legend<br>Ground<br>Power<br>Reserved |
|---------------------------------------|
|---------------------------------------|

Table 2-3. USB 3.2 Type A Connector Pin Description – J7

| Pin # | Module Pin Name<br>(see Note 1 and 2) | Module Pin # | Usage/Description                 | Type/Dir |
|-------|---------------------------------------|--------------|-----------------------------------|----------|
|       | USB 3.0 Type A (2)                    |              |                                   |          |
| 1     | –                                     | –            | VBUS Supply                       | Power    |
| 2     | USB1_D_N                              | 115          |                                   |          |
| 3     | USB1_D_P                              | 117          | USB 2.0 #4 Data from hub          | Bidir    |
| 4     | –                                     | –            | Ground                            | Ground   |
| 5     | USBSS0_RX_N                           | 161          |                                   |          |
| 6     | USBSS0_RX_P                           | 163          | USB 3.1 Receive #4 Data from hub  | Input    |
| 7     | –                                     | –            | Ground                            | Ground   |
| 8     | USBSS0_TX_N                           | 166          |                                   |          |
| 9     | USBSS0_TX_P                           | 168          | USB 3.1 Transmit #4 Data from hub | Output   |

| Pin # | Module Pin Name<br>(see Note 1 and 2) | Module Pin # | Usage/Description                 | Type/Dir |
|-------|---------------------------------------|--------------|-----------------------------------|----------|
|       | USB 3.0 Type A (1)                    |              |                                   |          |
| 10    | –                                     | –            | VBUS Supply                       | Power    |
| 11    | USB1_D_N                              | 115          |                                   |          |
| 12    | USB1_D_P                              | 117          | USB 2.0 Data #3 Data from hub     | Bidir    |
| 13    | –                                     | –            | Ground                            | Ground   |
| 14    | USBSS0_RX_N                           | 161          |                                   |          |
| 15    | USBSS0_RX_P                           | 163          | USB 3.1 Receive #3 Data from hub  | Input    |
| 16    | –                                     | –            | Ground                            | Ground   |
| 17    | USBSS0_TX_N                           | 166          |                                   |          |
| 18    | USBSS0_TX_P                           | 168          | USB 3.1 Transmit #3 Data from hub | Output   |

- 1. USB 3.2 module pin names are using the Orin NX and Orin Nano function names.
- 2. The module pin names not directly connected to the USB connector pins but are routed to the input of the USB hub.
- 3. In the Type/Dir column, Output is to USB connectors. Input is from USB connectors. Bidir is for bidirectional signals.

<span id="page-13-0"></span>

| Legend<br>Ground | Power | Reserved |
|------------------|-------|----------|
|------------------|-------|----------|

## 2.2 Gigabit Ethernet

The carrier board implements an RJ45 connector (J15) along with the necessary magnetics device.

<span id="page-13-1"></span>Table 2-4. Ethernet RJ45 Connector Pin Description – J15

| Pin # | Module Pin Name | Module Pin # | Usage/Description       | Type/Dir |
|-------|-----------------|--------------|-------------------------|----------|
| 1     | GPE_MDI0_P      | 186          | Gigabit Ethernet MDI 0+ | Bidir    |
| 2     | GPE_MDI0_N      | 184          | Gigabit Ethernet MDI 0– | Bidir    |
| 3     | GPE_MDI1_P      | 192          | Gigabit Ethernet MDI 1+ | Bidir    |
| 4     | –               | –            | MCT                     | –        |
| 5     | –               | –            | MCT                     | –        |
| 6     | GPE_MDI1_N      | 190          | Gigabit Ethernet MDI 1– | Bidir    |
| 7     | GPE_MDI2_P      | 198          | Gigabit Ethernet MDI 2+ | Bidir    |
| 8     | GPE_MDI2_N      | 196          | Gigabit Ethernet MDI 2– | Bidir    |
| 9     | GPE_MDI3_P      | 204          | Gigabit Ethernet MDI 3+ | Bidir    |

| Pin # | Module Pin Name | Module Pin # | Usage/Description                                                 | Type/Dir |
|-------|-----------------|--------------|-------------------------------------------------------------------|----------|
| 10    | GPE_MDI3_N      | 202          | Gigabit Ethernet MDI 3–                                           | Bidir    |
| 11    |                 |              |                                                                   |          |
| 12    |                 |              |                                                                   |          |
| 13    | –               | –            | Power-Over-Ethernet                                               | Power    |
| 14    |                 |              |                                                                   |          |
| 15    | –               | –            | Green LED Anode                                                   | Input    |
| 16    | GBE_LED_LINK    | 188          | Green LED Cathode. On for 1,000 Mbps link. Off for<br>10/100Mbps. | Output   |
| 17    | –               | –            | Yellow LED Anode                                                  | Input    |
| 18    | GBE_LED_ACT     | 194          | Yellow LED Cathode. On indicates activity.                        | Output   |
| 19    |                 |              |                                                                   |          |
| 20    | –               | –            | Shield Ground                                                     | Ground   |

Note: In the Type/Dir column, Output is to RJ45 connector. Input is from RJ45 connector. Bidir is for bidirectional signals.

<span id="page-14-2"></span>

| Legend | Ground | Power | Reserved |
|--------|--------|-------|----------|
|--------|--------|-------|----------|

## 2.3 DisplayPort

<span id="page-14-1"></span><span id="page-14-0"></span>A DisplayPort (DP) connector (J8) is provided. Dual mode is supported.

Table 2-5. DisplayPort Connector Pin Description – J8

| Pin # | Module Pin Name | Module Pin # | Usage/Description | Type/Dir |
|-------|-----------------|--------------|-------------------|----------|
| 1     | DP0_TXD0_P      | 41           | DP Lane 0+        | Output   |
| 2     | –               | –            | Ground            | Ground   |
| 3     | DP0_TXD0_N      | 39           | DP Lane 0–        | Output   |
| 4     | DP0_TXD1_P      | 47           | DP Lane 1+        | Output   |
| 5     | –               | –            | Ground            | Ground   |
| 6     | DP0_TXD1_N      | 45           | DP Lane 1–        | Output   |
| 7     | DP0_TXD2_P      | 53           | DP Lane 2+        | Output   |
| 8     | –               | –            | Ground            | Ground   |
| 9     | DP0_TXD2_N      | 51           | DP Lane 2–        | Output   |
| 10    | DP0_TXD3_P      | 59           | DP Lane 3+        | Output   |
| 11    | –               | –            | Ground            | Ground   |
| 12    | DP0_TXD3_N      | 57           | DP Lane 3–        | Output   |

| Pin # | Module Pin Name | Module Pin # | Usage/Description                                                                                                            | Type/Dir |
|-------|-----------------|--------------|------------------------------------------------------------------------------------------------------------------------------|----------|
| 13    | –               | –            | MODE to support Dual-role mode. Connects<br>from DP connector to PI3AUX221ZTAEX<br>device to select between DP or HDMI mode. | Input    |
| 14    | –               | –            | CEC_DP: Not used – pulled to GND through 1<br>Mohm resistor                                                                  | Unused   |
| 15    | DP0_AUX_N       | 90           | DisplayPort Auxiliary Channel 0-                                                                                             | Bidir    |
| 16    | –               | –            | Ground                                                                                                                       | Ground   |
| 17    | DP0_AUX_P       | 92           | DisplayPort Auxiliary Channel 0+                                                                                             | Bidir    |
| 18    | DP0_HPD         | 88           | HDMI™ Hot Plug Detect                                                                                                        | Input    |
| 19    | –               | –            | Power Return (Ground)                                                                                                        | Ground   |
| 20    | –               | –            | +3.3 V                                                                                                                       | Power    |

Note: In the Type/Dir column, Output is to DP connector. Input is from DP connector. Bidir is for bidirectional signals.

<span id="page-15-2"></span>

| Legend<br>Ground<br>Power | Reserved |
|---------------------------|----------|
|---------------------------|----------|

## 2.4 M.2 Key E Expansion Slot

The Jetson Orin Nano carrier board includes a M.2, Key E Slot Mini-PCIe Expansion slot (J10). This includes interface options for WiFi/BT including PCIe (x1), USB 2.0, UART, I2S, and I2C optional.

- **>** The Jetson Orin Nano Developer Kit carrier board will only support single sided M.2 Key E modules.
- <span id="page-15-1"></span>**>** Stuffing resistors for connecting I2C2 to pins 58 and 60 of the M.2 Key E connector are not installed by default. If I2C is required, 0Ω resistors can be installed at locations R106 and R107. Care should be taken as some M.2 cards can cause conflicts with other devices connected to the I2C interface.

<span id="page-15-0"></span>

| Pin # | Module Pin<br>Name | Module<br>Pin # | Usage/Description Type/Dir Pin # |        |   | Module Pin<br>Name | Module<br>Pin # | Usage/Description Type/Dir |             |
|-------|--------------------|-----------------|----------------------------------|--------|---|--------------------|-----------------|----------------------------|-------------|
| 1     | –                  |                 | Ground                           | Ground |   | –                  | –               | No Pin                     | –           |
| 3     | USB2_D_P           | 123             |                                  |        | 2 |                    |                 |                            |             |
| 5     | USB2_D_N           | 121             | USB 2.0 Data                     | Bidir  | 4 | –                  | –               | Main 3.3V Supply           | Power       |
| 7     | –                  |                 | Ground                           | Ground | 6 | –                  | –               | Unused                     | Unused      |
| 9     | –                  | –               | Unused                           | Unused | 8 | I2S1_CLK           | 226             | I2S #1 Clock               | Bidir, 1.8V |

| Pin# | Module Pin<br>Name | Module<br>Pin # | Usage/Description        | Type/Dir    | Pin# | Module Pin<br>Name | Module<br>Pin # | Usage/Description             | Type/Dir        |
|------|--------------------|-----------------|--------------------------|-------------|------|--------------------|-----------------|-------------------------------|-----------------|
| 11   |                    |                 |                          |             | 10   | I2S1_FS            | 224             | I2S #1 Left/Right<br>Clock    | Bidir, 1.8V     |
| 13   |                    |                 |                          |             | 12   | I2S1_DIN           | 222             | I2S #1 Data In                | Input, 1.8V     |
| 15   |                    |                 |                          |             | 14   | I2S1_DOUT          | 220             | I2S #1 Data Out               | Bidir, 1.8V     |
| 17   |                    |                 |                          |             | 16   | -                  | -               | Unused                        | Unused          |
| 19   |                    |                 |                          |             | 18   | -                  | -               | Ground                        | Ground          |
| 21   |                    |                 |                          |             | 20   | GPIO02             | 124             | Bluetooth #2 Wake<br>AP       | Input, 3.3V     |
| 23   |                    |                 |                          |             | 22   | UARTO_RXD          | 101             | UART #0 Receive               | Input, 1.8V     |
| 25   |                    |                 |                          |             | 24   |                    |                 |                               |                 |
| 27   |                    |                 | Key                      | Unused      | 26   |                    |                 | Key                           | Unused          |
| 29   |                    | _               | rey                      | Onuseu      | 28   |                    | _               | Rey                           | Onuseu          |
| 31   |                    |                 |                          |             | 30   |                    |                 |                               |                 |
| 33   | -                  | -               | Ground                   | Ground      | 32   | UARTO_TXD          | 99              | UART #0 Transmit              | Output,<br>1.8V |
| 35   | PEX1_TX0_P         | 174             | PCIe #1 Transmit         | Output      | 34   | UARTO_CTS*         | 105             | UART #0 Clear to<br>Send      | Input, 1.8V     |
| 37   | PEX1_TX0_N         | 172             | Lane 0                   |             | 36   | UARTO_RTS*         | 103             | UART #0 Request to<br>Send    | Output,<br>1.8V |
| 39   | -                  | -               | Ground                   | Ground      | 38   |                    |                 |                               |                 |
| 41   | PEX1_RX0_P         | 169             | PCIe #1 Receive Lane     | lanut       | 40   |                    |                 |                               |                 |
| 43   | PEX1_RX0_N         | 167             | 0                        | Input       | 42   |                    |                 | Unused                        | Unused          |
| 45   | -                  | -               | Ground                   | Ground      | 44   | _                  |                 | onusea                        | Onusea          |
| 47   | PEX1_CLK_P         | 175             | PCIe #1 Reference        | Output      | 46   |                    |                 |                               |                 |
| 49   | PEX1_CLK_N         | 173             | clock                    | Output      | 48   |                    |                 |                               |                 |
| 51   | -                  | -               | Ground                   | Ground      | 50   | CLK_32K_OUT        | 210             | Suspend Clock (32<br>KHz)     | Output,<br>3.3V |
| 53   | PEX1_CLKRE<br>Q*   | 182             | PCIe #1 Clock<br>Request | Bidir, 3.3V | 52   | PEXO_RST*          | 183             | PCIe #0 Reset                 | Output,<br>3.3V |
| 55   | PEX_WAKE*          | 179             | PCIe Wake                | Input, 3.3V | 54   | GPIO3              | 126             | BT Enable                     | Output,<br>3.3V |
| 57   | _                  | -               | Ground                   | Ground      | 56   | GPIO5              | 128             | Wi-Fi Disable                 | Output,<br>3.3V |
| 59   |                    |                 |                          |             | 58   | I2C2_SDA           | 234             | General I2C #2                | Bidir/OD,       |
| 61   | -                  |                 | Unused                   | Unused      | 60   | I2C2_SCL           | 232             | (optional)                    | 1.8V            |
| 63   | _                  | -               | Ground                   | Ground      | 62   | GPIO10             | 212             | M.2, Key E Connector<br>Alert | Input, 1.8V     |

| Pin# | Module Pin<br>Name | Module<br>Pin# | Usage/Description | Type/Dir | Pin # | Module Pin<br>Name | Module<br>Pin# | Usage/Description | Type/Dir |
|------|--------------------|----------------|-------------------|----------|-------|--------------------|----------------|-------------------|----------|
| 65   |                    |                |                   |          | 64    |                    |                |                   |          |
| 67   | _                  | -              | Unused            | Unused   | 66    |                    |                |                   |          |
| 69   | -                  | _              | Ground            | Ground   | 68    | -                  | -              | Unused            | Unused   |
| 71   |                    |                |                   |          | 70    |                    |                |                   |          |
| 73   | -                  | -              | Unused            | Unused   | 72    |                    |                |                   |          |
| 75   | _                  | _              | Ground            | Ground   | 74    | -                  | -              | Main 3.3V Supply  | Power    |

Note: In the Type/Dir column, Output is to M.2 module. Input is from M.2 module. Bidir is for bidirectional signals.

<span id="page-17-0"></span>

| <b>Legend</b> Ground | Power | Reserved |
|----------------------|-------|----------|
|----------------------|-------|----------|

### 2.5 M.2 Key M Expansion Slot

The carrier board includes two M.2, Key M Slots for NVMe storage (J11 and J24). The M.2, Key M slot J11 supports PCle (x4), Gen4. The M.2, Key M slot J24 supports PCle (x2), Gen4.

- > Jetson Orin Nano modules supports only up to Gen3 PCIe, and Jetson Orin NX modules support up
- > The Jetson Orin Nano Developer Kit carrier board will only support single sided M.2 Key M modules.

<span id="page-17-1"></span>Table 2-7. M.2 Key M Expansion Slot Pin Description – J11 (x4 PCle)

| Pin# | Module Pin<br>Name | Module<br>Pin# | Usage/Description | Type/Dir<br>Default | Pin# | Module Pin<br>Name | Module<br>Pin# | Usage/Description | Type/Dir<br>Default |
|------|--------------------|----------------|-------------------|---------------------|------|--------------------|----------------|-------------------|---------------------|
| 1    |                    |                |                   | _                   | 2    |                    |                |                   | _                   |
| 3    | -                  | _              | Ground            | Ground              | 4    | _                  | -              | Main 3.3V Supply  | Power               |
| 5    | PCIEO_RX3_N        | 155            | PCIe IF #0 Lane 3 |                     | 6    |                    |                |                   |                     |
| 7    | PCIEO_RX3_P        | 157            | Receive           | Input               | 8    | -                  | _              | Unused            | Unused              |
| 9    | _                  | _              | Ground            | Ground              | 10   |                    |                |                   |                     |
| 11   | PCIEO_TX3_N        | 154            | PCIe IF #0 Lane 3 |                     | 12   |                    |                |                   |                     |
| 13   | PCIEO_TX3_P        | 156            | Transmit          | Output              | 14   |                    |                |                   |                     |
| 15   | _                  | _              | Ground            | Ground              | 16   | _                  | _              | Main 3.3V Supply  | Power               |
| 17   | PCIEO_RX2_N        | 149            | PCIe IF #0 Lane 2 |                     | 18   |                    |                |                   |                     |
| 19   | PCIEO_RX2_P        | 151            | Receive           | Input               | 20   | -                  | -              | Unused            | Unused              |

| Pin# | Module Pin<br>Name | Module<br>Pin# | Usage/Description             | Type/Dir<br>Default | Pin# | Module Pin<br>Name | Module<br>Pin# | Usage/Description                                 | Type/Dir<br>Default |
|------|--------------------|----------------|-------------------------------|---------------------|------|--------------------|----------------|---------------------------------------------------|---------------------|
| 21   | _                  | _              | Ground                        | Ground              | 22   |                    |                |                                                   |                     |
| 23   | PCIEO_TX2_N        | 148            | PCIe IF #0 Lane 2             |                     | 24   |                    |                |                                                   |                     |
| 25   | PCIEO_TX2_P        | 150            | Transmit                      | Output              | 26   |                    |                |                                                   |                     |
| 27   | _                  | _              | Ground                        | Ground              | 28   |                    |                |                                                   |                     |
| 29   | PCIEO_RX1_N        | 137            | PCIe IF #0 Lane 1             |                     | 30   |                    |                |                                                   |                     |
| 31   | PCIEO_RX1_P        | 139            | Receive                       | Input               | 32   |                    |                |                                                   |                     |
| 33   | -                  | -              | Ground                        | Ground              | 34   |                    |                |                                                   |                     |
| 35   | PCIEO_TX1_N        | 140            | PCIe IF #0 Lane 1             |                     | 36   |                    |                |                                                   |                     |
| 37   | PCIEO_TX1_P        | 142            | Transmit                      | Output              | 38   |                    |                |                                                   |                     |
| 39   | -                  | -              | Ground                        | Ground              | 40   |                    |                | Harrand.                                          | l la constant       |
| 41   | PCIEO_RXO_N        | 131            | PCIe IF #0 Lane 0             |                     | 42   | _                  |                | Unused                                            | Unused              |
| 43   | PCIEO_RXO_P        | 133            | Receive                       | Input               | 44   | GPIO10             | 212            | M.2 Key M Alert                                   | Input, 1.8V         |
| 45   | -                  | -              | Ground                        | Ground              | 46   |                    |                | Harrand                                           | U d                 |
| 47   | PCIEO_TXO_N        | 134            | DOI: 15 #0   0                |                     | 48   | _                  |                | Unused                                            | Unused              |
| 49   | PCIEO_TXO_P        | 136            | PCIe IF #0 Lane 0<br>Transmit | Output              | 50   | PEXO_RST*          | 181            | PCIe IF #0 Reset                                  | Output,<br>3.3V     |
| 51   | _                  | _              | Ground                        | Ground              | 52   | PEXO_<br>CLKREQ*   | 180            | PCIe IF #0 Clock<br>Request                       | Input, 3.3V         |
| 53   | PCIEO_CLK_N        | 160            | PCIe IF #0 Reference          | Output              | 54   | PEX_WAKE*          | 179            | PCle Wake (Level<br>Shifted from 3.3V to<br>1.8V) | Input, 3.3V         |
| 55   | PCIEO_CLK_P        | 162            |                               |                     | 56   |                    |                |                                                   |                     |
| 57   | -                  | -              | Ground                        | Ground              | 58   | _                  |                | Unused                                            | Unused              |
| 59   |                    |                |                               |                     | 60   | _                  |                |                                                   |                     |
| 61   |                    |                |                               | l la cara           | 62   | _                  |                | Lieus and (March                                  | l la caral          |
| 63   | _                  |                | Unused (Key)                  | Unused              | 64   | _                  |                | Unused (Key)                                      | Unused              |
| 65   |                    |                |                               |                     | 66   |                    |                |                                                   |                     |
| 67   | <u>-</u>           | _              | Unused                        | Unused              | 68   | _                  | _              | 32 KHz Suspend Clock                              | Output,<br>3.3V     |
| 69   |                    |                |                               |                     | 70   |                    |                |                                                   |                     |
| 71   |                    |                |                               |                     | 72   | -                  | -              | Main 3.3V Supply                                  | Power               |
| 73   | -                  | -              | Ground                        | Ground              | 74   |                    |                |                                                   |                     |
| 75   |                    |                |                               |                     |      |                    |                | No Pin                                            | _                   |

Note: In the Type/Dir column, Output is to M.2 module. Input is from M.2 Module. Bidir is for bidirectional signals.

| Legend | Ground | Power | Reserved |
|--------|--------|-------|----------|

<span id="page-19-0"></span>Table 2-8. M.2 Key M Expansion Slot Pin Description – J24 (x2 PCIe)

| Pin# | Module Pin<br>Name | Module<br>Pin # | Usage/Description             | Type/Dir<br>Default | Pin# | Module Pin<br>Name | Module<br>Pin# | Usage/Description                                 | Type/Dir<br>Default |
|------|--------------------|-----------------|-------------------------------|---------------------|------|--------------------|----------------|---------------------------------------------------|---------------------|
| 1    |                    |                 |                               |                     | 2    |                    |                |                                                   |                     |
| 3    | _                  | -               | Ground                        | Ground              | 4    | -                  | -              | Main 3.3V Supply                                  | Power               |
| 5    |                    |                 |                               |                     | 6    |                    |                |                                                   |                     |
| 7    | -                  | _               | Unused                        | Unused              | 8    | -                  | _              | Unused                                            | Unused              |
| 9    | -                  | _               | Ground                        | Ground              | 10   |                    |                |                                                   |                     |
| 11   |                    |                 |                               |                     | 12   |                    |                |                                                   |                     |
| 13   | -                  | _               | Unused                        | Unused              | 14   |                    |                |                                                   |                     |
| 15   | -                  | _               | Ground                        | Ground              | 16   | -                  | -              | Main 3.3V Supply                                  | Power               |
| 17   |                    |                 |                               |                     | 18   |                    |                |                                                   |                     |
| 19   | -                  | _               | Unused                        | Unused              | 20   |                    |                |                                                   |                     |
| 21   | -                  | _               | Ground                        | Ground              | 22   |                    |                |                                                   |                     |
| 23   |                    |                 |                               |                     | 24   |                    |                |                                                   |                     |
| 25   | -                  | _               | Unused                        | Unused              | 26   |                    |                |                                                   |                     |
| 27   | _                  | _               | Ground                        | Ground              | 28   |                    |                |                                                   |                     |
| 29   | PCIE2_RX1_N        | 58              | PCIe IF #2 Lane 1             |                     | 30   |                    |                |                                                   |                     |
| 31   | PCIE2_RX1_P        | 60              | Receive                       | Input               | 32   | _                  | _              | Unused                                            | Unused              |
| 33   | -                  | -               | Ground                        | Ground              | 34   |                    |                |                                                   |                     |
| 35   | PCIE2_TX1_N        | 64              | PCle IF #2 Lane 1             | 0.1                 | 36   |                    |                |                                                   |                     |
| 37   | PCIE2_TX1_P        | 66              | Transmit                      | Output              | 38   |                    |                |                                                   |                     |
| 39   | -                  | -               | Ground                        | Ground              | 40   |                    |                |                                                   |                     |
| 41   | PCIE2_RX0_N        | 40              | PCIe IF #2 Lane 0             | Land                | 42   |                    |                |                                                   |                     |
| 43   | PCIE2_RX0_P        | 42              | Receive                       | Input               | 44   | GPIO10             | 212            | M.2 Key M Alert                                   | Input, 1.8V         |
| 45   | -                  | -               | Ground                        | Ground              | 46   |                    |                | l lava a d                                        | Llavaaal            |
| 47   | PCIE2_TX0_N        | 46              | DCIa IE #2 I and 0            |                     | 48   | _                  |                | Unused                                            | Unused              |
| 49   | PCIE2_TX0_P        | 48              | PCIe IF #2 Lane 0<br>Transmit | Output              | 50   | PEX2_RST*          | 219            | PCIe IF #0 Reset                                  | Output,<br>3.3V     |
| 51   | -                  | -               | Ground                        | Ground              | 52   | PEX2_CLKREQ        | 221            | PCIe IF #0 Clock<br>Request                       | Input, 3.3V         |
| 53   | PCIE2_CLK_N        | 52              | PCIe IF #2 Reference<br>Clock | Output              | 54   | PEX_WAKE*          | 179            | PCIe Wake (Level<br>Shifted from 3.3V to<br>1.8V) | Input, 3.3V         |
| 55   | PCIE2_CLK_P        | 54              |                               |                     | 56   |                    |                |                                                   |                     |
| 57   | -                  | _               | Ground                        | Ground              | 58   | -                  |                | Unused                                            | Unused              |
| 59   | _                  | _               | Unused (Key)                  | Unused              | 60   | -                  | -              | Unused (Key)                                      | Unused              |

| Pin # | Module Pin<br>Name | Module<br>Pin # | Usage/Description | Type/Dir<br>Default | Pin # | Module Pin<br>Name | Module<br>Pin # | Usage/Description            | Type/Dir<br>Default |
|-------|--------------------|-----------------|-------------------|---------------------|-------|--------------------|-----------------|------------------------------|---------------------|
| 61    |                    |                 |                   |                     | 62    |                    |                 |                              |                     |
| 63    |                    |                 |                   |                     | 64    |                    |                 |                              |                     |
| 65    |                    |                 |                   |                     | 66    |                    |                 |                              |                     |
| 67    | –                  | –               | Unused            | Unused              | 68    | –                  | –               | 32 KHz Suspend Clock Output, | 3.3V                |
| 69    |                    |                 |                   |                     | 70    |                    |                 |                              |                     |
| 71    |                    |                 |                   |                     | 72    | –                  | –               | Main 3.3V Supply             | Power               |
| 73    | –                  | –               | Ground            | Ground              | 74    |                    |                 |                              |                     |
| 75    |                    |                 |                   |                     |       |                    | –               | –No Pin                      | –                   |

- 1. PCIe 2 module pin names are using the Orin NX and Orin Nano function names.
- 2. In the Type/Dir column, Output is to M.2 module. Input is from M.2 Module. Bidir is for bidirectional signals.

| Legend | Ground | Power | Reserved |
|--------|--------|-------|----------|
|--------|--------|-------|----------|

# <span id="page-21-0"></span>**Chapter 3. Carrier Board Custom Expansion IF Connections**

The Jetson Orin Nano carrier board supports several expansion headers and connectors that have custom pinouts. The following lists the headers and connectors that have custom pinouts.

- > Jetson Orin Nano Module Connector, 260-pin, SO-DIMM, 1.27 mm pitch
- > Camera Connectors (x2), 22 position, Flex Connector, 0.5 mm pitch
- > 40-Pin Expansion Header, 2x20, 2.54 mm pitch
- > Button Header, 2x4, 2.54 mm pitch
- > Optional CAN Bus header
- > Fan Connector, 4-pin, 1.25 mm pitch
- > Optional real-time-clock (RTC) back-up connector
- > DC Power Jack
- > Optional Power-over Ethernet (PoE) header, 1x4, 2.54 mm pitch
- <span id="page-21-1"></span>> Optional PoE backpower header, 1x, 2.54 mm pitch

## 3.1 Jetson Orin Nano Module Connector

The carrier board interfaces to the Jetson Orin Nano module using a 260-pin SODIMM connector (J2). The carrier board has a TE Connectivity 2309413-1 connector. This interfaces with the Jetson Orin Nano edge fingers. The connector pinout can be found in the *Jetson Orin Nano Product Design Guide*.

## <span id="page-21-2"></span>3.2 Camera Connector

The Jetson Orin Nano carrier board includes two 22-position flex (0.5 mm pitch) camera connectors (J20 and J219). The connector used on the carrier board is a Molex Japan Part #54548-2272.

The connectors support the following.

- > J20: CSI 1 x2 lane
- > J21: CSI 1 x2 lane or 1 x4 lane
- > Both J20/J21: C
  - CAM\_I2C, clock, and control GPIOs for the camera
  - 3.3V Supply

<span id="page-22-0"></span>Table 3-1. Camera #0 Connector Pin Description – J20

| Pin # | Module Pin<br>Name | Module<br>Pin # | Usage/Description                                                                                                                                                               | Type/Dir     |
|-------|--------------------|-----------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------|
| 1     | –                  | –               | +3.3V                                                                                                                                                                           | Power        |
| 2     | CAM_I2C_SDA        | 215             | Camera I2C. 2.2 kΩ pull-ups on module. The module CAM_I2C                                                                                                                       | Bidir, 3.3V  |
| 3     | CAM_I2C_SCL        | 213             | pins connect to an I2C mux. The camera connector #0 (J20)<br>receives the I2C from the mux (first output). The I2C signals on<br>the camera side of the mux have 1 kΩ pull-ups. | Output, 3.3V |
| 4     | –                  | –               | Ground                                                                                                                                                                          | Ground       |
| 5     | CAM0_MCLK          | 116             | Camera #0 Primary Clock                                                                                                                                                         | Output, 1.8V |
| 6     | CAM0_PWDN          | 114             | Camera #0 Power-down                                                                                                                                                            | Output, 1.8V |
| 7     | –                  | –               | Ground                                                                                                                                                                          | Ground       |
| 8     | CSI0_D1_P          | 18              |                                                                                                                                                                                 |              |
| 9     | CSI0_D1_N          | 16              | CSI 0 Data 1                                                                                                                                                                    | Input        |
| 10    | –                  | –               | Ground                                                                                                                                                                          | Ground       |
| 11    | CSI0_D0_P          | 6               |                                                                                                                                                                                 |              |
| 12    | CSI0_D0_N          | 4               | CSI 0 Data 0                                                                                                                                                                    | Input        |
| 13    | –                  | –               | Ground                                                                                                                                                                          | Ground       |
| 14    | CSI1_CLK_P         | 11              |                                                                                                                                                                                 |              |
| 15    | CSI1_CLK_N         | 9               | CSI 0 Clock                                                                                                                                                                     | Input        |
| 16    | –                  | –               | Ground                                                                                                                                                                          | Ground       |
| 17    | CSI1_D1_P          | 17              |                                                                                                                                                                                 |              |
| 18    | CSI1_D1_N          | 15              | CSI 1 Data 1                                                                                                                                                                    | Input        |
| 19    | –                  | –               | Ground                                                                                                                                                                          | Ground       |
| 20    | CSI1_D0_P          | 5               |                                                                                                                                                                                 |              |
| 21    | CSI1_D0_N          | 3               | CSI 1 Data 0                                                                                                                                                                    | Input        |
| 22    | –                  | –               | Ground                                                                                                                                                                          | Ground       |

Note: In the Type/Dir column, Output is to camera module. Input is from camera module. Bidir is for bidirectional signals.

| Legend | Ground | Power | Reserved |
|--------|--------|-------|----------|

<span id="page-23-0"></span>Table 3-2. Camera #1 Connector Pin Description – J21

| Pin # | Module Pin<br>Name | Module<br>Pin # | Usage/Description                                                                                                                                                                | Type/Dir     |
|-------|--------------------|-----------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------|
| 1     | –                  | –               | +3.3V                                                                                                                                                                            | Power        |
| 2     | CAM_I2C_SDA        | 215             | Camera I2C. 2.2 kΩ pull-ups on module. The module CAM_I2C                                                                                                                        | Bidir, 3.3V  |
| 3     | CAM_I2C_SCL        | 213             | pins connect to an I2C mux. The camera connector #1 (J21)<br>receives the I2C from the mux (second output). The I2C signals<br>on the camera side of the mux have 1 kΩ pull-ups. | Output, 3.3V |
| 4     | –                  | –               | Ground                                                                                                                                                                           | Ground       |
| 5     | CAM1_MCLK          | 122             | Camera #0 Primary Clock                                                                                                                                                          | Output, 1.8V |
| 6     | CAM1_PWDN          | 120             | Camera #0 Power-down                                                                                                                                                             | Output, 1.8V |
| 7     | –                  | –               | Ground                                                                                                                                                                           | Ground       |
| 8     | CSI3_D1_P          | 35              |                                                                                                                                                                                  |              |
| 9     | CSI3_D1_N          | 33              | CSI 3 Data 1                                                                                                                                                                     | Input        |
| 10    | –                  | –               | Ground                                                                                                                                                                           | Ground       |
| 11    | CSI3_D0_P          | 23              |                                                                                                                                                                                  |              |
| 12    | CSI3_D0_N          | 21              | CSI 3 Data 0                                                                                                                                                                     | Input        |
| 13    | –                  | –               | Ground                                                                                                                                                                           | Ground       |
| 14    | CSI2_CLK_P         | 30              |                                                                                                                                                                                  |              |
| 15    | CSI2_CLK_N         | 28              | CSI 2 Clock                                                                                                                                                                      | Input        |
| 16    | –                  | –               | Ground                                                                                                                                                                           | Ground       |
| 17    | CSI2_D1_P          | 36              |                                                                                                                                                                                  |              |
| 18    | CSI2_D1_N          | 34              | CSI 2 Data 1                                                                                                                                                                     | Input        |
| 19    | –                  | –               | Ground                                                                                                                                                                           | Ground       |
| 20    | CSI2_D0_P          | 24              |                                                                                                                                                                                  |              |
| 21    | CSI2_D0_N          | 22              | CSI 2 Data 0                                                                                                                                                                     | Input        |
| 22    | –                  | –               | Ground                                                                                                                                                                           | Ground       |

Note: In the Type/Dir column, Output is to camera module. Input is from camera module. Bidir is for bidirectional signals.

| Legend | Ground | Power | Reserved |
|--------|--------|-------|----------|
|        |        |       |          |

## <span id="page-24-0"></span>3.3 40-Pin Expansion Header

The Jetson Orin Nano carrier board includes a 40-pin (2x20, 2.54 mm pitch) expansion header (J12). The connector used on the carrier board is an Astron Technology (Part # 27-0169H-220-1G-H).

The expansion connector includes various audio and control interfaces including:

- > I2S
- > Audio (AU) clock
- > I2C (x2)
- > SPI (x2)
- > UART
- > GPIOs (x3 See notes)

- **>** All the signals on the expansion header use 3.3V levels.
- **>** All the interface signal pins (I2S, I2C, SPI, UART, and AU clock) can also be configured as GPIOs.
- **>** Any pull-up or pull-down resistors on the signals (except I2C) must be weak (limited to >50 kΩ).

<span id="page-24-1"></span>Figure 3-1. Expansion Header Connections

<span id="page-25-0"></span>Table 3-3. Expansion Header Pin Description – J12

| Header<br>Pin # | Module Pin<br>Name | Module<br>Pin # | SoC Pin Name                       | Default Usage /<br>Description | Alternate<br>Functionality         | Type/ Dir               | Pin Drive<br>or Power<br>Pin Max<br>Current | SoC<br>GPIO<br>Port # | Power<br>on<br>Default | PU/PD on<br>Module | Notes |
|-----------------|--------------------|-----------------|------------------------------------|--------------------------------|------------------------------------|-------------------------|---------------------------------------------|-----------------------|------------------------|--------------------|-------|
| 1               | –                  | –               | –                                  | Main 3.3V Supply               | –                                  | Power (input)           | 1A                                          | –                     | –                      | –                  | 1     |
| 2               | –                  | –               | –                                  | Main 5.0V Supply               | –                                  | Power<br>(input/output) | 1A                                          | –                     | –                      | –                  | 1     |
| 3               | I2C1_SDA           | 191             | GP16_I2C8_DAT                      | I2C #1 Data                    | –                                  | Bidir OD                | ±2 mA                                       | PDD.02                | z                      | 2.2KΩ PU           | 2     |
| 4               | –                  | –               | –                                  | Main 5.0V Supply               | –                                  | Power                   | 1A                                          | –                     | –                      | –                  | –     |
| 5               | I2C1_SCL           | 189             | GP15_I2C8_CLK                      | I2C #1 Clock                   | –                                  | Bidir OD                | ±2 mA                                       | PDD.01                | z                      | 2.2KΩ PU           | 2     |
| 6               | –                  | –               | –                                  | Ground                         | –                                  | Ground                  | –                                           | –                     | –                      | –                  | –     |
| 7               | GPIO09             | 211             | GP167                              | GPIO                           | Audio Primary Clock                | Bidir/Output            | ±20uA                                       | PAC.06                | pd                     |                    | 3     |
| 8               | UART1_TXD          | 203             | GP70_UART1_T<br>XD_BOOT2_STR<br>AP | UART #1 Transmit               | GPIO                               | Output/Bidir            | ±20uA                                       | PR.02                 | pd                     |                    | 3     |
| 9               | –                  | –               | –                                  | Ground                         | –                                  | Ground                  | –                                           | –                     | –                      | –                  | –     |
| 10              | UART1_RXD          | 205             | GP71_UART1_R<br>XD                 | UART #1 Receive                | GPIO                               | Input/Bidir             | ±20uA                                       | PR.03                 | pd                     |                    | 3     |
| 11              | UART1_RTS*         | 207             | GP72_UART1_<br>RTS_N               | GPIO                           | UART #2 Request to<br>Send         | Bidir/Output            | ±20uA                                       | PR.04                 | pd                     |                    | 3     |
| 12              | I2S0_SCLK          | 199             | GP122                              | GPIO                           | Audio I2S #0 Clock                 | Bidir                   | ±20uA                                       | PH.07                 | pd                     |                    | 3     |
| 13              | SPI1_SCK           | 106             | GP36_SPI3_CLK                      | GPIO                           | SPI #1 Shift Clock                 | Bidir/Output            | ±20uA                                       | PY.00                 | pd                     |                    | 3     |
| 14              | –                  | –               | –                                  | Ground                         | –                                  | Ground                  | –                                           | –                     | –                      | –                  | –     |
| 15              | GPIO12             | 218             | GP88_PWM1                          | GPIO                           | –                                  | Bidir                   | ±20uA                                       | PN.01                 | z                      |                    | 3     |
| 16              | SPI1_CSI1*         | 112             | GP40_SPI3_CS1<br>_N                | GPIO                           | SPI #1 Chip Select #1              | Bidir/Output            | ±20uA                                       | PY.04                 | z                      |                    | 3     |
| 17              | –                  | –               | –                                  | Main 3.3V Supply               | –                                  | Power                   | 1A                                          | –                     | –                      | –                  | 1     |
| 18              | SPI1_CSI0*         | 110             | GP39_SPI3_CS0<br>_N                | GPIO                           | SPI #0 Chip Select #0              | Bidir/Output            | ±20uA                                       | PZ.06                 | z                      |                    | 3     |
| 19              | SPI0_MOSI          | 89              | GP49_SPI1_MO<br>SI                 | GPIO                           | SPI #0 Primary<br>Out/Secondary In | Bidir/Output            | ±20uA                                       | PZ.05                 | pd                     |                    | 3     |
| 20              | –                  | –               | –                                  | Ground                         | –                                  | Ground                  | –                                           | –                     | –                      | –                  | –     |
| 21              | SPI0_MISO          | 93              | GP48_SPI1_MIS<br>O                 | GPIO                           | SPI #0 Primary<br>In/Secondary Out | Bidir/Input             | ±20uA                                       | PZ.04                 | pd                     |                    | 3     |
| 22              | SPI1_MISO          | 108             | GP37_SPI3_MIS<br>O                 | GPIO                           | SPI #1 Primary<br>In/Secondary Out | Bidir/Input             | ±20uA                                       | PY.01                 | pd                     |                    | 3     |
| 23              | SPI0_SCK           | 91              | GP47_SPI1_CLK                      | GPIO                           | SPI #0 Shift Clock                 | Bidir/Output            | ±20uA                                       | PZ.03                 | pd                     |                    | 3     |
| 24              | SPI0_CS0*          | 95              | GP50_SPI1_CS0<br>_N                | GPIO                           | SPI #0 Chip Select #0              | Bidir/Output            | ±20uA                                       | PZ.06                 | z                      |                    | 3     |

| Header<br>Pin # | Module Pin<br>Name | Module<br>Pin # | SoC Pin Name         | Default Usage /<br>Description | Alternate<br>Functionality         | Type/ Dir            | Pin Drive<br>or Power<br>Pin Max<br>Current | SoC<br>GPIO<br>Port # | Power<br>on<br>Default | PU/PD on<br>Module | Notes |
|-----------------|--------------------|-----------------|----------------------|--------------------------------|------------------------------------|----------------------|---------------------------------------------|-----------------------|------------------------|--------------------|-------|
| 25              | –                  | –               | –                    | Ground                         | –                                  | Ground               | –                                           | –                     | –                      | –                  | –     |
| 26              | SPI0_CS1*          | 97              | GP51_SPI1_CS1<br>_N  | GPIO                           | SPI #0 Chip Select #1              | Bidir/Output         | ±20uA                                       | PZ.07                 | pu                     |                    | 3     |
| 27              | I2C0_SDA           | 187             | GP14_I2C2_DAT        | I2C #0 Data                    | GPIO                               | Bidir OD/Bidir ±2 mA |                                             | PDD.00                | z                      | 1.5KΩ PU           | 2     |
| 28              | I2C0_SCL           | 185             | GP13_I2C2_CLK        | I2C #0 Clock                   | GPIO                               | Bidir OD/Bidir ±2 mA |                                             | PCC.07                | z                      | 1.5KΩ PU           | 2     |
| 29              | GPIO01             | 118             | GP65                 | GPIO                           | General Purpose<br>Clock #0        | Bidir/Output         | ±20uA                                       | PQ.05                 | pd                     |                    | 3     |
| 30              | –                  | –               | –                    | Ground                         | –                                  | Ground               | –                                           | –                     | –                      | –                  | –     |
| 31              | GPIO11             | 216             | GP66                 | GPIO                           | General Purpose<br>Clock #1        | Bidir/Output         | ±20uA                                       | PQ.06                 | pd                     |                    | 3     |
| 32              | GPIO07             | 206             | GP113_PWM7           | GPIO                           | PWM                                | Bidir/Output         | ±20uA                                       | PG.06                 | z                      |                    | 3     |
| 33              | GPIO13             | 228             | GP115                | GPIO                           | PWM                                | Bidir/Output         | ±20uA                                       | PH.00                 | z                      |                    | 3     |
| 34              | –                  | –               | –                    | Ground                         | –                                  | Ground               | –                                           | –                     | –                      | –                  | –     |
| 35              | I2S0_FS            | 197             | GP125                | GPIO                           | Audio I2S #0 Field<br>Select       | Bidir                | ±20uA                                       | PI.02                 | pd                     |                    | 3     |
| 36              | UART1_CTS*         | 209             | GP73_UART1_<br>CTS_N | GPIO                           | UART #1 Clear to<br>Send           | Bidir/Input          | ±20uA                                       | PR.05                 | pd                     |                    | 3     |
| 37              | SPI1_MOSI          | 104             | GP38_SPI3_MO<br>SI   | GPIO                           | SPI #1 Primary<br>Out/Secondary In | Bidir/Output         | ±20uA                                       | PY.02                 | pd                     |                    | 3     |
| 38              | I2S0_DIN           | 195             | GP124                | GPIO                           | Audio I2S #0 Data in               | Bidir/Input          | ±20uA                                       | PI.01                 | pd                     |                    | 3     |
| 39              | –                  | –               | –                    | Ground                         | –                                  | Ground               | –                                           | –                     | –                      | –                  | –     |
| 40              | I2S0_DOUT          | 193             | GP123                | GPIO                           | Audio I2S #0 Data<br>Out           | Bidir/Output         | ±20uA                                       | PI.00                 | pd                     |                    | 3     |

- 1. This is current capability per power pin.
- 2. These pins are connected to the SoC directly. They are open-drain (either pulled up or driven low by the SoC when configured as outputs). The max drive that meets the data sheet VOL is ±2 mA.
- 3. These pins connect to TI TXB0108 level translators. Due to the design of these devices, the output drivers are very weak, so they can be overdriven by another connected device output for bidirectional support.
- 4. In the Type/Dir column, output is to expansion header. Input is from expansion header. Bidir is for bidirectional signals. Where two directions are shown, the first is for the primary function (mostly GPIOs) and the second is for the alternate function.
- 5. Where the signal direction is input or output in this table (Table 3-3), this matches the typical special function usage (for example, SPI, I2S, and so on). The direction is bidirectional if these are configured as GPIOs.
- 6. All signals on the 40-pin header are 3.3V levels.

| Legend | Ground | Power | Reserved |
|--------|--------|-------|----------|
|        |        |       |          |

## <span id="page-27-0"></span>3.4 Button Header

The Jetson Orin Nano carrier board brings several system signals (power, reset, and force recovery), UART, and Sleep/Wake LED-related signals to a pair of standard 0.254 mm pitch header. The button header is J14.

<span id="page-27-1"></span>Table 3-4. Button Header Description – J14

| Pin<br># | Module Pin Name       | Module<br>Pin # | Usage/Description                                                                                  | Type/Dir<br>Default |
|----------|-----------------------|-----------------|----------------------------------------------------------------------------------------------------|---------------------|
| 1        | –                     | –               | PC_LED-: Connects to LED Cathode to indicate System<br>Sleep/Wake (Off when system in sleep mode)  | Input, 5V           |
| 2        | –                     | –               | PC_LED+: Connects to LED Anode (see Pin 1)                                                         | Output              |
| 3        | UART2_RXD (DEBUG) 238 |                 | UART #2 Receive                                                                                    | Input, 3.3V         |
| 4        | UART2_TXD (DEBUG) 236 |                 | UART #2 Transmit                                                                                   | Output, 3.3V        |
| 5        | –                     | –               | AC OK: Connect pins 5 and 6 to disable Auto-Power-On and<br>require power button press.            | Input, 3.3V         |
| 6        | –                     | –               | Auto Power-on disable: Pulled to GND. See Pin 5.                                                   | Not<br>applicable   |
| 7        | –                     | –               | Ground                                                                                             | Ground              |
| 8        | SYS_RESET*            | 239             | Temporarily connect pins 7 and 8 to reset system                                                   | Input, 1.8V         |
| 9        | –                     | –               | Ground                                                                                             | Ground              |
| 10       | FORCE_RECOVERY*       | 214             | Connect pins 9 and 10 during power-on to put system in USB<br>Force Recovery mode.                 | Input, 1.8V         |
| 11       | –                     | –               | Ground                                                                                             | Ground              |
| 12       | SLEEP/WAKE*           | 240             | Connect pins 11 and 12 to initiate power-on if Auto-Power<br>On disabled (Pins 5 and 6 connected). | Input, 5V           |

Note: In the Type/Dir column, Output is to button header. Input is from button header. Bidir is for bidirectional signals.

| Ground | Power | Reserved | Legend |
|--------|-------|----------|--------|
|--------|-------|----------|--------|

## <span id="page-28-0"></span>3.5 Optional CAN Bus Header

The Jetson Orin Nano carrier board includes the footprint for a 4-pin, 2.54 mm pitch header (J17) which supports a CAN bus interface.

<span id="page-28-2"></span>Table 3-5. Optional CAN Header Pin Description – J17

| Pin # | Module Pin Name | Module Pin # | Usage/Description | Type/Dir Default |
|-------|-----------------|--------------|-------------------|------------------|
| 1     | CAN_TX          | 145          | CAN Bus transmit  | Output, 3.3V     |
| 2     | CAN_RX          | 143          | CAN Bus receive   | Input, 3.3V      |
| 3     | –               | –            | Ground            | Ground           |
| 4     | –               | –            | Main 3.3V Supply  | Power            |

Note: In the Type/Dir column, Output is to CAN connector. Input is from CAN connector. Bidir is for bidirectional signals.

<span id="page-28-1"></span>

## 3.6 Fan Connector

The Jetson Orin Nano carrier board includes a 4-pin fan header (J13). The connector used is a Singatron Enterprise Co., Ltd., Part # 2WBA2542WVC-F-04PNLBT1N00G.

<span id="page-28-3"></span>Table 3-6. Fan Connector Pin Description – J13

| Pin # | Module Pin Name | Module Pin # | Usage/Description                 | Type/Dir Default |
|-------|-----------------|--------------|-----------------------------------|------------------|
| 1     | –               | –            | Ground                            | Ground           |
| 2     | –               | –            | Main 5.0V Supply                  | Power            |
| 3     | GPIO08          | 208          | Fan Tachometer signal             | Input, 5V        |
| 4     | GPIO14          | 230          | Fan Pulse Width Modulation signal | Output, 5V       |

Note: In the Type/Dir column, Output is to fan connector. Input is from fan connector. Bidir is for bidirectional signals.

| Legend | Ground | Power | Reserved |
|--------|--------|-------|----------|
|        |        |       |          |

# <span id="page-29-0"></span>3.7 Optional Battery Back-up Coin Cell Holder

The Jetson carrier board has a connector where an RTC backup battery can be connected. This connector (J3) is commonly used on laptop designs. The connector used is a Wieson Technologies AC2651-0011-003-HH, 2-pin, 1.25 mm pitch connector.

<span id="page-29-3"></span>Table 3-7. RTC Backup Batter Connector Pin Description – J3

| Pin # | Associated Module<br>Pin Name | Module<br>Pin # | Usage/Description         | Type/Dir |
|-------|-------------------------------|-----------------|---------------------------|----------|
| 1     | PM<br>IC_BBAT                 | 235             | RTC backup battery supply | Power    |
| 2     | –                             | –               | Ground                    | Ground   |

<span id="page-29-1"></span>**Legend** Ground Power Reserved

## 3.8 DC Power Jack

The Jetson Orin Nano carrier board uses a DC power jack (J16) to bring in the power from the included DC power supply. The jack used on the carrier board is a Singatron Enterprise part (part #: 2DC-0005D206F). The mating barrel jack connector dimensions are:

- > Barrel length: 9.5 mm
- > Barrel diameter: 5.5 mm
- > Pin receptacle: Accepts 2.5 mm jack pin
- > The center pin is positive (+V)
- <span id="page-29-2"></span>> Max current supported is 3.5 A

Figure 3-2. Jack Connector

<span id="page-30-2"></span>Table 3-8. DC Jack Pin Description – J16

| Pin #  | Module Pin Name Module Pin # |       | Usage/Description                              |          | Type/Dir Default |  |
|--------|------------------------------|-------|------------------------------------------------|----------|------------------|--|
| 1      | –                            | –     | Main DC input supplying DC jack input (9-20 V) |          | Power            |  |
| 2      | –                            | –     | Ground                                         |          | Ground           |  |
| 3      | –                            | –     | Ground                                         |          | Ground           |  |
|        |                              |       |                                                |          |                  |  |
| Legend | Ground                       | Power |                                                | Reserved |                  |  |

# <span id="page-30-0"></span>3.9 Optional Power-Over Ethernet and Backpower Headers

The Jetson Orin Nano carrier board provides an option for an alternate main power input (besides the DC power jack). A 4-pin Power over Ethernet (PoE) header (J19 – 1x4 male, 2.54 mm pitch) brings out the VC power pins of the Ethernet connector. In addition, a 2 pin Backpower header (J18 – 1x2 male, 2.54 mm pitch) provides an alternate path for the input voltage (3 A max). To use this alternate PoE power mechanism, the design will require a power converter to take the high-voltage PoE supply (38 V-60 V) and convert it to the 5 V-20 V input the carrier board requires.

<span id="page-30-1"></span>Figure 3-3. PoE Alternative Power Input

<span id="page-30-3"></span>Table 3-9. PoE Header – J19

| Pin #  | Module Pin Name Module Pin # |       | Usage/Description                     |          |       | Type/Dir Default |
|--------|------------------------------|-------|---------------------------------------|----------|-------|------------------|
| 1      | –                            | –     | Ethernet RG45 connector PoE VC1 power |          |       | Power            |
| 2      | –                            | –     | Ethernet RG45 connector PoE VC2 power |          | Power |                  |
| 3      | –                            | –     | Ethernet RG45 connector PoE VC3 power |          |       | Power            |
| 4      | –                            | –     | Ethernet RG45 connector PoE VC4 power |          |       | Power            |
|        |                              |       |                                       |          |       |                  |
| Legend | Ground                       | Power |                                       | Reserved |       |                  |

<span id="page-31-0"></span>Table 3-10. PoE Backpower Header – J18

| Pin # | Module Pin Name Module Pin # |   | Usage/Description                                             | Type/Dir Default |
|-------|------------------------------|---|---------------------------------------------------------------|------------------|
| 1     | –                            | – | Main DC input supplying DC jack input (9 V-20 V).<br>3 A max. | Power            |
| 2     | –                            | – | Ground                                                        | Ground           |

| Legend | Ground | Power | Reserved |
|--------|--------|-------|----------|
|        |        |       |          |

## <span id="page-32-0"></span>**Chapter 4. Mechanical Specification**

[Figure 4-1](#page-32-1) and [Figure 4-2](#page-33-0) show the mechanical dimensions for the carrier board and the developer kit.

<span id="page-32-1"></span>The Developer Kit Weighs 0.175kg

Figure 4-1. Developer Kit Carrier Board Mechanical Dimensions

<span id="page-33-0"></span>Figure 4-2. Developer Kit Mechanical Dimensions

## <span id="page-34-2"></span>**Chapter 5. Interface Power**

<span id="page-34-0"></span>Figure 5-1. **Power Diagram** 

<span id="page-34-1"></span>Note: Jetson Orin Nano DevKit Carrier Board has pull-up on MODULE\_ID removed. Only 5V mode (VDD\_5V\_SYS) supported regardless of module type.

The following tables show the allocation of supplies to the connectors on the Jetson Orin Nano carrier board and current capabilities.

<span id="page-35-2"></span>Table 5-1. Interface Power Supply Allocation

| Power Rails  | Usage                                            | (V)  | Power Supply or Gate        | Source                             | Enable                                 |
|--------------|--------------------------------------------------|------|-----------------------------|------------------------------------|----------------------------------------|
| DC_IN        | Main power input from DC<br>Adapter              | 19.5 | AONR21357025 Power<br>mux   | DC Adapter                         |                                        |
| VDD_5V_SYS   | Main 5.0V supply                                 | 5.0  | GS9230NVTQ-R                | VDD_CVB (DC_IN<br>after Power FET) | VDD_CVB                                |
| VDD_3V3_SYS  | Main 3.3V supply                                 | 3.3  | GS9230NVTQ-R                | VDD_CVB                            | SYS_RESET_IN*                          |
| 3V3_AO       | Button MCU                                       | 3.3  | GS7116S5-ADJ-R LDO          | VDD_5V_SYS                         | VDD_5V_SYS<br>regulator power<br>good  |
| VDD_1V8      | Main 1.8V supply                                 | 1.8  | AP2127K-1.8TRG1             | VDD_3V3_SYS                        | 3.3V_IO_PG                             |
| VDD_AV10_HUB | USB hub                                          | 1.1  | GS7303ACTD-R                | VDD_5V_SYS                         | VDD_3V3_SYS<br>regulator power<br>good |
| USBC_VBUS    | 5V VBUS for USB Type C<br>connector              | 5.0  | AP22811AW5-7                | VDD_5V_SYS                         | ID from USB Type C<br>CC controller    |
| USB_VBUS_A   | 5V VBUS for dual stacked 3.0<br>Type A connector | 5.0  | AP22811AW5-7 Load<br>Switch | VDD_5V_SYS                         | From USB Hub                           |
| USB_VBUS_B   | 5V VBUS for dual stacked 3.0<br>Type A connector | 5.0  | AP22811AW5-7 Load<br>Switch | VDD_5V_SYS                         | From USB Hub                           |
| VDD_3V3_DP   | 3.3V rail for DP connector                       | 5.0  | GS7612S5MC-R Load<br>Switch | VDD_3V3_SYS                        | VDD_3V3_SYS<br>regulator power<br>good |

<span id="page-35-1"></span><span id="page-35-0"></span>Table 5-2. Interface Supply Current Capabilities

| Power Rails | Usage                            | (V)  | Max Current (A) |
|-------------|----------------------------------|------|-----------------|
| DCJ_IN      | Main power input from DC Adapter | 19.0 | 4.2             |
| VDD_5V_SYS  | Main 5.0V supply                 | 5.0  | 7.8             |
| VDD_3V3_SYS | Main 3.3V supply                 | 3.3  | 5.4             |
| VDD_1V8     | Main 1.8V supply                 | 1.8  | 0.0002          |
| 3V3_AO      | 3.3V Always-on supply            | 3.3  | 0.200           |

<span id="page-36-1"></span><span id="page-36-0"></span>Table 5-3. Supply Current Capabilities per Connector per Supply

| Power Rails  | Connector              | (V) | Max Current (A) |
|--------------|------------------------|-----|-----------------|
| VDD_5V_SYS   | SO-DIMM (VDD_IN)       | 5.0 | 5.0             |
|              | 40-pin header          |     | 0.5             |
|              | Fan connector          |     | 0.15            |
| VDD_3V3_DP   | DP connector           |     | 0.5             |
| USBC_VBUS    | USB Type C             |     | 0.5             |
| USB_VBUS_A/B | USB 3.2 type A (x4)    |     | 0.5             |
| VDD_3V3_SYS  | 40-pin header          | 3.3 | 0.1             |
|              | M.2 Key E socket       |     | 0.8             |
|              | M.2 Key M sockets (x2) |     | 2.1             |
|              | Camera connectors (x2) |     | 0.26            |

#### Notice

This document is provided for information purposes only and shall not be regarded as a warranty of a certain functionality, condition, or quality of a product. NVIDIA Corporation ("NVIDIA") makes no representations or warranties, expressed or implied, as to the accuracy or completeness of the information contained in this document and assumes no responsibility for any errors contained herein. NVIDIA shall have no liability for the consequences or use of such information or for any infringement of patents or other rights of third parties that may result from its use. This document is not a commitment to develop, release, or deliver any Material (defined below), code, or functionality.

NVIDIA reserves the right to make corrections, modifications, enhancements, improvements, and any other changes to this document, at any time without notice.

Customer should obtain the latest relevant information before placing orders and should verify that such information is current and complete. NVIDIA products are sold subject to the NVIDIA standard terms and conditions of sale supplied at the time of order acknowledgement, unless otherwise agreed in an individual sales agreement signed by authorized representatives of NVIDIA and customer ("Terms of Sale"). NVIDIA hereby expressly objects to applying any customer general terms and conditions with regards to the purchase of the NVIDIA product referenced in this document. No contractual obligations are formed either directly or indirectly by this document.

Unless specifically agreed to in writing by NVIDIA, NVIDIA products are not designed, authorized, or warranted to be suitable for use in medical, military, aircraft, space, or life support equipment, nor in applications where failure or malfunction of the NVIDIA product can reasonably be expected to result in personal injury, death, or property or environmental damage. NVIDIA accepts no liability for inclusion and/or use of NVIDIA products in such equipment or applications and therefore such inclusion and/or use is at customer's own risk.

NVIDIA makes no representation or warranty that products based on this document will be suitable for any specified use. Testing of all parameters of each product is not necessarily performed by NVIDIA. It is customer's sole responsibility to evaluate and determine the applicability of any information contained in this document, ensure the product is suitable and fit for the application planned by customer, and perform the necessary testing for the application in order to avoid a default of the application or the product. Weaknesses in customer's product designs may affect the quality and reliability of the NVIDIA product and may result in additional or different conditions and/or requirements beyond those contained in this document. NVIDIA accepts no liability related to any default, damage, costs, or problem which may be based on or attributable to: (i) the use of the NVIDIA product in any manner that is contrary to this document or (ii) customer product designs.

No license, either expressed or implied, is granted under any NVIDIA patent right, copyright, or other NVIDIA intellectual property right under this document. Information published by NVIDIA regarding third-party products or services does not constitute a license from NVIDIA to use such products or services or a warranty or endorsement thereof. Use of such information may require a license from a third party under the patents or other intellectual property rights of the third party, or a license from NVIDIA under the patents or other intellectual property rights of NVIDIA.

Reproduction of information in this document is permissible only if approved in advance by NVIDIA in writing, reproduced without alteration and in full compliance with all applicable export laws and regulations, and accompanied by all associated conditions, limitations, and notices. THIS DOCUMENT AND ALL NVIDIA DESIGN SPECIFICATIONS, REFERENCE BOARDS, FILES, DRAWINGS, DIAGNOSTICS, LISTS, AND OTHER DOCUMENTS (TOGETHER AND SEPARATELY, "MATERIALS") ARE BEING PROVIDED "AS IS." NVIDIA MAKES NO WARRANTIES, EXPRESSED, IMPLIED, STATUTORY, OR OTHERWISE WITH RESPECT TO THE MATERIALS, AND EXPRESSLY DISCLAIMS ALL IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE. TO THE EXTENT NOT PROHIBITED BY LAW, IN NO EVENT WILL NVIDIA BE LIABLE FOR ANY DAMAGES, INCLUDING WITHOUT LIMITATION ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, HOWEVER CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY, ARISING OUT OF ANY USE OF THIS DOCUMENT, EVEN IF NVIDIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. Notwithstanding any damages that customer might incur for any reason whatsoever, NVIDIA's aggregate and cumulative liability towards customer for the products described herein shall be limited in accordance with the Terms of Sale for the product.

### Trademarks

NVIDIA, the NVIDIA logo, Jetson, Jetson Orin Nano, and NVIDIA Orin are trademarks and/or registered trademarks of NVIDIA Corporation in the U.S. and other countries. Other company and product names may be trademarks of the respective companies with which they are associated.

### VESA DisplayPort

DisplayPort and DisplayPort Compliance Logo, DisplayPort Compliance Logo for Dual-mode Sources, and DisplayPort Compliance Logo for Active Cables are trademarks owned by the Video Electronics Standards Association in the United States and other countries.

### HDMI

HDMI, the HDMI logo, and High-Definition Multimedia Interface are trademarks or registered trademarks of HDMI Licensing LLC.

#### Copyright

© 2023 NVIDIA Corporation. All rights reserved.
