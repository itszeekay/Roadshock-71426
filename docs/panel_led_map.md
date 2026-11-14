# Panel LED display protocol - nibble to RGB map

MCU: **STM8S003K3** (button panel RGB LED display driver). Not the STM8S003F3P6 on the base board.

Status: STM8 side fully decompiled (Ghidra, Roadstm8Panel project, 147/147
functions). Color order per channel is still a bench measurement.

Scope: this is the STM8S003K3 behavior only. The 115200 display link is
internal to the panel PCB (ASR to STM8); nothing on the 2400-baud J2 bus
carries LED colors. Controlling the LEDs needs a display-link tap or an
ASR replacement; that is outside the J2 gateway scope (see `roadmap.md`).

## Frame (ASR -> STM8, 115200 8N1)

9 bytes: `5A b1 b2 b3 b4 b5 b6 b7 EE`

| byte | meaning |
|---|---|
| 0 | `0x5A` sync |
| 1 | ignored by STM8 |
| 2 | high nibble = ch0, low = ch1 |
| 3 | high = ch2, low = ch3 |
| 4 | high = ch4, low = ch5 |
| 5 | high = ch6, low = ch7 |
| 6 | ignored |
| 7 | ignored |
| 8 | `0xEE` tail |

Validation is in `display_frame_handler` (0x844C): `pcVar3[9] == 9`, `*pcVar3 == 0x5A`,
`pcVar3[8] == 0xEE`. The length check uses the pointer returned from
`bank_8b` (0x8398).

## Pin table

24 records at flash `0x8AB4`, iterated from RAM `0x0010` (`led_gpio_init`
(0x8C52) sets the pin pointer to `0x0010`, count 24, and calls `gpio_init`
with mode `0xF0`). All pins are push-pull outputs, initial high, so the LEDs are
active-low (common-anode).

Record layout: `{port(2), mask(1)}`. Ports: `0x5000` PA, `0x5005` PB,
`0x500A` PC, `0x500F` PD, `0x5014` PE, `0x5019` PF.

| # | Port | Mask | LQFP-32 pin |
|---:|---|---|---:|
| 0 | PA | 0x02 | 2 |
| 1 | PA | 0x04 | 3 |
| 2 | PA | 0x08 | 7 |
| 3 | PF | 0x10 | 8 |
| 4 | PB | 0x80 | 9 |
| 5 | PB | 0x40 | 10 |
| 6 | PB | 0x20 | 11 |
| 7 | PB | 0x10 | 12 |
| 8 | PB | 0x08 | 13 |
| 9 | PB | 0x04 | 14 |
| 10 | PB | 0x02 | 15 |
| 11 | PB | 0x01 | 16 |
| 12 | PE | 0x20 | 17 |
| 13 | PC | 0x02 | 18 |
| 14 | PC | 0x04 | 19 |
| 15 | PC | 0x08 | 20 |
| 16 | PC | 0x10 | 21 |
| 17 | PC | 0x20 | 22 |
| 18 | PC | 0x40 | 23 |
| 19 | PC | 0x80 | 24 |
| 20 | PD | 0x01 | 25 |
| 21 | PD | 0x04 | 27 |
| 22 | PD | 0x08 | 28 |
| 23 | PD | 0x10 | 29 |

Grouped by channel (three consecutive records, pointer advance `+9`):

| Channel | pin1 | pin2 | pin3 |
|---|---|---|---|
| ch0 | PA1 (2) | PA2 (3) | PA3 (7) |
| ch1 | PF4 (8) | PB7 (9) | PB6 (10) |
| ch2 | PB5 (11) | PB4 (12) | PB3 (13) |
| ch3 | PB2 (14) | PB1 (15) | PB0 (16) |
| ch4 | PE5 (17) | PC1 (18) | PC2 (19) |
| ch5 | PC3 (20) | PC4 (21) | PC5 (22) |
| ch6 | PC6 (23) | PC7 (24) | PD0 (25) |
| ch7 | PD2 (27) | PD3 (28) | PD4 (29) |

## Nibble dispatch (display_frame_handler, 0x844C)

After splitting the four payload bytes into eight nibbles (`abStack_8`),
the nibble pointer points at the nibble and the pin pointer points at the
channel's first pin record (`0x0010 + ch*9`). The per-channel loop ends with
the pin pointer advanced by 9.

Low-level setters (verified from assembly):

| function | assembly | effect |
|---|---|---|
| `sub_8efd` | `LDW X,0x0008; INCW X; INCW X; LD A,(X); LDW X,[0x0008]` | returns pin1 mask in A, port in X |
| `sub_8e7f` | `LDW X,0x0008; ADDW X,#5; LD A,(X); LDW X,[0x0008+3]` | returns pin2 mask in A, port in X |
| `sub_8e72` | `LDW X,0x0008; ADDW X,#8; LD A,(X); LDW X,[0x0008+6]` | returns pin3 mask in A, port in X |
| `sub_8f68` → `sub_8f31` | `OR A,0x0000; LD (X),A` | set pin high (off) |
| `sub_8f65` → `sub_8f59` | `CPL A; AND A,(X); LD (X),A` | clear pin low (on) |

Composed forms:

| composed | calls | effect |
|---|---|---|
| `sub_8f44` | `sub_8efd` + `sub_8f68` | pin1 high (off) |
| `sub_8f38` | `sub_8efd` + `sub_8f65` | pin1 low (on) |
| `sub_8f3e` | `sub_8e7f` + `sub_8f68` | pin2 high (off) |

Dispatch (assembly at 0x84AD-0x84F8, DEC-chain on the nibble):

| nibble | calls | pin1 | pin2 | pin3 | lit |
|---:|---|---|---|---|---|
| 0 | `sub_8f44`, `sub_8f3e`, `sub_8e72`+`sub_8f68` | H | H | H | off |
| 1 | `sub_8f38`, `sub_8f3e`, `sub_8e72`+`sub_8f68` | L | H | H | pin1 only |
| 2 | `sub_8f44`, `sub_8f3e`, `sub_8e72`+`sub_8f68` | H | H | H | off |
| 3 | `sub_8f44`, `sub_8f3e`, `sub_8e72`+`sub_8f65` | H | H | L | pin3 only |
| 4 | `sub_8f44`, `sub_8f3e`, `sub_8e72`+`sub_8f68` | H | H | H | off |
| 5 | `sub_8f44`, `sub_8e7f`+`sub_8f65`, `sub_8e72`+`sub_8f68` | H | L | H | pin2 only |
| 6 | `sub_8f44`, `sub_8f3e`, `sub_8e72`+`sub_8f68` | H | H | H | off |
| 7 | `sub_8f38`, `sub_8e7f`+`sub_8f65`, `sub_8e72`+`sub_8f68` | L | L | H | pin1 + pin2 |
| 8-15 | (fall through, no writes) | - | - | - | unchanged |

H = high (off), L = low (on, active-low). Only odd nibbles produce a non-off
pattern; even nibbles are all-high (off). Nibbles 8-15 leave the channel
unchanged.

The patterns are: 1 = pin1, 5 = pin2, 3 = pin3, 7 = pin1+pin2. No pattern lights
all three pins, and no pattern lights pin2+pin3 or pin1+pin3.

## Color map

The ASR side supplies nibbles `1`, `3`, `5`, `7` for the four channel modes, and
the owner's manual names those modes toggle red, momentary blue, pulse green and
blinking yellow. Combined with the pattern table above:

| Nibble | Pins lit | Color |
|---|---|---|
| 1 | pin1 | red |
| 3 | pin3 | blue |
| 5 | pin2 | green |
| 7 | pin1 + pin2 | yellow |

Nibble 7 lights pin1 and pin2, and red plus green is yellow, which is
self-consistent. That gives pin1 = red, pin2 = green, pin3 = blue.

The chain from the firmware is in
[asr5601_firmware.md](asr5601_firmware.md). Bench confirmation with a known LED
is still worthwhile but no longer the only source.

## What is still open

- Bytes 1/6/7 of the frame: the STM8 ignores them; they may carry a command
  or checksum in the ASR firmware.
- The pin table copy from flash `0x8AB4` to RAM `0x0010` is not yet traced to a
  single instruction; `led_gpio_init` iterates from `0x0010`, so the copy must
  happen earlier in startup. This does not affect the table contents.

## Ghidra recording

Recorded in the Roadstm8Panel project (Ghidra 11.3.1, verified):
- `display_frame_handler` (0x844C)
- `pin1_set_low` (0x8F38), `pin1_set_high` (0x8F44), `pin2_set_high` (0x8F3E)
- `get_pin1` (0x8EFD), `get_pin2` (0x8E7F), `get_pin3` (0x8E72)
- `pin_clear` (0x8F65), `pin_set` (0x8F68)
- `led_gpio_init` (0x8C52), `gpio_init` (0x8510)
