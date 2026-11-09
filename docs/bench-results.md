# Bench results

Everything here was measured on real hardware or read from the dumped images.

## Dumps

| Item | Value |
|---|---|
| Base flash | **8192 B**, ROP `0x00` (unprotected) |
| Base EEPROM | 128 B |
| Base option bytes | 64 B |
| Panel flash | **8192 B**, ROP `0x00` (unprotected) |
| Panel EEPROM | 128 B, all zero |
| Panel option bytes | 64 B (same as base) |

Both flash images were read twice with independent reads and were byte-identical
each time.

SHA-256 values are in [`dumps/SHA256SUMS`](../dumps/SHA256SUMS).

### The stm8flash text-mode trap

`stm8flash` on Windows writes output files in **text mode**, so every `0x0A`
byte becomes `0x0D 0x0A`. The read is the right data with extra bytes:

- Base raw: 8284 B = 8192 + 92 (92 `0x0A` bytes).
- Panel raw: 8249 B = 8192 + 57.

Detection:

```
size - expected == count(0x0A)   and every 0x0A is preceded by 0x0D
```

Fix:

```python
clean = raw.replace(b"\x0d\x0a", b"\x0a")
```

The corrected files are in `dumps/`; the raw reads are kept as
`flash.raw.bin` for evidence. The complete story is in
[reproduce.md](reproduce.md#the-stm8flash-text-mode-trap).

---

## Base pin map

Verified twice: by continuity on the board and against the firmware's own
`{port, mask}` output table.

| Ch | Pin | Ch | Pin |
|---|---|---|---|
| 1 | PA3 | 5 | PC5 |
| 2 | PA2 | 6 | PC4 |
| 3 | PC7 | 7 | PC3 |
| 4 | PC6 | 8 | PD2 |

PA1 is the ACC/ignition input.

## Output stage

- High-side **P-channel D30PW40A** (TO-263 / D2PAK, 30 A / 40 V), driven by a
  SOT-23 **FMMT493** NPN (marking `493`) with a gate pull-up; active-high.
- **Channels 1–2 (30 A)** are fitted with **two D30PW40A in parallel**;
  channels 3–4 (20 A), 5–6 (10 A) and 7–8 (5 A) use one each.
- Terminal label inside the lid: **1–2 = 30 A, 3–4 = 20 A, 5–6 = 10 A,
  7–8 = 5 A**.
- The manual's per-circuit list is 5, 5, 10, 10, 20, 20, 30, 30 for buttons
  1–8; the lid label gives the physical order with terminal 1 at 30 A.

## Protocol

Verified from live captures:

- 2400 8N1, 11-byte frames, additive checksum.
- `08 0C` button bitmask; `07` power.
- Replies `18` (11 bytes) and `17` (12 bytes, extra status byte).
- Button map: `p0` bit `0x10` = 1, `0x01` = 2; `p1` = 3/4; `p2` = 5/6;
  `p3` = 7/8.

`tools/protocol_ref.py` asserts the captured pairs.

## Base output / PWM

- Stock on/off works.
- TIM1 hardware PWM on channel 6 (PC4 = TIM1_CH4) works.
- Measured: 200, 500, 1000, 1500, 2000 Hz.
- Duty: 10–100 % and odd values (3, 7, 13, 17, 37, 42, 61, 77, 89, 97).
- The advanced timer needs `BKR.MOE = 1`; without it the output never reaches
  the pin.
- TIM1 has four separate `CCMR` registers, unlike TIM2.
- The current source includes a TIM1 prescaler fix for low frequencies. It is
  built into `firmware/prebuilt/roadshock_full.ihx` but not yet flashed;
  50–199 Hz has not been re-measured.

PWM formula: `f = 16 MHz / (prescaler × (ARR + 1))`.

## Panel display link

- STM8 UART initialises at **115200** (`0x0001C200`).
- RX frame is **9 bytes**, `0x5A … 0xEE`.
- 24 GPIOs = 8 groups of 3 = 8 RGB LEDs.
- The STM8 has no button scan and no input reads.
- The ASR is the button/UI controller.

## UART / clock

- Base clock: HSI 16 MHz master / 2 MHz CPU (`CKDIVR = 0x18`).
- Base UART: `BRR1 = 0xA0`, `BRR2 = 0x1A` → 2400 baud.
- Panel STM8 clock: 16 MHz (`CKDIVR = 0`), UART 115200.

## Panel standalone

With the panel powered and the base disconnected:

- Backlight on.
- Status LEDs do not respond to buttons.
- No valid frames seen on the ASR's TX (only a 1-byte `00` glitch).

Working explanation: the ASR's UI appears to wait for the base's startup/replies.
The stock base sends one unsolicited `0x1B` at boot.
`rp2040/base_emulator.py` reproduces the startup frame and the replies for bench
testing.

## Open

- ASR firmware.
- J2-only LED override.
- Exact display-nibble colour map.
- PDU current sensing.
