# Protocol

Base link: **STM8S003F3P6** (base, 2400 baud). Display link: **STM8S003K3** (panel, 115200 baud). Do not mix them up; they are different MCUs on different boards.

There are **two** UART links on the button panel. Do not confuse them.

| Link | Baud | Direction | Purpose |
|---|---|---|---|
| Base ↔ panel | **2400** | bidirectional | buttons, power, replies |
| ASR → STM8 | **115200** | unidirectional | RGB LED display data |

Everything below is verified from the firmware and from live captures unless
marked otherwise.

---

## 1. Base ↔ panel: 2400 8N1

### Frame

```
seq  dir  type  flag  p0 p1 p2 p3 p4 p5  sum
 1    1     1     1     6 bytes          1
```

| Field | Meaning |
|---|---|
| `seq` | sequence counter, increments per exchange, wraps at 0xFF |
| `dir` | `0x00` = panel → base, `0xFF` = base → panel |
| `type` | request type; the reply carries `type | 0x10` |
| `flag` | sub-command / index |
| `p0..p5` | six payload bytes |
| `sum` | `sum(all preceding bytes) & 0xFF` |

The link is **full duplex**: two separate signal wires, idle high.

### Message types

| Type | Direction | Flag | Meaning |
|---|---|---|---|
| `0x07` | panel → base | `0x00` / `0x01` | master power / parameter exchange |
| `0x08` | panel → base | `0x0C` | live button bitmask |
| `0x0B`, `0x0D`, `0x19` | n/a | n/a | accepted by the dispatcher, not sent by the stock panel |

### Replies

The stock base replies to every accepted panel frame.

- Normal reply: 11 bytes, `dir = 0xFF`, `type = request | 0x10`, byte 3 = `0x00`,
  payload echoed.
- `0x07` reply: **12 bytes**, `type = 0x17`, with the request's `flag` in the
  extra byte before the payload.

Verified examples:

```
panel: 19 00 08 0c 62 40 20 02 00 00 f1
base : 19 ff 18 00 62 40 20 02 00 00 f4

panel: 41 00 07 00 00 00 00 00 00 00 48     power OFF
base : 41 ff 17 00 00 00 00 00 00 00 00 57

panel: 42 00 07 01 00 00 00 00 00 00 4a     power ON
base : 42 ff 17 00 01 00 00 00 00 00 00 59
```

`tools/protocol_ref.py` contains a self-test that asserts these exact pairs.

### Button bitmask (`0x08 0x0C`)

The payload is the set of buttons **currently held**, one frame on press and one
all-zero frame on release.

| Payload byte | bit `0x10` | bit `0x01` |
|---|---|---|
| `p0` | button 1 | button 2 |
| `p1` | button 3 | button 4 |
| `p2` | button 5 | button 6 |
| `p3` | button 7 | button 8 |
| `p4`, `p5` | always 0 | |

### Master power (`0x07`)

`flag 0x00` = off, `flag 0x01` = on, six zero payload bytes.

### Startup frame (`0x1B`)

The stock base sends one unsolicited frame during init:

```
00 FF 1B 02 00 00 00 00 00 00 1C
```

- `dir = FF`, `type = 1B`, `flag = 02`, payload zero at boot.
- Sent once from the base's init (`sub_8E5C`); the sequence counter is 0 at boot.
- The panel's ASR appears to wait for this (or for replies in general) before it
  updates the status LEDs. See [panel.md](panel.md).

### Custom type `0x09` (our firmware only)

The stock base does not implement it. Payload:

```
[channel, mode, duty, freq_lo, freq_hi, 0]
```

- `mode`: `0` = off, `1` = steady on, `2` = PWM
- `duty`: 0-100
- `freq`: 50-2000 Hz (16-bit little-endian in `freq_lo`/`freq_hi`);
  bench-tested at 200-2000 Hz
- Reply: `0x19` (type `0x09 | 0x10`), 11 bytes.

### Custom type `0x0D` (our firmware only)

The custom type `0x0D` (WIPER) provides wiper control:

```
[channel, action, duty]
```

- `channel`: 1-8 (which output channel to control)
- `action`: `0` = off, `1` = slow PWM, `2` = fast PWM, `3` = intermittent momentary
- `duty`: 0-100 PWM duty cycle (for actions 1 & 2 only)

---

## 2. ASR → STM8 display link: 115200 8N1

The STM8 is a pure RGB LED driver. The ASR sends 9-byte frames:

```
[0] 0x5A
[1] ignored by the STM8
[2] high nibble = ch0, low nibble = ch1
[3] high = ch2, low = ch3
[4] high = ch4, low = ch5
[5] high = ch6, low = ch7
[6] ignored
[7] ignored
[8] 0xEE
```

The STM8 checks `[0] == 0x5A`, `[8] == 0xEE`, and `length == 9`. Bytes 1/6/7 are
free (probably a command/checksum in the ASR firmware).

### Nibble → 3-pin pattern

From the STM8 `sub_844C`; H = high, L = low. LEDs are active-low, so **L = lit**.

| nibble | pin1 | pin2 | pin3 |
|---:|---|---|---|
| 0 | H | H | H |
| 1 | L | H | H |
| 2 | H | H | H |
| 3 | H | H | L |
| 4 | H | H | H |
| 5 | H | L | H |
| 6 | H | H | H |
| 7 | L | L | H |
| 8-15 | no change | | |

Only odd nibbles produce a non-off pattern; even nibbles are all-high. The
exact color per nibble and the R/G/B pin order are **?** until confirmed on the
bench. Sending a nibble and watching the LED is the fastest way to build the
color table.

---

## Capture format

`rp2040/dual_listen.py` prints one line per frame:

```
F <ms> A 00 ff 18 00 10 00 00 00 00 00 27
F <ms> B 00 00 08 0c 10 00 00 00 00 00 24
```

- `A` = `board.RX` (GP1)
- `B` = `board.D9` (GP9)

In our harness `B` carried panel→base requests and `A` carried base→panel
replies. Either wiring order is fine; the `dir` byte tells you which is which.

---

## 3. Stock channel modes (base firmware)

The stock base firmware implements four per-channel modes, selected by
double-clicking the Mode button on the panel. Mode dispatch lives in the base
firmware and was recovered from decompilation (Ghidra 11.3.1, SHA256
`a730e8b0bd32861a02fdfd75ada5a78f632b85e54de8cb0b6a3d2d85f1dcef62`, 256
functions). Timing values need bench confirmation.

### Mode indicators

p.6 of the owner's manual defines four per-channel modes with indicator colors:

| Mode | Indicator |
|------|-----------|
| Toggle | Red |
| Momentary | Blue |
| Pulse | Green |
| Blinking | Yellow |

Hold behavior and timing are not defined by the manual and must be measured on
hardware.

### Dispatchers (same state machine, three entry points)

| Address | Name | Role |
|---------|------|------|
| 0x816D | `mode_handler` | single channel (stack parameter) |
| 0x833B | `mode_apply_block` | block (pointer + index) |
| 0x8146 | `config_mode_handler` | type-7 12-nibble buffer |

### Conversion

When the channel edit index is 0 or 4, the dispatcher converts the incoming mode
byte:

```c
if (value == 1) value = 0;
else if (value == 3) value = 2;
else if (value == 5) value = 4;
else if (value == 7) value = 8;   // via set_6() (param + 1)
```

### Dispatch

The dispatcher writes to `channel_state_write` (0x828D) based on the converted
value:

| Converted value | Write via `channel_state_write` |
|-----------------|---------------------------------|
| 0 | clears state byte |
| 1 | `0x10` or `*pb | 1` |
| 2 | `0x20` or `*pb | 2` |
| 3 | `0x30` or `*pb | 3` |
| 4 | `0x40` or `*pb | 4` |
| 5 | `0x50` or `*pb | 5` |
| 6 | `0x60` or `*pb | 6` |
| 7 | `0x70` or `*pb | 7` |
| 8 | `0x80` or `*pb | 8` |

`channel_state_write` advances `ch_edit` and loops while `ch_edit < 0x0C`,
processing all 12 channels.

### Firmware assumptions (custom base)

The custom base firmware implements the modes with these assumed timings:

- **Toggle** - press toggles the output on or off
- **Momentary** - on while held, off on release
- **Pulse** - turns the output on for a fixed interval (250 ms in this build); stock duration unknown
- **Blinking** - toggles every 100 ms (200 ms full cycle, 5 Hz); stock rate unknown; treat as placeholder

These timing values are placeholders and must be confirmed on hardware.

### EEPROM encoding (bytes 0x0D-0x14)

The stock base stores per-channel settings in EEPROM. Eight bytes, one per
channel. Example factory dump: `07 02 05 01 02 00 00 02`; after bench:
`00 00 00 00 00 00 00 00`.

Each byte holds mode and timing information. The full field decode is still an
open item. `eeprom_write` (0x9927) and `eeprom_sequencer` (0x86E8) handle
EEPROM access.

### Timing sources

Blink and pulse timing are driven by `tim4_isr` (0x9608) and `mode_tick` (0x8700),
advancing the scheduler on each TIM4 tick. The exact blink period, pulse length,
and hold behavior require bench measurement.
