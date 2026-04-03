# Communications to Flight Controller Interface

## Purpose

Define the interface between communications hardware and flight controller
logic.

## Controller Ownership

- Communications board hosts its own RP2040 for local TX/RX control and
  baseband handling.
- Flight controller hosts a separate RP2040 for system-level command authority,
  routing, and integration logic.
- The two controllers communicate bidirectionally over the interfaces defined
  below.

## Baseline Interface (Iteration 1)

- Primary physical link: SPI (FC master, comms slave)
- Data direction: bidirectional
- Nominal use: command exchange + telemetry/data transfer
- Debug link: UART during bring-up and integration

## Expanded Interface (Iteration 2)

- Add CAN control-plane messaging between FC and comms
- Keep SPI for bulk or timing-sensitive transfers
- CAN carries mode changes, heartbeat, fault/status, and queue state

## Provisional Signal Set

- SPI: `SCLK`, `MOSI`, `MISO`, `CS_N`, optional `IRQ_N`
- CAN: `CANH`, `CANL`, `GND`
- Optional control: `COMMS_EN`, `COMMS_FAULT_N`

## Provisional Timing and Throughput Targets

- SPI clock target: 4 MHz to 8 MHz initial range
- CAN rate target: 500 kbps (classic CAN)
- FC-comms heartbeat period: 100 ms nominal

## Fault Behavior

- Missing heartbeat timeout triggers comms link degraded state
- FC retries command transaction with bounded retry count
- On repeated failure, FC enters reduced service mode and logs fault

## Open Items

- Final SPI framing and CRC policy
- CAN message ID allocation for comms state and command ack
- Ownership of mode transitions when links disagree
