# Roadmap: CAN gateway and PDU

## The target

Both products use the **same middle MCU** between the panel and the base:

```
 button panel (ASR + STM8 LED driver)        base board (power stage)
        |            |                              |
   2400 bus    115200 display link              2400 bus
        \            |                            /
         \           v                           /
          +------ middle MCU (RP2040/ESP32) -----+
                          |
                         CAN
```

The middle MCU is a **3-port bridge**:

| Port | Link | Direction |
|---|---|---|
| 1 | 2400 bus, panel → base | RX + TX (MITM) |
| 2 | 2400 bus, base → panel | RX + TX (MITM) |
| 3 | 115200 display, ASR → STM8 | RX + TX (override) |
| 4 | CAN | MCP2515 / CAN2040 / ESP32 TWAI |

Portability:

- **Feather RP2040**: two hardware UARTs + PIO for the third; CAN via MCP2515
  (SPI) or CAN2040 (PIO).
- **ESP32**: three hardware UARTs + TWAI. Easier for the CAN variant.

Keep the protocol/state logic portable; only the port layer is board-specific.

## Two firmware roles

- **Gateway**: pass-through/translate the stock link, read buttons, drive the
  base, optionally override the panel LEDs.
- **PDU**: same bridge, but the base runs our firmware and reports real output
  state; the bridge is the CAN authority.

## Phases

1. **Finish the base**
   - Flash the prescaler fix; re-test low PWM frequencies.
   - Implement the four stock modes (toggle / momentary / pulse / blinking).
   - Add a factual status frame (actual duty, ACC gating, faults).

2. **Prove full panel control**
   - Identify the ASR display UART pins by continuity from STM8 PD5/PD6.
   - Send 9-byte `0x5A` frames; map nibble → colour.
   - Ship a host tool + Feather injector.

3. **Gateway prototype**
   - 3-port MITM, pass-through first.
   - Button frames → host/CAN; CAN → `08 0C` / `07` / `09`.
   - LED override via the display link.

4. **CAN**
   - Add MCP2515 or CAN2040; test with a USB-CAN adapter or a second Feather.
   - Implement the CAN ID map.

5. **PDU variant**
   - Custom base firmware as the output authority.
   - Decide current sensing (stock board has none).
   - Same bridge, no pass-through.

6. **Publish**
   - Clean repo, dumps, decompilation, protocol, tools, wiring, safety.

## Proposed CAN IDs

| ID | Direction | Payload |
|---|---|---|
| `0x100` | panel/ECU → gateway | 8-button bitmask (mirrors `08 0C`) |
| `0x101` | panel/ECU → gateway | master power (mirrors `07 00/01`) |
| `0x110 + n` | ECU → PDU | channel n: mode, duty |
| `0x120` | ECU → PDU | status request |
| `0x121 + n` | PDU → ECU | channel n: actual state, duty, fault |
| `0x130` | ECU → gateway | panel LED state (maps to `0x5A` display frames) |

Keep the mapping in one table so a different ECU protocol is a config change,
not a firmware rewrite.

## Open decisions

1. ASR display UART pins.
2. Display-nibble colour map.
3. Exact stock mode timing rules.
4. CAN controller for the PDU (MCP2515 vs CAN2040 vs ESP32 TWAI).
5. Current sensing for the PDU (v1 or later).
