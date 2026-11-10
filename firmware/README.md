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
- **Hardware PWM** on TIM1 (channels 3, 4, 6, 7) and TIM2 (channels 1, 5).
- Custom `0x09` command for off / steady on / PWM with duty and frequency.
- EEPROM persistence of per-channel settings (mode, on/off, delayed-off, double-tap).
- Custom `0x0A` status frame returns channel states + master.
- Custom `0x0D` wiper control (off, slow PWM, fast PWM, intermittent momentary).
- Fails safe: a PWM request on a channel without a timer channel falls back to
  off.

## Not implemented yet

- CAN (the STM8 has no CAN controller; the gateway/PDU plan uses a companion
  MCU).

## Bench verification pending

- The four modes are implemented but have not all been exercised on hardware.
- The prescaler fix is built into the prebuilt full image but has not been
  flashed; 50-199 Hz has not been re-measured.

## Source

| File | Purpose |
|---|---|
| `src/main.c` | modes, frame handling, `0x09` |
| `src/board.c` / `board.h` | clock, GPIO, TIM1 PWM, ACC sense |
| `src/protocol.c` / `protocol.h` | UART 2400, polled RX, checksum, replies |
| `src/test_pattern.c` | bench test pattern (build with `make testpattern`) |

## Build

```bash
cd firmware
make
# bench test pattern image (channel 6 blink + PWM ramp at ~1 kHz):
make testpattern
```

Output: `build/roadshock.ihx`, the application image.

The full 8 KB image used for flashing is prebuilt. The Makefile does not
generate it.

Requires SDCC 4.5 in `PATH`.

## Prebuilt

| File | Notes |
|---|---|
| `prebuilt/roadshock_full.ihx` | latest full 8 KB image (prescaler fix); not yet flashed on the bench |
| `prebuilt/roadshock_full.bin` | binary generated from that `.ihx` |
| `prebuilt/roadshock_app.ihx` | application-only image |
| `prebuilt/SHA256SUMS` | hashes of the prebuilt images |

The prebuilt `.bin` is generated from the `.ihx` (0xFF fill), so the pair is
consistent. Always prefer the `.ihx` for `stm8flash`.

## Flash

12 V off; ST-Link on `V+`, `GND`, `SWIM`, `RST`:

```bash
stm8flash -c stlinkv2 -p stm8s003f3 -w prebuilt/roadshock_full.ihx
```

Or `make flash-full` from the `firmware` directory. `make flash` writes the
just-built application image instead.

Remove `RST`/the ST-Link to run.

## Type `0x09` payload

```
[channel, mode, duty, freq_lo, freq_hi, 0]
```

- `mode`: `0` off, `1` steady on, `2` PWM, `3` PWM with soft start
- `duty`: 0-100
- `freq`: 50-2000 Hz, 16-bit little-endian (mode 2 only)
- Reply: `0x19`

## PWM notes

- TIM1 has four separate `CCMR` registers; the map is in `src/board.h`.
- `BKR.MOE` must be set or the output never reaches the pin.
- `f = 16 MHz / (prescaler × (ARR + 1))`.

See [`../docs/firmware.md`](../docs/firmware.md) and
[`../docs/bench-results.md`](../docs/bench-results.md).
