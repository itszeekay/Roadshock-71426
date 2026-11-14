# Roadmap: CAN gateway and PDM

MCUs: base **STM8S003F3P6**, button panel **STM8S003K3** (LED driver) + **ASR5601S** (panel main controller).

## The target

Both products use the **same middle MCU** on the J2 cable between the panel
and the base. J2 carries the 2400-baud bus only (two signal wires plus power
and ground). The bridge therefore sees only the 2400-baud link:

```
 button panel (ASR + STM8 LED driver)        base board (power stage)
              |                                    |
         2400 bus              2400 bus            |
              \                                    /
               +------ middle MCU (RP2040/ESP32) ---+
                               |
                              CAN
```

The 115200 display link between the ASR and the STM8 is internal to the panel
PCB. It is not on J2. The panel LEDs are driven by the ASR over that internal
link, and there is no J2 path to intercept or inject display frames.

LED override would require hardware modification: wiring to the STM8 PD5/PD6
pins and the ASR display UART, or replacing the ASR. That is out of scope for
the gateway and PDM work. The bridge scope is the 2400-baud bus: button
events in, channel commands out, and output state back to CAN.

The middle MCU is a **bridge with two serial ports plus CAN**:

| Port | Link | Direction |
|---|---|---|
| 1 | 2400 bus, panel to base | RX + TX (MITM) |
| 2 | 2400 bus, base to panel | RX + TX (MITM) |
| 3 | CAN | MCP2515 / CAN2040 / ESP32 TWAI |

Portability:

- **Feather RP2040**: two hardware UARTs; CAN via MCP2515 (SPI) or CAN2040
  (PIO).
- **ESP32**: two hardware UARTs + TWAI. Easier for the CAN variant.

Keep the protocol/state logic portable; only the port layer is board-specific.

## Two firmware roles

- **Gateway**: pass-through/translate the stock link, read buttons, drive the
  base. LED state is not part of the gateway; the LEDs remain under the ASR UI.
- **PDM**: same bridge, but the base runs our firmware and reports real output
  state; the bridge is the CAN authority.

## Phases

1. **Finish the base**
   - Flash `firmware/prebuilt/roadshock_full.ihx` (includes the prescaler fix);
     re-test low PWM frequencies.
   - Verify the four stock modes (toggle / momentary / pulse / blinking) on
     hardware; they are implemented in the source.
   - Add a factual status frame (actual duty, ACC gating, faults).

2. **Prove the J2 gateway**
   - Three-port MITM is not needed; a two-port pass-through is sufficient
     (panel to base, base to panel).
   - Button frames to host/CAN; CAN to `08 0C` / `07` / `09`.
   - No display-link wiring is involved in this phase.

3. **CAN**
   - Current design: ESP32-S2 Mini with TWAI and an SN65HVD230 transceiver.
     MCP2515 and CAN2040 remain alternatives for other boards.
   - Test with a USB-CAN adapter or a second node.
   - Early testing used an Adafruit RP2040 CAN Bus Feather (MCP25625); it is not
     part of the current design.
   - Implement the CAN ID map (below, without the LED entry).

4. **PDM variant**
   - Custom base firmware as the output authority.
   - Decide current sensing (stock board has none).
   - Same bridge, no pass-through.

5. **Publish**
   - Clean repo, dumps, decompilation, protocol, tools, wiring, safety.

## Proposed CAN IDs

| ID | Direction | Payload |
|---|---|---|
| `0x100` | panel/ECU to gateway | 8-channel button bitmask (mirrors `08 0C`) |
| `0x101` | panel/ECU to gateway | master power (mirrors `07 00/01`) |
| `0x110 + n` | ECU to PDM | channel n: mode, duty |
| `0x120` | ECU to PDM | status request |
| `0x121 + n` | PDM to ECU | channel n: actual state, duty, fault |

Keep the mapping in one table so a different ECU protocol is a config change,
not a firmware rewrite.

## Open decisions

1. Exact stock mode timing rules.
2. CAN controller for the PDM: ESP32-S2 TWAI is the current choice; MCP2515 and
   CAN2040 remain alternatives.
3. Current sensing for the PDM (v1 or later).
4. ASR firmware is dumped and analyzed; the runtime pin map and BLE service
   list remain open and are not required for the J2 gateway.

## Out of scope

- Panel LED override via the internal 115200 display link. That would require
  hardware modification (panel-internal wiring or ASR replacement) and is not
  part of the gateway or PDM.
