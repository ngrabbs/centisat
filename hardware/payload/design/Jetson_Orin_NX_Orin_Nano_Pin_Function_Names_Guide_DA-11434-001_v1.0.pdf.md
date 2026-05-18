[Figure: The NVIDIA logo is a green and white eye-shaped symbol with a stylized, abstract design. The eye is surrounded by a green square, with a white eye-like shape inside. The word 'NVIDIA' is written in bold, modern font below the symbol.]

# **Jetson Orin NX Series and Jetson Orin Nano Series Pin and Function Names Guide**

Application Note

### Document History

#### DA-11434-001\_v1.0

| Version | Date         | Description of Change |
|---------|--------------|-----------------------|
| 01      | July 5, 2023 | Initial release       |

### Table of Contents

| Introduction                                         | 1 |
|------------------------------------------------------|---|
| Pin and Function Names                               | 3 |
| Pinmux                                               |   |
| Data Sheet                                           |   |
| Technical Reference Manual                           |   |
| Design Guide                                         | 6 |
| Pin Description Spreadsheet                          | 6 |
| Reference Design Files                               | 8 |
| Chip, Module, and Carrier Board Pin Name and Numbers | 9 |

### List of Figures

| Figure 1. | Pad Control for I2S1_CLK | 5 |
|-----------|--------------------------|---|
| Figure 2. | Design Schematics        | 8 |

### List of Tables

| Table 1. | Hardware References and Feature Documentation      | <br>1 |
|----------|----------------------------------------------------|-------|
| Table 2. | Pin Name Usage                                     | 3     |
| Table 3. | Pinmux I2S1                                        | 3     |
| Table 4. | Data Sheet I2S1 Pin Descriptions                   | 4     |
| Table 5. | Design Guide Audio I2S and MCLK Pin Descriptions   | <br>6 |
| Table 6. | Design Guide Audio I2S and MCLK Signal Connections | <br>6 |
| Table 7. | Pin Description Spreadsheet (I2S1 Rows)            | 7     |
| Table 8. | Chip, Module, and Carrier Board Pinout<br>         | 9     |

## <span id="page-4-0"></span>**Introduction**

The NVIDIA® Jetson™ Orin NX series and Jetson Orin Nano™ series System on Module (SOM) is built around the NVIDIA Orin™ System on Chip (SoC). Jetson Orin NX series and Orin Nano series documentation often refers to names of interfaces, pins, functions, and so on, from a SOM perspective. However, other documentation (for example, the Technical Reference Manual (TRM)) will necessarily take an SoC perspective. Some documentation will reference both SOM and SoC naming. It is important to understand whether a given document is using the following with reference to the SOM or the SoC.

- > Pin names and numbers
- > Interface names and instances
- > Function names and instances

[Figure: A blank white screen with a single, empty, gray box in the center.]

**Note:** References to Jetson Orin NX or Jetson Orin Nano apply to any of the Jetson Orin NX series or Jetson Orin Nano series of modules respectively.

Various documents are provided to help customers design, lay out, build, and configure NVIDIA® Jetson™ module-based designs.

[Table 1](#page-4-1) lists the main documents that are focused on the hardware or contain references to hardware features.

<span id="page-4-1"></span>Table 1. Hardware References and Feature Documentation

| Document<br>Category                | Document Name for Jetson<br>Orin<br>NX or Orin Nano<br>Designs                            | Description                                                                                                                                      |
|-------------------------------------|-------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------|
| Data sheet                          | Jetson Orin NX Series Module Data<br>Sheet, Jetson Orin Nano Series<br>Module Data Sheet. | > Module overview<br>> Power and system management<br>> Interface and signal description<br>> Electrical, package, and thermal<br>specifications |
| Technical Reference<br>Manual (TRM) | Orin (SoC) Technical Reference<br>Manual                                                  | > Address map<br>> Chapters per block (functional description,<br>programming guidelines, and registers)                                         |
| Product design guide                | Jetson Orin NX Series and Jetson<br>Orin Nano Series Design Guide                         | > Power<br>> Interface chapters (connection figures<br>and tables, and routing guidelines)                                                       |

| Document<br>Category           | Document Name for Jetson<br>Orin<br>NX or Orin Nano<br>Designs                 | Description                                                                                                                |
|--------------------------------|--------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------|
| Carrier board<br>specification | Jetson Orin Nano Developer Kit<br>Carrier Board Specification                  | > Developer Kit features and description<br>> Expansion connector and interface<br>descriptions<br>> Power allocation      |
| Pinmux                         | Jetson Orin NX Series and Jetson<br>Orin Nano Series Pinmux Config<br>Template | > Module pin name and number, SoC ball<br>name, Verilog ball name.<br>> SFIO and GPIO options<br>> Wakes, straps POR state |
| Design files                   | Jetson Orin Nano Developer Kit<br>Carrier Board Design Files                   | > Schematics, layout, bill of materials (BOM)<br>> Miscellaneous (Assy drawing, stack-up,<br>gerbers, and so on)           |

## <span id="page-6-0"></span>**Pin and Function Names**

There are different pin and interface names in many cases on the module compared to chip. Some documents are based on the chip, such as the TRM, while others are based on the module, or may have both chip and module terms and names. This can lead to confusion. It is important to use the right document and to understand whether a term or name is associated with a chip, module pin name or number, an interface name or instance, or a function name or instance.

<span id="page-6-2"></span>[Table 2](#page-6-2) shows what name forms are used in the various documents.

Table 2. Pin Name Usage

| Usage              | Verilog Name | SoC Ball Name | Module Pin Name  |
|--------------------|--------------|---------------|------------------|
| Usage in Documents | Pinmux       | Pinmux        | Pinmux           |
|                    | TRM          | Design guide  | Data sheet       |
|                    |              |               | Design guide     |
|                    |              |               | Reference design |

## <span id="page-6-1"></span>Pinmux

The Jetson Orin NX Series and Jetson Orin Nano Series Pinmux Config Template spread sheet has the module pin names and pin numbers in the first two columns. The SFIO functions are shown in the Function column. The portion of the pinmux in [Table 3](#page-6-3) includes one of the I2S interfaces.

<span id="page-6-3"></span>Table 3. Pinmux I2S1

| Jetson Orin<br>NX / Orin Nano<br>SODIMM<br>Connector |             | Pad<br>information | POR       | Function       |
|------------------------------------------------------|-------------|--------------------|-----------|----------------|
| Pin #                                                | Signal Name | Pull<br>Strength   | Pin State | Customer Usage |
| 226                                                  | I2S1_CLK    | 50k                | pd        | I2S4_SCLK      |
| 220                                                  | I2S1_SDOUT  | 50k                | pd        | I2S4_SDATA_OUT |
| 222                                                  | I2S1_SDIN   | 50k                | pd        | I2S4_SDATA_IN  |
| 224                                                  | I2S1_FS     | 50k                | pd        | I2S4_LRCK      |

In the case shown in Table 3, for one of the I2S interfaces that are available on the module pins, the following pin and function names exist:

- > Module signal names: I2S1\_xxx
- > Customer Usage (w/I2S4 pins functions selected): I2S4\_xxx

This shows that the module pin names, and function names can be different. When referring to the various documents, it is important to understand which name form is applicable. For instance, if the TRM is accessed for information on how to configure the pins or functions, it is necessary to know that the TRM is chip focused. It contains SoC Verilog ball names when referring to the pins, such as in the "Pinmux Register" section, or function names (Customer Usage column of Pinmux) if the function is being configured. In the case of the module data sheet, the module pin names are relevant. See Section: [Data Sheet](#page-7-0) and Section: [Technical Reference Manual](#page-8-0) for details.

[Figure: A simple, empty speech bubble with a black outline and a white interior.]

**Note:** The Jetson Orin NX series and Jetson Orin Nano Series Pinmux spread sheet does not show the columns with the Verilog or SoC ball names. These are hidden (in columns D and E). This information is shown in the Pin Description spread sheet that is attached to the Jetson Orin NX series and Jetson Orin Nano Series Product Design Guide.

## <span id="page-7-0"></span>Data Sheet

The module data sheet only uses the module pin names. If a programmer needed to know what SoC function to configure, it would be necessary to look at either the pinmux spread sheet or OEM product design guide to know what SoC function is associated with that module pin.

<span id="page-7-1"></span>Table 4. Data Sheet I2S1 Pin Descriptions

| Pin # | Signal    | Usage<br>and Description          | Direction | Pin Type    |
|-------|-----------|-----------------------------------|-----------|-------------|
| 226   | I2S1_SCLK | I2S Audio Port 1 Clock            | Bidir     | CMOS – 1.8V |
| 224   | I2S1_FS   | I2S Audio Port 1 Left/Right Clock | Bidir     | CMOS – 1.8V |
| 220   | I2S1_DOUT | I2S Audio Port 1 Data Out         | Output    | CMOS – 1.8V |
| 222   | I2S1_DIN  | I2S Audio Port 1 Data In          | Input     | CMOS – 1.8V |

## <span id="page-8-0"></span>Technical Reference Manual

The Technical Reference Manual (TRM) is based on the chip (for example, SoC Orin). References to pin names (such as DAP4\_SCLK) will be Verilog ball names. The TRM also has references to functions (such as I2S1). These should match the names of functions in the pinmux spreadsheet or design guide. To know what pin on the module an SoC pin is associated with, the Pin Description spreadsheet, which is attached to the Design Guide is the best cross reference since it includes the module, SoC Verilog, and SoC package ball names.

The following example shows a portion of the pad control for the module I2S1\_CLK (Verilog ball name DAP4\_SCLK).

#### <span id="page-8-1"></span>Figure 1. Pad Control for I2S1\_CLK

| 1:0 | 12S4 | PM:<br>0 = I2S4<br>1 = RSVD1<br>2 = RSVD2 |
|-----|------|-------------------------------------------|
|     |      | 3 = RSVD3                                 |

## <span id="page-9-0"></span>Design Guide

The design guide focuses on the module, but many of the figures and pin description tables also include the SoC signal (package ball name) associated with a module pin where applicable. The partial table [\(Table 4\)](#page-7-1) contains the same I2S interface used as the example in the earlier sections. Both the module (Jetson Orin NX / Orin Nano) and SoC pin names are shown.

<span id="page-9-2"></span>Table 5. Design Guide Audio I2S and MCLK Pin Descriptions

| Pin # | Module Pin<br>Name | SoC Signal      | Usage<br>and Description             | Direction | Pin Type |
|-------|--------------------|-----------------|--------------------------------------|-----------|----------|
| 226   | I2S1_SCLK          | GP206_DAP4_CLK  | I2S Audio Port 1 Clock               | Bidir     |          |
| 224   | I2S1_FS            | GP209_DAP4_FS   | I2S Audio Port 1 Left/Right<br>Clock | Bidir     | CMOS –   |
| 220   | I2S1_DOUT          | GP207_DAP4_DOUT | I2S Audio Port 1 Data Out            | Output    | 1.8V     |
| 222   | I2S1_DIN           | GP208_DAP4_DIN  | I2S Audio Port 1 Data In             | Input     |          |

[Table 6](#page-9-3) is an audio signal connections table, which contains only the module pin names, or function names in parentheses, if necessary, for clarity.

<span id="page-9-3"></span>Table 6. Design Guide Audio I2S and MCLK Signal Connections

| Module Pin Name<br>(SoC Function) | Type | Termination | Description                                                                              |
|-----------------------------------|------|-------------|------------------------------------------------------------------------------------------|
| I2S[1:0]_SCLK                     | I/O  |             | I2S Serial Clock: Connect to I2S/PCM CLK<br>pin of audio device.                         |
| I2S[1:0]_FS                       | I/O  |             | I2S Frame Select (Left/Right Clock):<br>Connect to corresponding pin of audio<br>device. |
| I2S[1:0]_DOUT                     | I/O  |             | I2S Data Output: Connect to data input pin<br>of audio device.                           |
| I2S[1:0]_DIN                      | I    |             | I2S Data Input: Connect to data output pin<br>of audio device.                           |

### <span id="page-9-1"></span>Pin Description Spreadsheet

The Jetson Orin NX and Orin Nano Pin Description spreadsheet is attached to the design guide. This document provides more details for each pin. The spreadsheet can be sorted by pin number or by function. Below is the I2S1 section of the spreadsheet sorted by function.

#### <span id="page-10-0"></span>Table 7. Pin Description Spreadsheet (I2S1 Rows)

| Pin# | Orin Module<br>Pin Name | Orin Module Function<br>(Where different than<br>Module Pin Name) | Orin Pin Name   | Verilog Pin<br>Name | Function<br>#1 | Function<br>#2 | Usage/Description                 | Usage on Jetson Orin Nano<br>DevKit Carrier Board<br>(P3768) | Direction | Pin Type    | MPIO Pad<br>Code | Power-on<br>Reset<br>State |
|------|-------------------------|-------------------------------------------------------------------|-----------------|---------------------|----------------|----------------|-----------------------------------|--------------------------------------------------------------|-----------|-------------|------------------|----------------------------|
| 226  | I2S1_SCLK               |                                                                   | GP206_DAP4_CLK  | DAP4_SCLK           | I2S            | GPIO           | I2S Audio Port 1 Clock            | M.2 Key E                                                    | Bidir     | CMOS – 1.8V | ST               | pd                         |
| 224  | 12S1_FS                 |                                                                   | GP209_DAP4_FS   | DAP4_FS             | I2S            | GPIO           | I2S Audio Port 1 Left/Right Clock | M.2 Key E                                                    | Bidir     | CMOS - 1.8V | ST               | pd                         |
| 220  | I2S1_DOUT               |                                                                   | GP207_DAP4_DOUT | DAP4_DOUT           | I2S            | GPIO           | I2S Audio Port 1 Data Out         | M.2 Key E                                                    | Bidir     | CMOS - 1.8V | ST               | pd                         |
| 222  | I2S1_DIN                |                                                                   | GP208_DAP4_DIN  | DAP4_DIN            | I2S            | GPIO           | I2S Audio Port 1 Data In          | M.2 Key E                                                    | Bidir     | CMOS – 1.8V | ST               | pd                         |

## <span id="page-11-0"></span>Reference Design Files

The reference design files (schematics, layout, and so on) also contain only module pin names and net names. Look to the pinmux or design guide if it is necessary to know which chip pin is associated with a module pin name.

<span id="page-11-1"></span>Figure 2. Design Schematics

| Г | IN   | 12S1_SDOUT | 14 $^{\circ}$ | AP PCM OUT/12S SD OUT |
|---|------|------------|---------------|-----------------------|
| _ | DUT  | I2S1_SDIN  | 12            | AP PCM IN/12S SD IN   |
|   | IN > | I2S1_LRCK  | 10            | PCM SYNC/12S WS       |
| _ | IN   | I2S1_SCLK  | 8             | PCM_CLK/12S SCK       |
| ш | IIV  | SNN LED1 L | 6 ~           | TCM_CENTIZE SCR       |
|   |      |            |               |                       |

# <span id="page-12-0"></span>**Chip, Module, and Carrier Board Pin Name and Numbers**

The information provided in the following table can be found in various hardware documentation (as described within this application note). [Table 8](#page-12-1) provides a consolidation of this information for your convenience.

<span id="page-12-1"></span>Table 8. Chip, Module, and Carrier Board Pinout

| Conn.<br>Pin # | Carrier Board<br>Symbol Pin Name | Carrier Board<br>Net Name | SoC Pin Name  |
|----------------|----------------------------------|---------------------------|---------------|
| 1              | GND                              | GND                       | −             |
| 2              | GND                              | GND                       | −             |
| 3              | CSI1_D0_N                        | CSI1_D0_N                 | HS_CSI1_D0_N  |
| 4              | CSI0_D0_N                        | CSI0_D0_N                 | HS_CSI0_D0_N  |
| 5              | CSI1_D0_P                        | CSI1_D0_P                 | HS_CSI1_D0_P  |
| 6              | CSI0_D0_P                        | CSI0_D0_P                 | HS_CSI0_D0_P  |
| 7              | GND                              | GND                       | −             |
| 8              | GND                              | GND                       | −             |
| 9              | RSVD (CSI1_CLK_N)                | CSI1_CLK_N                | HS_CSI1_CLK_N |
| 10             | CSI0_CLK_N                       | CSI0_CLK_N                | HS_CSI0_CLK_N |
| 11             | RSVD (CSI1_CLK_P)                | CSI1_CLK_P                | HS_CSI1_CLK_P |
| 12             | CSI0_CLK_P                       | CSI0_CLK_P                | HS_CSI0_CLK_P |
| 13             | GND                              | GND                       | −             |
| 14             | GND                              | GND                       | −             |
| 15             | CSI1_D1_N                        | CSI1_D1_N                 | HS_CSI1_D1_N  |
| 16             | CSI0_D1_N                        | CSI0_D1_N                 | HS_CSI0_D1_N  |
| 17             | CSI1_D1_P                        | CSI1_D1_P                 | HS_CSI1_D1_P  |
| 18             | CSI0_D1_P                        | CSI0_D1_P                 | HS_CSI0_D1_P  |
| 19             | GND                              | GND                       | −             |
| 20             | GND                              | GND                       | −             |
| 21             | CSI3_D0_N                        | CSI3_D0_N                 | HS_CSI3_D0_N  |

| Conn.<br>Pin # | Carrier Board<br>Symbol Pin Name | Carrier Board<br>Net Name | SoC Pin Name     |
|----------------|----------------------------------|---------------------------|------------------|
| 22             | CSI2_D0_N                        | CSI2_D0_N                 | HS_CSI2_D0_N     |
| 23             | CSI3_D0_P                        | CSI3_D0_P                 | HS_CSI3_D0_P     |
| 24             | CSI2_D0_P                        | CSI2_D0_P                 | HS_CSI2_D0_P     |
| 25             | GND                              | GND                       | −                |
| 26             | GND                              | GND                       | −                |
| 27             | CSI3_CLK_N                       | CSI3_CLK_N                | HS_CSI3_CLK_N    |
| 28             | CSI2_CLK_N                       | CSI2_CLK_N                | HS_CSI2_CLK_N    |
| 29             | CSI3_CLK_P                       | CSI3_CLK_P                | HS_CSI3_CLK_P    |
| 30             | CSI2_CLK_P                       | CSI2_CLK_P                | HS_CSI2_CLK_P    |
| 31             | GND                              | GND                       | −                |
| 32             | GND                              | GND                       | −                |
| 33             | CSI3_D1_N                        | CSI3_D1_N                 | HS_CSI3_D1_N     |
| 34             | CSI2_D1_N                        | CSI2_D1_N                 | HS_CSI2_D1_N     |
| 35             | CSI3_D1_P                        | CSI3_D1_P                 | HS_CSI3_D1_P     |
| 36             | CSI2_D1_P                        | CSI2_D1_P                 | HS_CSI2_D1_P     |
| 37             | GND                              | GND                       | −                |
| 38             | GND                              | GND                       | −                |
| 39             | DP0_TXD0_N<br>(USBSS1_RX_N)      | USBSS1_RX_N               | HS_UPHY0_L1_RX_N |
| 40             | CSI4_D2_N (PCIE2_RX0_N)          | PCIE2_RX0_N               | HS_UPHY2_L0_RX_N |
| 41             | DP0_TXD0_P<br>(USBSS1_RX_P)      | USBSS1_RX_P               | HS_UPHY0_L1_RX_P |
| 42             | CSI4_D2_P (PCIE2_RX0_P)          | PCIE2_RX0_P               | HS_UPHY2_L0_RX_P |
| 43             | GND                              | GND                       | −                |
| 44             | GND                              | GND                       | −                |
| 45             | DP0_TXD1_N<br>(USBSS1_TX_N)      | USBSS1_TX_N               | HS_UPHY0_L1_TX_N |
| 46             | CSI4_D0_N (PCIE2_TX0_N)          | PCIE2_TX0_N               | HS_UPHY2_L0_TX_N |
| 47             | DP0_TXD1_P (USBSS1_TX_P)         | USBSS1_TX_P               | HS_UPHY0_L1_TX_P |
| 48             | CSI4_D0_P (PCIE2_TX0_P)          | PCIE2_TX0_P               | HS_UPHY2_L0_TX_P |
| 49             | GND                              | GND                       | −                |
| 50             | GND                              | GND                       | −                |
| 51             | DP0_TXD2_N<br>(USBSS2_RX_N)      | USBSS2_RX_N               | HS_UPHY0_L2_RX_N |
| 52             | CSI4_CLK_N (PCIE2_CLK_N)         | PCIE2_CLK_N               | SF_PCIE7_CLK_N   |
| 53             | DP0_TXD2_P<br>(USBSS2_RX_P)      | USBSS2_RX_P               | HS_UPHY0_L2_RX_P |
| 54             | CSI4_CLK_P (PCIE2_CLK_P)         | PCIE2_CLK_P               | SF_PCIE7_CLK_P   |

| Conn.<br>Pin # | Carrier Board<br>Symbol Pin Name | Carrier Board<br>Net Name | SoC Pin Name           |
|----------------|----------------------------------|---------------------------|------------------------|
| 55             | GND                              | GND                       | −                      |
| 56             | GND                              | GND                       | −                      |
| 57             | DP0_TXD3_N<br>(USBSS2_TX_N)      | USBSS2_TX_N               | HS_UPHY0_L2_TX_N       |
| 58             | CSI4_D1_N (PCIE2_RX1_N)          | PCIE2_RX1_N               | HS_UPHY2_L1_RX_N       |
| 59             | DP0_TXD3_P (USBSS2_TX_P)         | USBSS2_TX_P               | HS_UPHY0_L2_TX_P       |
| 60             | CSI4_D1_P (PCIE2_RX1_P)          | PCIE2_RX1_P               | HS_UPHY2_L1_RX_P       |
| 61             | GND                              | GND                       | −                      |
| 62             | GND                              | GND                       | −                      |
| 63             | DP1_TXD0_N<br>(HDMI_TXD2_N)      | DP1_TXD0_N                | HS_DISP0_HDMI_D2_DP0_N |
| 64             | CSI4_D3_N (PCIE2_TX1_N)          | PCIE2_TX1_N               | HS_UPHY2_L1_TX_N       |
| 65             | DP1_TXD0_P<br>(HDMI_TXD2_P)      | DP1_TXD0_P                | HS_DISP0_HDMI_D2_DP0_P |
| 66             | CSI4_D3_P (PCIE2_TX1_P)          | PCIE2_TX1_P               | HS_UPHY2_L1_TX_P       |
| 67             | GND                              | GND                       | −                      |
| 68             | GND                              | GND                       | −                      |
| 69             | DP1_TXD1_N<br>(HDMI_TXD1_N)      | DP1_TXD1_N                | HS_DISP0_HDMI_D1_DP1_N |
| 70             | DSI_D0_N (RSVD)                  | −                         | −                      |
| 71             | DP1_TXD1_P<br>(HDMI_TXD1_P)      | DP1_TXD1_P                | HS_DISP0_HDMI_D1_DP1_P |
| 72             | DSI_D0_P (RSVD)                  | −                         | −                      |
| 73             | GND                              | GND                       | −                      |
| 74             | GND                              | GND                       | −                      |
| 75             | DP1_TXD2_N<br>(HDMI_TXD0_N)      | DP1_TXD2_N                | HS_DISP0_HDMI_D0_DP2_N |
| 76             | DSI_CLK_N (RSVD)                 | −                         | −                      |
| 77             | DP1_TXD2_P<br>(HDMI_TXD0_P)      | DP1_TXD2_P                | HS_DISP0_HDMI_D0_DP2_P |
| 78             | DSI_CLK_P (RSVD)                 | −                         | −                      |
| 79             | GND                              | GND                       | −                      |
| 80             | GND                              | GND                       | −                      |
| 81             | DP1_TXD3_N (HDMI_TXC_N)          | DP1_TXD3_N                | HS_DISP0_HDMI_CK_DP3_N |
| 82             | DSI_D1_N (RSVD)                  | −                         | −                      |
| 83             | DP1_TXD3_P (HDMI_TXC_P)          | DP1_TXD3_P                | HS_DISP0_HDMI_CK_DP3_P |
| 84             | DSI_D1_P (RSVD)                  | −                         | −                      |
| 85             | GND                              | GND                       | −                      |
| 86             | GND                              | GND                       | −                      |

| Conn.<br>Pin # | Carrier Board<br>Symbol Pin Name | Carrier Board<br>Net Name | SoC Pin Name      |
|----------------|----------------------------------|---------------------------|-------------------|
| 87             | GPIO00 (USB_VBUS_EN0)            | USB_VBUS_EN0              | GP45_USB_VBUS_EN0 |
| 88             | DP0_HPD (RSVD)                   | −                         | −                 |
| 89             | SPI0_MOSI                        | SPI0_MOSI                 | GP49_SPI1_MOSI    |
| 90             | DP0_AUX_N (RSVD)                 | −                         | −                 |
| 91             | SPI0_SCK                         | SPI0_SCK                  | GP47_SPI1_CLK     |
| 92             | DP0_AUX_P (RSVD)                 | −                         | −                 |
| 93             | SPI0_MISO                        | SPI0_MISO                 | GP48_SPI1_MISO    |
| 94             | HDMI_CEC                         | HDMI_CEC                  | GP05_HDMI_CEC     |
| 95             | SPI0_CS0*                        | SPI0_CS0*                 | GP50_SPI1_CS0_N   |
| 96             | DP1_HPD (HDMI_HPD)               | DP1_HPD                   | GP74_HPD0_N       |
| 97             | SPI0_CS1*                        | SPI0_CS1*                 | GP51_SPI1_CS1_N   |
| 98             | DP1_AUX_N<br>(HDMI_DDC_SDA)      | DP1_AUX_N                 | SF_DPAUX01_N      |
| 99             | UART0_TXD                        | UART0_TXD                 | GP32_UART2_TXD    |
| 100            | DP1_AUX_P<br>(HDMI_DDC_SCL)      | DP1_AUX_P                 | SF_DPAUX01_P      |
| 101            | UART0_RXD                        | UART0_RXD                 | GP33_UART2_RXD    |
| 102            | GND                              | GND                       | −                 |
| 103            | UART0_RTS*                       | UART0_RTS*                | GP34_UART2_RTS_N  |
| 104            | SPI1_MOSI                        | SPI1_MOSI                 | GP38_SPI3_MOSI    |
| 105            | UART0_CTS*                       | UART0_CTS*                | GP35_UART2_CTS_N  |
| 106            | SPI1_SCK                         | SPI1_SCK                  | GP36_SPI3_CLK     |
| 107            | GND                              | GND                       | −                 |
| 108            | SPI1_MISO                        | SPI1_MISO                 | GP37_SPI3_MISO    |
| 109            | USB0_D_N                         | USB0_AP_N                 | HS_USB0_P0_N      |
| 110            | SPI1_CS0*                        | SPI1_CS0*                 | GP39_SPI3_CS0_N   |
| 111            | USB0_D_P                         | USB0_AP_P                 | HS_USB0_P0_P      |
| 112            | SPI1_CS1*                        | SPI1_CS1*                 | GP40_SPI3_CS1_N   |
| 113            | GND                              | GND                       | −                 |
| 114            | CAM0_PWDN                        | CAM0_PWDN                 | GP121_UART4_CTS_N |
| 115            | USB1_D_N                         | USB1_AP_N                 | HS_USB0_P1_N      |
| 116            | CAM0_MCLK                        | CAM0_MCLK                 | GP52_CLK1         |
| 117            | USB1_D_P                         | USB1_AP_P                 | HS_USB0_P1_P      |
| 118            | GPIO01 (CLK)                     | GPIO01                    | GP65              |
| 119            | GND                              | GND                       | −                 |
| 120            | CAM1_PWDN                        | CAM1_PWDN                 | GP161_SPI5_CLK    |
| 121            | USB2_D_N                         | USB2_AP_N                 | HS_USB0_P2_N      |

| Conn.<br>Pin # | Carrier Board<br>Symbol Pin Name | Carrier Board<br>Net Name | SoC Pin Name     |
|----------------|----------------------------------|---------------------------|------------------|
| 122            | CAM1_MCLK                        | CAM1_MCLK                 | GP53_CLK2        |
| 123            | USB2_D_P                         | USB2_AP_P                 | HS_USB0_P2_P     |
| 124            | GPIO02                           | BT_M2_WAKE_AP             | GP58             |
| 125            | GND                              | GND                       | −                |
| 126            | GPIO03                           | BT_M2_EN                  | GP06_SPI2_CLK    |
| 127            | GPIO04                           | PWR_LED_CTRL              | GP07_SPI2_MISO   |
| 128            | GPIO05                           | W_DISABLE1_CTRL           | GP08_SPI2_MOSI   |
| 129            | GND                              | GND                       | −                |
| 130            | GPIO06                           | CAM_MUX_SEL               | GP09_SPI2_CS_N   |
| 131            | PCIE0_RX0_N                      | PCIE0_RX0_N               | HS_UPHY0_L4_RX_N |
| 132            | GND                              | GND                       | −                |
| 133            | PCIE0_RX0_P                      | PCIE0_RX0_P               | HS_UPHY0_L4_RX_P |
| 134            | PCIE0_TX0_N                      | PCIE0_TX0_N               | HS_UPHY0_L4_TX_N |
| 135            | GND                              | GND                       | −                |
| 136            | PCIE0_TX0_P                      | PCIE0_TX0_P               | HS_UPHY0_L4_TX_P |
| 137            | PCIE0_RX1_N                      | PCIE0_RX1_N               | HS_UPHY0_L5_RX_N |
| 138            | GND                              | GND                       | −                |
| 139            | PCIE0_RX1_P                      | PCIE0_RX1_P               | HS_UPHY0_L5_RX_P |
| 140            | PCIE0_TX1_N                      | PCIE0_TX1_N               | HS_UPHY0_L5_TX_N |
| 141            | GND                              | GND                       | −                |
| 142            | PCIE0_TX1_P                      | PCIE0_TX1_P               | HS_UPHY0_L5_TX_P |
| 143            | RSVD (CAN_RX)                    | CAN_RX                    | GP18_CAN0_DIN    |
| 144            | GND                              | GND                       | −                |
| 145            | RSVD (CAN_TX)                    | CAN_TX                    | GP17_CAN0_DOUT   |
| 146            | GND                              | GND                       | −                |
| 147            | GND                              | GND                       | −                |
| 148            | PCIE0_TX2_N                      | PCIE0_TX2_N               | HS_UPHY0_L6_TX_N |
| 149            | PCIE0_RX2_N                      | PCIE0_RX2_N               | HS_UPHY0_L6_RX_N |
| 150            | PCIE0_TX2_P                      | PCIE0_TX2_P               | HS_UPHY0_L6_TX_P |
| 151            | PCIE0_RX2_P                      | PCIE0_RX2_P               | HS_UPHY0_L6_RX_P |
| 152            | GND                              | GND                       | −                |
| 153            | GND                              | GND                       | −                |
| 154            | PCIE0_TX3_N                      | PCIE0_TX3_N               | HS_UPHY0_L7_TX_N |
| 155            | PCIE0_RX3_N                      | PCIE0_RX3_N               | HS_UPHY0_L7_RX_N |
| 156            | PCIE0_TX3_P                      | PCIE0_TX3_P               | HS_UPHY0_L7_TX_P |
| 157            | PCIE0_RX3_P                      | PCIE0_RX3_P               | HS_UPHY0_L7_RX_P |
| 158            | GND                              | GND                       | −                |

| Conn.<br>Pin # | Carrier Board<br>Symbol Pin Name | Carrier Board<br>Net Name | SoC Pin Name                             |
|----------------|----------------------------------|---------------------------|------------------------------------------|
| 159            | GND                              | GND                       | −                                        |
| 160            | PCIE0_CLK_N                      | PCIE0_CLK_N               | SF_PCIE4_CLK_N and<br>HS_UPHY0_REFCLK1_N |
| 161            | USBSS0_RX_N                      | USBSS0_RX_N               | HS_UPHY0_L0_RX_N                         |
| 162            | PCIE0_CLK_P                      | PCIE0_CLK_P               | SF_PCIE4_CLK_P and<br>HS_UPHY0_REFCLK1_P |
| 163            | USBSS0_RX_P                      | USBSS0_RX_P               | HS_UPHY0_L0_RX_P                         |
| 164            | GND                              | GND                       | −                                        |
| 165            | GND                              | GND                       | −                                        |
| 166            | USBSS0_TX_N                      | USBSS0_TX_N               | HS_UPHY0_L0_TX_N                         |
| 167            | PCIE1_RX0_N                      | PCIE1_RX0_N               | HS_UPHY0_L3_RX_N                         |
| 168            | USBSS0_TX_P                      | USBSS0_TX_P               | HS_UPHY0_L0_TX_P                         |
| 169            | PCIE1_RX0_P                      | PCIE1_RX0_P               | HS_UPHY0_L3_RX_P                         |
| 170            | GND                              | GND                       | −                                        |
| 171            | GND                              | GND                       | −                                        |
| 172            | PCIE1_TX0_N                      | PCIE1_TX0_N               | HS_UPHY0_L3_TX_N                         |
| 173            | PCIE1_CLK_N                      | PCIE1_CLK_N               | SF_PCIE1_CLK_N                           |
| 174            | PCIE1_TX0_P                      | PCIE1_TX0_P               | HS_UPHY0_L3_TX_P                         |
| 175            | PCIE1_CLK_P                      | PCIE1_CLK_P               | SF_PCIE1_CLK_P                           |
| 176            | GND                              | GND                       | −                                        |
| 177            | GND                              | GND                       | −                                        |
| 178            | MOD_SLEEP*                       | MOD_SLEEP*                | SF_PWR_SOC_EN                            |
| 179            | PCIE_WAKE*                       | PCIE_WAKE*                | GP185_PCIE_WAKE_N                        |
| 180            | PCIE0_CLKREQ*                    | PCIE0_CLKREQ*             | GP183_PCIE4_CLKREQ_N                     |
| 181            | PCIE0_RST*                       | PCIE0_RST*                | GP184_PCIE4_RST_N                        |
| 182            | PCIE1_CLKREQ*                    | PCIE1_CLKREQ*             | GP177_PCIE1_CLKREQ_N                     |
| 183            | PCIE1_RST*                       | PCIE1_RST*                | GP178_PCIE1_RST_N                        |
| 184            | GBE_MDI0_N                       | GBE_MDI0_N                | −                                        |
| 185            | I2C0_SCL                         | ID_I2C_SCL                | GP13_I2C2_CLK                            |
| 186            | GBE_MDI0_P                       | GBE_MDI0_P                | −                                        |
| 187            | I2C0_SDA                         | ID_I2C_SDA                | GP14_I2C2_DAT                            |
| 188            | GBE_LED_LINK                     | GBE_LED_LINK              | −                                        |
| 189            | I2C1_SCL                         | I2C1_SCL                  | GP15_I2C8_CLK                            |
| 190            | GBE_MDI1_N                       | GBE_MDI1_N                | −                                        |
| 191            | I2C1_SDA                         | I2C1_SDA                  | GP16_I2C8_DAT                            |
| 192            | GBE_MDI1_P                       | GBE_MDI1_P                | −                                        |
| 193            | I2S0_DOUT                        | I2S0_SDOUT                | GP123                                    |

| Conn.<br>Pin # | Carrier Board<br>Symbol Pin Name | Carrier Board<br>Net Name | SoC Pin Name               |
|----------------|----------------------------------|---------------------------|----------------------------|
| 194            | GBE_LED_ACT                      | GBE_LED_ACT               | −                          |
| 195            | I2S0_DIN                         | I2S0_SDIN                 | GP124                      |
| 196            | GBE_MDI2_N                       | GBE_MDI2_N                | −                          |
| 197            | I2S0_FS                          | I2S0_LRCK                 | GP125                      |
| 198            | GBE_MDI2_P                       | GBE_MDI2_P                | −                          |
| 199            | I2S0_SCLK                        | I2S0_SCLK                 | GP122                      |
| 200            | GND                              | GND                       | −                          |
| 201            | GND                              | GND                       | −                          |
| 202            | GBE_MDI3_N                       | GBE_MDI3_N                | −                          |
| 203            | UART1_TXD                        | UART1_TXD                 | GP70_UART1_TXD_BOOT2_STRAP |
| 204            | GBE_MDI3_P                       | GBE_MDI3_P                | −                          |
| 205            | UART1_RXD                        | UART1_RXD                 | GP71_UART1_RXD             |
| 206            | GPIO07 (PWM)                     | GPIO07                    | GP113_PWM7                 |
| 207            | UART1_RTS*                       | UART1_RTS*                | GP72_UART1_RTS_N           |
| 208            | GPIO08                           | FAN_TACH                  | GP62                       |
| 209            | UART1_CTS*                       | UART1_CTS*                | GP73_UART1_CTS_N           |
| 210            | CLK_32K_OUT                      | SUSCLK_32KHZ              | SF_CLK32K                  |
| 211            | GPIO09 (AUD_MCLK)                | GPIO09                    | GP167                      |
| 212            | GPIO10                           | M2_ALERT*                 | GP02                       |
| 213            | CAM_I2C_SCL                      | CAM_I2C_SCL               | GP54_I2C3_CLK              |
| 214            | FORCE_RECOVERY*                  | FORCE_RECOVERY*           | GP107_RECOVERY0_STRAP      |
| 215            | CAM_I2C_SDA                      | CAM_I2C_SDA               | GP55_I2C3_DAT              |
| 216            | GPIO11 (CLK)                     | GPIO11                    | GP66                       |
| 217            | MODULE_ID                        | MODULE_ID                 | −                          |
| 218            | GPIO12                           | GPIO12                    | GP88_PWM1                  |
| 219            | SDMMC_DAT0 (PCIE2_RST)           | PCIE2_RST                 | GP188_PCIE7_RST_N          |
| 220            | I2S1_DOUT                        | I2S1_SDOUT                | GP207_DAP4_DOUT            |
| 221            | SDMMC_DAT1<br>(PCIE2_CLKREQ)     | PCIE2_CLKREQ              | GP187_PCIE7_CLKREQ_N       |
| 222            | I2S1_DIN                         | I2S1_SDIN                 | GP208_DAP4_DIN             |
| 223            | SDMMC_DAT2 (PCIE3_RST)           | PCIE3_RST                 | GP192_PCIE9_RST_N          |
| 224            | I2S1_FS                          | I2S1_LRCK                 | GP209_DAP4_FS              |
| 225            | SDMMC_DAT3<br>(PCIE3_CLKREQ)     | PCIE3_CLKREQ              | GP191_PCIE9_CLKREQ_N       |
| 226            | I2S1_SCLK                        | I2S1_SCLK                 | GP206_DAP4_CLK             |
| 227            | SDMMC_CMD<br>(PCIE3_CLK_N)       | PCIE3_CLK_N               | SF_PCIE9_CLK_N             |
| 228            | GPIO13 (PWM)                     | GPIO13                    | GP115                      |

| Conn.<br>Pin # | Carrier Board<br>Symbol Pin Name | Carrier Board<br>Net Name | SoC Pin Name                             |
|----------------|----------------------------------|---------------------------|------------------------------------------|
| 229            | SDMMC_CLK (PCIE3_CLK_P)          | PCIE3_CLK_P               | SF_PCIE9_CLK_P                           |
| 230            | GPIO14 (PWM)                     | FAN_PWM                   | GP31_PWM3                                |
| 231            | GND                              | GND                       | −                                        |
| 232            | I2C2_SCL                         | I2C2_SCL                  | GP126_I2C1_CLK                           |
| 233            | SHUTDOWN_REQ*                    | SHUTDOWN_REQ*             | −                                        |
| 234            | I2C2_SDA                         | I2C2_SDA                  | GP127_I2C1_DAT                           |
| 235            | PMIC_BBAT                        | BBAT                      | (PMIC BBATT)                             |
| 236            | UART2_TXD (DEBUG)                | UART2_TXD                 | GP11_UART3_TXD                           |
| 237            | POWER_EN                         | POWER_EN                  | (PMIC EN0)                               |
| 238            | UART2_RXD (DEBUG)                | UART2_RXD                 | GP12_UART3_RXD                           |
| 239            | SYS_RESET*                       | SYS_RST*                  | (PMIC output) SF_RST_N (via AND<br>gate) |
| 240            | SLEEP/WAKE*                      | PWR_BTN*                  | GP04                                     |
| 241            | GND                              | GND                       | −                                        |
| 242            | GND                              | GND                       | −                                        |
| 243            | GND                              | GND                       | −                                        |
| 244            | GND                              | GND                       | −                                        |
| 245            | GND                              | GND                       | −                                        |
| 246            | GND                              | GND                       | −                                        |
| 247            | GND                              | GND                       | −                                        |
| 248            | GND                              | GND                       | −                                        |
| 249            | GND                              | GND                       | −                                        |
| 250            | GND                              | GND                       | −                                        |
| 251            | VDD_IN                           | VDD_CVM                   | −                                        |
| 252            | VDD_IN                           | VDD_CVM                   | −                                        |
| 253            | VDD_IN                           | VDD_CVM                   | −                                        |
| 254            | VDD_IN                           | VDD_CVM                   | −                                        |
| 255            | VDD_IN                           | VDD_CVM                   | −                                        |
| 256            | VDD_IN                           | VDD_CVM                   | −                                        |
| 257            | VDD_IN                           | VDD_CVM                   | −                                        |
| 258            | VDD_IN                           | VDD_CVM                   | −                                        |
| 259            | VDD_IN                           | VDD_CVM                   | −                                        |

#### **Notice**

This document is provided for information purposes only and shall not be regarded as a warranty of a certain functionality, condition, or quality of a product. NVIDIA Corporation ("NVIDIA") makes no representations or warranties, expressed or implied, as to the accuracy or completeness of the information contained in this document and assumes no responsibility for any errors contained herein. NVIDIA shall have no liability for the consequences or use of such information or for any infringement of patents or other rights of third parties that may result from its use. This document is not a commitment to develop, release, or deliver any Material (defined below), code, or functionality.

NVIDIA reserves the right to make corrections, modifications, enhancements, improvements, and any other changes to this document, at any time without notice.

Customer should obtain the latest relevant information before placing orders and should verify that such information is current and complete.

NVIDIA products are sold subject to the NVIDIA standard terms and conditions of sale supplied at the time of order acknowledgement, unless otherwise agreed in an individual sales agreement signed by authorized representatives of NVIDIA and customer ("Terms of Sale"). NVIDIA hereby expressly objects to applying any customer general terms and conditions with regards to the purchase of the NVIDIA product referenced in this document. No contractual obligations are formed either directly or indirectly by this document.

Unless specifically agreed to in writing by NVIDIA, NVIDIA products are not designed, authorized, or warranted to be suitable for use in medical, military, aircraft, space, or life support equipment, nor in applications where failure or malfunction of the NVIDIA product can reasonably be expected to result in personal injury, death, or property or environmental damage. NVIDIA accepts no liability for inclusion and/or use of NVIDIA products in such equipment or applications and therefore such inclusion and/or use is at customer's own risk.

NVIDIA makes no representation or warranty that products based on this document will be suitable for any specified use. Testing of all parameters of each product is not necessarily performed by NVIDIA. It is customer's sole responsibility to evaluate and determine the applicability of any information contained in this document, ensure the product is suitable and fit for the application planned by customer, and perform the necessary testing for the application in order to avoid a default of the application or the product. Weaknesses in customer's product designs may affect the quality and reliability of the NVIDIA product and may result in additional or different conditions and/or requirements beyond those contained in this document. NVIDIA accepts no liability related to any default, damage, costs, or problem which may be based on or attributable to: (i) the use of the NVIDIA product in any manner that is contrary to this document or (ii) customer product designs.

No license, either expressed or implied, is granted under any NVIDIA patent right, copyright, or other NVIDIA intellectual property right under this document. Information published by NVIDIA regarding third-party products or services does not constitute a license from NVIDIA to use such products or services or a warranty or endorsement thereof. Use of such information may require a license from a third party under the patents or other intellectual property rights of the third party, or a license from NVIDIA under the patents or other intellectual property rights of NVIDIA.

Reproduction of information in this document is permissible only if approved in advance by NVIDIA in writing, reproduced without alteration and in full compliance with all applicable export laws and regulations, and accompanied by all associated conditions, limitations, and notices.

THIS DOCUMENT AND ALL NVIDIA DESIGN SPECIFICATIONS, REFERENCE BOARDS, FILES, DRAWINGS, DIAGNOSTICS, LISTS, AND OTHER DOCUMENTS (TOGETHER AND SEPARATELY, "MATERIALS") ARE BEING PROVIDED "AS IS." NVIDIA MAKES NO WARRANTIES, EXPRESSED, IMPLIED, STATUTORY, OR OTHERWISE WITH RESPECT TO THE MATERIALS, AND EXPRESSLY DISCLAIMS ALL IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE. TO THE EXTENT NOT PROHIBITED BY LAW, IN NO EVENT WILL NVIDIA BE LIABLE FOR ANY DAMAGES, INCLUDING WITHOUT LIMITATION ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, HOWEVER CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY, ARISING OUT OF ANY USE OF THIS DOCUMENT, EVEN IF NVIDIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. Notwithstanding any damages that customer might incur for any reason whatsoever, NVIDIA's aggregate and cumulative liability towards customer for the products described herein shall be limited in accordance with the Terms of Sale for the product.

#### **Trademarks**

NVIDIA, the NVIDIA logo, Jetson, NVIDIA Jetson Orin, and NVIDIA Orin are trademarks and/or registered trademarks of NVIDIA Corporation in the U.S. and other countries. Other company and product names may be trademarks of the respective companies with which they are associated.

#### **HDMI**

HDMI, the HDMI logo, and High-Definition Multimedia Interface are trademarks or registered trademarks of HDMI Licensing LLC.

#### **Arm**

Arm, AMBA, and Arm Powered are registered trademarks of Arm Limited. Cortex, MPCore, and Mali are trademarks of Arm Limited. All other brands or product names are the property of their respective holders. ʺArmʺ is used to represent Arm Holdings plc; its operating company Arm Limited; and the regional subsidiaries Arm Inc.; Arm KK; Arm Korea Limited.; Arm Taiwan Limited; Arm France SAS; Arm Consulting (Shanghai) Co. Ltd.; Arm Germany GmbH; Arm Embedded Technologies Pvt. Ltd.; Arm Norway, AS, and Arm Sweden AB.

#### **Copyright**

© 2023 NVIDIA Corporation. All rights reserved.

[Figure: The NVIDIA logo is a green and white eye with a black border. The eye is composed of a green square with a white eye shape inside, and a white line that forms the eye's pupil. The eye is surrounded by a black border, and the word "NVIDIA" is written in black letters below the eye. The background is a light gray color.]
