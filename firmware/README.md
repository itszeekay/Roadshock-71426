# Custom base firmware

Target: **STM8S003F3P6** (8 KB flash, 1 KB RAM). Built with **SDCC 4.5**
(`sdcc -mstm8`).

## Features

- 8 outputs on the stock pin map.
- Per-channel modes: **toggle / momentary / pulse / blinking**.
- ACC/ignition gating on **PA1** (active high): when the vehicle is off, outputs
  are dropped.
- UART1 **2400 8N1**, stock frame format.
- Accepts panel `0x08 0x0C` (buttons) and `0x07` (master power).
- Replies with the stock `18` (11-byte) / `17` (12-byte) frames.
- **Hardware PWM** on TIM1 (channel 6 = PC4 = TIM1_CH4).
- Custom `0x09` command for off / steady on / PWM with duty and frequency.
- Fails safe: a PWM request on a channel without a timer channel falls back to
  off.

## Not implemented yet

- EEPROM persistence of per-channel settings (the stock base stores them at
  `0x0D–0x14`; ours does not yet).
- CAN (the STM8 has no CAN controller; the gateway/PDU plan uses a companion
  MCU).
- A factual status frame for the gateway/panel.

## Source

| File | Purpose |
|---|---|
| `src/main.c` | modes, frame handling, `0x09` |
| `src/board.c` / `board.h` | clock, GPIO, TIM1 PWM, ACC sense |
| `src/protocol.c` / `protocol.h` | UART 2400, polled RX, checksum, replies |
| `src/test_pattern.c` | bench test pattern (not in the default build) |

## Build

```bash
cd firmware
make
```

Output: `build/roadshock.ihx`.

Requires SDCC 4.5 in `PATH`.

## Prebuilt

| File | Notes |
|---|---|
| `prebuilt/roadshock_full.ihx` | latest full 8 KB image (prescaler fix) |
| `prebuilt/roadshock_full.bin` | binary generated from that `.ihx` |
| `prebuilt/roadshock_app.ihx` | application-only image |

The prebuilt `.bin` is generated from the `.ihx` (0xFF fill), so the pair is
consistent. Always prefer the `.ihx` for `stm8flash`.

## Flash

12 V off; ST-Link on `V+`, `GND`, `SWIM`, `RST`:

```bash
stm8flash -c stlinkv2 -p stm8s003f3 -w prebuilt/roadshock_full.ihx
```

Remove `RST`/the ST-Link to run.

## Type `0x09` payload

```
[channel, mode, duty, freq_lo, freq_hi, 0]
```

- `mode`: `0` off, `1` steady on, `2` PWM
- `duty`: 0–100
- `freq`: 50–2000 Hz, 16-bit little-endian
- Reply: `0x19`

## PWM notes

- TIM1 has four separate `CCMR` registers; the map is in `src/board.h`.
- `BKR.MOE` must be set or the output never reaches the pin.
- `f = 16 MHz / (prescaler × (ARR + 1))`.

See [`../docs/firmware.md`](../docs/firmware.md) and
[`../docs/bench-results.md`](../docs/bench-results.md).
