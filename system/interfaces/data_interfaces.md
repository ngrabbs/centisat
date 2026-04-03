# Data Interfaces

## Purpose

Define data interchange boundaries between flight controller, communications,
payload, and EPS telemetry paths.

## Baseline Data Flow

- Uplink command ingress: comms board receives and forwards to FC
- FC is command authority for routing/validation to EPS, payload, and comms
- Downlink telemetry originates from FC-assembled system state and payload data

## Transport Mapping (Provisional)

- FC <-> EPS housekeeping: I2C + optional fault GPIO
- FC <-> Comms data path: SPI
- FC <-> Comms/payload control plane (Iteration 2): CAN

## Packet Ownership

- FC owns system-level command validation and sequencing
- Comms owns RF framing/modulation implementation details
- EPS owns charger and rail health observability fields

## Buffering and Queue Guidelines (Provisional)

- FC command queue depth target: >= 16 entries
- FC outbound telemetry queue target: >= 32 frames
- Comms TX queue target: >= 16 frames with priority classes
- On overflow, drop lowest-priority telemetry first, never safety alerts

## Open Items

- Final packet schema and versioning strategy
- Priority map between operational and diagnostic traffic
- Cross-board timestamp source of truth
