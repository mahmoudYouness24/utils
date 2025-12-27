# Embedded Utilities

Reusable firmware utility modules designed for embedded systems and communication stacks.

This library consolidates common helpers used across RF and cellular projects, with a focus on
robustness, portability, and low memory footprint.

**Current Version:** v0.1.0

---

## Modules
- **utils_string** — safe string helpers to prevent overflows.
- **utils_buffer** — ring buffer for UART data buffering and response parsing.
- **utils_conversion** — data conversion helpers (hex/binary, string/numeric, IP address).
- **utils_memory** — safe memory operation wrappers with bounds checking.
- **utils_crc** — CRC and checksum utilities (CRC8/16/32, XOR, sum checksums).
- **utils_log** — configurable logging system with multiple levels and hex dump support.
- **utils_time** — timeout management, timers, and elapsed time tracking.
