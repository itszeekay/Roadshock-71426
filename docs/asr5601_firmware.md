# ASR5601S firmware

What the panel's main controller does, recovered from the SWD dump
(`dumps/asr/asr_flash.bin`) and the Ghidra project (`reverse/asr/`).

## Image layout

| Offset | Contents |
|---|---|
| `0x00000` | bootloader `ASRBOOTLOADER-560X-MX-V2.0.2` |
| `0x08000` | OTA tag (`7F 7F FF FF`, `FDB0`) |
| `0x0A000` | NVDS, tag only, otherwise blank |
| `0x0C000` | coredump area, empty |
| `0x0D000` | BLE stack ROM `rom-asr-1.00` (`ASONATA_BLE_NONOS_V1.4.1`) |
| `0x48000` | application `app-1.0.2-20240319.1000` |
| `0x5BA14` | end of programmed content |

## UARTs and pins

This corrects the earlier assumption that the base link is on UART1. The
application uses three UARTs, each with a different job.

| UART | Base | Pins | Baud | Role |
|---|---|---|---|---|
| UART0 | `0x40000000` | P02 TX, P03 RX | **2400** | base board link (J2) |
| UART1 | `0x40001000` | P04 TX, P05 RX | **921600** | log and console, broken out on J3 |
| UART3 | `0x40018000` | P13 TX, P14 RX | 115200 | display link, RGB LED frames to the panel STM8 |

Evidence:

- `uart0_base_link_init` at `0x1004E8A4` sets pins P02/P03, baud `0x960` = 2400,
  index 0, and enables the UART0 interrupt.
- `uart1_log_init` at `0x1004E7F0` sets pins P04/P05 and baud `0xE1000` =
  921600.
- `led_frame_send` at `0x100516D8` writes through `uart3_write` at `0x1004E888`,
  which targets `0x40018000`.
- The UART3 setup at `0x1004E854` configures pins P13 and P14 with class 16.

Consequences:

- J3 is the **UART1 log port**, not the base link. It is the correct download
  port, but it says nothing about the J2 protocol.
- The 2400 base link reaches the ASR on **P02/P03**. That is what a middle ECU
  must drive on the panel side.
- The application repurposes P06 and P07 in its pin setup, so SWD only works
  while the application is not running. The display link is not the cause; it
  is on P13/P14. P06/P07 belong to the keypad group in the pin setup.

## Pinout

Confirmed from the initialization code:

| Pin | Function | Baud | Evidence |
|---|---|---|---|
| P02 | UART0 TX | 2400 | `uart0_base_link_init` |
| P03 | UART0 RX | 2400 | `uart0_base_link_init` |
| P04 | UART1 TX | 921600 | `uart1_log_init` |
| P05 | UART1 RX | 921600 | `uart1_log_init` |
| P13 | UART3 TX | 115200 | `0x1004E854` |
| P14 | UART3 RX | 115200 | `0x1004E854` |

The remaining pins are configured through `pinmux_set` with a configuration
class. The switch that maps a class to the 4-bit function code is decoded:

| Class | Function code | Pins | Role |
|---|---|---|---|
| 3 | 0 | P10, P15, P16, P22, P24 | GPIO |
| 12 | 6 | P06, P07, P08, P09 | keypad columns 0 to 3 |
| 12 | 6 | P25, P26, P28, P29 | keypad rows 2, 3, 1, 4 |
| 13 | 1 | P02, P03 | UART0 |
| 14 | 1 | P04, P05 | UART1 |
| 16 | 1 | P13, P14 | UART3 |

Function code 6 is the keypad row/column function in the ASR pin mux table.
That gives a 4 by 4 matrix:

| | COL0 P06 | COL1 P07 | COL2 P08 | COL3 P09 |
|---|---|---|---|---|
| ROW1 P28 | key | key | key | key |
| ROW2 P25 | key | key | key | key |
| ROW3 P26 | key | key | key | key |
| ROW4 P29 | key | key | key | key |

Sixteen positions, ten used by the panel buttons.

This explains the SWD behaviour: at reset P06/P07 are `SWC`/`SWD`, and the
application switches them to keypad columns during init, which removes the
debug port.

The keypad itself supports up to 14 rows by 8 columns in hardware; this panel
uses 4 rows by 5 columns, and the firmware handles keys 1 through 14.

## Base link handling

| Item | Value |
|---|---|
| UART0 RX callback | `0x1004F728` |
| RX ring buffer | `0x20003481`, index at `0x20003470` |
| buffer slot size | `0x20` |
| byte dispatcher | `0x1004E1A0` |

The hardware ISR `0x1004C760` calls the generic UART handler `0x1004C4E8(0)`,
which reads the data register and calls the registered callback. The callback
appends the byte to a 32-byte ring buffer and signals a consumer.

The callback does not parse the frame itself. It stores the byte in a 32-byte
ring buffer and publishes event `0x28` through the BLE stack's event publisher
(`0x1000DF44`).

`base_link_byte_handler` at `0x1004E1A0` handles events `0x28` through `0x37`.
Event `0x28` is the frame path: it takes the current byte count of the slot as
the message length, fills a queue entry `{count, payload pointer, callback}` and
posts message `0x0B`. The count is not a wire byte; it is the number of bytes
that arrived in that burst. The other events dispatch to decode and output
functions:

| Event | Handler |
|---|---|
| `0x28` | queue the frame, post `0x0B` |
| `0x29` | `0x1004F7E0` |
| `0x2D` | `0x1005147C` |
| `0x30` | `0x100512EC` |
| `0x2A` | `0x10051B7C` |
| `0x2F` | `0x10050488` |
| `0x2E` | `0x10050448` |
| `0x2B` | `0x10051B04` |
| `0x31` to `0x37` | `0x10051654`, `0x1005032C`, `0x100502EC`, `0x1004FE88`, `0x1004FE40`, `0x1004FDF8`, `0x1004F7BC` |

Frames are delimited by an idle gap, not by a length field. The base firmware
confirms the same scheme from the other end: its UART1 receive ISR accumulates
bytes into a 32-byte buffer, a timeout marks the burst as complete, and
`frame_handler` validates the checksum over the received count. The 11-byte
frame is the application format; the transport is gap-delimited and the
checksum rejects anything malformed.

## Buttons

The keypad is a hardware matrix, not individual GPIO inputs.

| Item | Value |
|---|---|
| peripheral | KEYPAD block, `0x40015000` |
| interrupt | IRQ19, `0x1004DD24` (`keypad_irq`) |
| matrix | 4 rows by 5 columns, 20 possible keys |
| callback | row, column, pressed |
| log | `keypad irq`, `col = %ld,row = %ld,press stat:%d` |

The IRQ enables the block, copies the current matrix state, then compares it
against the previous state and calls a callback for every bit that changed.
The key index is the matrix position, and the panel firmware supports keys 1
through 14 even though this unit has 10 physical buttons.

The event handler at `0x100505B4` (`key_event_handler`) maps a key to an
action. Behavior found so far, from strings and branches:

| Behavior | Evidence |
|---|---|
| Per-key press logging | `key1 press` through `key14 press` |
| Work mode entry by repeated key 13 | `KEY13 %d times press,enter setting work mode` |
| Backlight setting mode | `enter backlight setting mode`, `BL mode:release key` |
| Backlight color cycle timer | `BL_RGB_CHANGE_TIMER:%d,BL_SET_MODE_TIMER clear;BL_SET_MODE_TIMER set` |
| Temporary all-off | `temp all off`, `temp all restore` |
| Per-channel control mode | `snv_data.current_control_mode[id]=%d` |

The handler keeps a per-channel state block with offsets `0x11`, `0x18`, `0x30`
and `0x48`; these select the control mode, the mode index and the timers for
each of the eight channels.

## LED pipeline

`led_frame_send` builds the 9-byte UART3 frame:

```
5A 00 <b0> <b1> <b2> <b3> <b4> <b5> EE
```

The six payload bytes come from the caller's buffer. The panel STM8 turns
bytes 2 to 5 into eight 3-bit RGB groups, as documented in
[panel_led_map.md](panel_led_map.md). Callers of the builder:

| Caller | Note |
|---|---|
| `0x1004FDF8` | calls `0x10053918` first |
| `0x1004FE40` | same |
| `0x1004FE88` | same, plus `0x1004EAC0` |
| `0x10051B04` | calls `0x10051734` and `0x1005187C` |

`led_update` at `0x10051B04` is the next layer up. It takes six color bytes,
writes the LED frame, and alternates between two nibble encodings on every
call using a toggle at `0x20003904`:

| Function | Role |
|---|---|
| `0x10051734` | odd to even nibble remap |
| `0x1005187C` | even to odd nibble encode |

The mapping is recoverable from the code even though there is no table. Each
channel keeps a 0-3 state byte, and `0x10050160` turns that value into a stored
nibble:

| Mode | State value | Stored nibble |
|---|---|---|
| toggle | 0 | 1 |
| momentary | 1 | 2 |
| pulse | 2 | 5 |
| blinking | 3 | 7 |

The key handler cycles the state byte with the mode and calls
`0x10050160(channel, value)`, so the state value is the mode index. `led_update`
then alternates between the two encoders on each call:

| Stored | Encoder A | Encoder B |
|---|---|---|
| 1 | 0 | 1 |
| 2 | 2 | 3 |
| 5 | 4 | 5 |
| 7 | 6 | 7 |

The even nibble is all-high, which the STM8 treats as off, and the odd nibble is
the visible color. Combining that with the owner's manual (toggle red,
momentary blue, pulse green, blinking yellow) gives:

| Nibble | Color |
|---|---|
| 0 | off |
| 1 | red |
| 3 | blue |
| 5 | green |
| 7 | yellow |

Nibbles 2, 4 and 6 appear only as the off phase of the alternating encoder. The
all-channel helpers use `0x11`, which is red on every LED, or `0x00` for all
off.

This is consistent with the STM8 pattern table: nibble 7 lights pin1 and pin2,
and red plus green is yellow. See [panel_led_map.md](panel_led_map.md).

## BLE

- The BLE stack is ASR's `ASONATA_BLE_NONOS_V1.4.1`, resident in the ROM at
  `0x1000D000`. The application calls it; the ROM is not rebuilt here.
- The NVDS block at `0x1000A000` contains only the tag, so the device name and
  bonding data are set at runtime or were never provisioned.
- There is no static GATT or service table in the application. The stack
  registers services at runtime, so the service list has to be read from a live
  scan rather than from the image.
- Application strings include `ASR BLE 560X`, `APP  %s, Name:`,
  `APP_CB: %s, manuf_name =0x%04X`, BLE MAC logging, and the OTA handlers
  (`otas_disable_handler`, `ota get version`, `ota set boot`).
- Advertising is configured through the `app_ble_*` functions
  (`app_ble_set_adv_data`, `app_ble_start_advertising`,
  `app_ble_config_legacy_advertising`).
- The advertising data template is in flash at `0x10059122` and is copied into
  RAM at `0x2000080A` by the startup RAM copy. It is a 26-byte buffer:

  ```
  19 09 "Controller8 Wired-xxxxxx"
  ```

  `0x19` is the AD length, `0x09` is "complete local name", and the last six
  characters are overwritten at runtime with six hex digits taken from the BLE
  MAC. So the advertised name is `Controller8 Wired-XXXXXX`.

## Flashing over J3

The ROM monitor on UART1 is the programming interface. It accepts `init`,
`erase`, `burn` and `boot`; `init` was confirmed on the bench. We hold a
verified full image, so a restore path exists.

Safe validation, without touching the boot image:

1. `SEL0` high, power cycle, connect at 115200.
2. Burn a small pattern into the blank ATE partition at `0x100F0000`.
3. Read it back over SWD.
4. Erase it back to `0xFF`.

## What this means for the middle ECU

- The ESP32 sits on the two J2 signal wires and speaks the 11-byte 2400 frame
  protocol to the base on one side and to the panel's UART0 on the other.
- The panel treats those frames as its only source of base state: master power,
  button reporting, and the startup frame that makes the LEDs come alive.
- Because the ASR keeps the whole UI and LED authority, a middle ECU that
  reproduces the base frames gets the full panel behavior without touching the
  panel firmware.
- The J3 log port at 921600 is a debugging side channel, separate from the
  product link.
