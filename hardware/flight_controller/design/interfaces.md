# Flight Controller Interfaces

## Scope

Define the external interfaces for the flight-controller board and assign
ownership expectations for each link.

## Board-to-Board Interfaces

| Interface | Peer | Direction | Baseline Use | Status |
|---|---|---|---|---|
| I2C (`SCL`, `SDA`) | EPS | Bidirectional | Charger/housekeeping telemetry | In progress |
| SPI (`SCLK`, `MOSI`, `MISO`, `CS_N`) | Comms RP2040 | Bidirectional | Command/data exchange | Baseline planned |
| UART (`TX`, `RX`) | Ground/debug host | Bidirectional | Bring-up logs and diagnostics | Baseline planned |
| CAN (`CANH`, `CANL`) | Comms/payload nodes | Bidirectional | Control-plane messaging | Iteration 2 planned |

## Control and Fault Signals (Provisional)

| Signal | Direction | Purpose | Status |
|---|---|---|---|
| `COMMS_EN` | Out | Enable/disable comms board operation | Provisional |
| `COMMS_FAULT_N` | In | Comms fault indication to FC | Provisional |
| `EPS_ALERT_N` | In | EPS fault/alert line to FC | Provisional |
| `PAYLOAD_EN` | Out | Payload power/operation gating | Provisional |

## Timing and Throughput Targets (Provisional)

- I2C target: 400 kHz fast mode for housekeeping telemetry
- SPI target: 4 to 8 MHz initial operating range
- CAN target (Iteration 2): 500 kbps classic CAN 2.0B
- FC-comms heartbeat target: 100 ms nominal interval

## Ownership Rules

- FC is system command authority and state-machine owner
- Comms RP2040 owns RF framing/modulation and radio-local timing
- EPS telemetry source remains EPS-side hardware path, consumed by FC

## Interface Closure Checklist

- Final connector pin map and signal integrity constraints
- Pull-up/pull-down strategy and voltage-domain verification
- CRC and retry policy per transport
- Timeout behavior and degraded-mode actions per link

## Related Documents

- FC architecture: `hardware/flight_controller/design/overview.md`
- FC-comms details: `system/interfaces/comms_to_fc.md`
- Global bus strategy: `system/interfaces/board_to_board.md`
