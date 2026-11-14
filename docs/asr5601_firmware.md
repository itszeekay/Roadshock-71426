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
| UART3 | `0x40018000` | P06 TX, P07 RX | display link | RGB LED frames to the panel STM8 |

Evidence:

- `uart0_base_link_init` at `0x1004E8A4` sets pins P02/P03, baud `0x960` = 2400,
  index 0, and enables the UART0 interrupt.
- `uart1_log_init` at `0x1004E7F0` sets pins P04/P05 and baud `0xE1000` =
  921600.
- `led_frame_send` at `0x100516D8` writes through `uart3_write` at `0x1004E888`,
  which targets `0x40018000`.

Consequences:

- J3 is the **UART1 log port**, not the base link. It is the correct download
  port, but it says nothing about the J2 protocol.
- The 2400 base link reaches the ASR on **P02/P03**. That is what a middle ECU
  must drive on the panel side.
- The app reassigns P06/P07 to UART3, which is why SWD only worked in the ROM
  monitor.

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

The dispatcher compares the received byte against ASCII command bytes:

| Byte | Character | Action |
|---|---|---|
| `0x28` | `(` | builds a message from the ring buffer and posts 11 bytes |
| `0x29` | `)` | calls `0x1004F7E0(0)` |
| `0x2D` | `-` | calls `0x1005147C(0)` |
| `0x30` | `0` | calls `0x100512EC(0)`, then 40 |
| `0x2A` | `*` | further branch |

This is a byte-level command interface layered on the same link. The 11-byte
post matches the panel frame length, so the binary frame and this byte protocol
share the transport. The exact command semantics are still being decoded.

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

`0x1005187C` and `0x10051734` are the next layer up, where the color and blink
state is computed. That is where the per-button color table lives.

## BLE

- The BLE stack is ASR's `ASONATA_BLE_NONOS_V1.4.1`, resident in the ROM at
  `0x1000D000`. The application calls it; the ROM is not rebuilt here.
- The NVDS block at `0x1000A000` contains only the tag, so the device name and
  bonding data are set at runtime or were never provisioned.
- Application strings include `ASR BLE 560X`, `APP  %s, Name:`,
  `APP_CB: %s, manuf_name =0x%04X`, BLE MAC logging, and the OTA handlers
  (`otas_disable_handler`, `ota get version`, `ota set boot`).
- Advertising is configured through the `app_ble_*` functions
  (`app_ble_set_adv_data`, `app_ble_start_advertising`,
  `app_ble_config_legacy_advertising`).

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
