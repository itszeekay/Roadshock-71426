# Reproduce

## Prerequisites

| Tool | Use |
|---|---|
| ST-Link V2 (or clone) + `stm8flash` | SWIM dump/flash |
| SDCC 4.5 | build the custom base firmware |
| Python 3 + `pyserial` | protocol tests and console capture |
| Adafruit Feather RP2040 + CircuitPython | bus capture / impersonation |
| Optional: Adafruit RP2040 CAN Bus Feather (MCP25625) | early CAN bench testing; not part of the current design |
| Optional: USB-UART adapter | ASR J3 experiments |

---

## 1. Dump the stock firmware

Wire the ST-Link to the SWIM header: `V+`, `GND`, `SWIM`, and `RST` for reliable
flashing. **Power the board from 12 V only with the ST-Link's 3.3 V
disconnected.**

```bash
# base board (STM8S003F3P6)
stm8flash -c stlinkv2 -p stm8s003f3 -s flash  -r base_flash.raw.bin
stm8flash -c stlinkv2 -p stm8s003f3 -s eeprom -r base_eeprom.raw.bin
stm8flash -c stlinkv2 -p stm8s003f3 -s opt    -r base_opt.bin

# button panel STM8 (STM8S003K3)
stm8flash -c stlinkv2 -p stm8s003k3 -s flash  -r panel_flash.raw.bin
stm8flash -c stlinkv2 -p stm8s003k3 -s eeprom -r panel_eeprom.raw.bin
stm8flash -c stlinkv2 -p stm8s003k3 -s opt    -r panel_opt.bin
```

Read twice and compare. The repository images were built from two identical
reads.

### The stm8flash text-mode trap

On Windows, `stm8flash` writes files in text mode, so every `0x0A` becomes
`0x0D 0x0A`. A perfect read therefore looks too long:

```
base:  8284 = 8192 + 92     (92 × 0x0A)
panel: 8249 = 8192 + 57     (57 × 0x0A)
```

Detect it:

```python
raw = open("base_flash.raw.bin", "rb").read()
assert len(raw) - 8192 == raw.count(0x0A)
```

Fix it:

```python
clean = raw.replace(b"\x0d\x0a", b"\x0a")
open("base_flash.bin", "wb").write(clean)
assert len(clean) == 8192
```

A corrupted image decodes as plausible-looking but wrong code. Always validate
the reset vector and the pin table after correcting.

### Validate

```bash
python3 tools/validate_dump.py dumps/base/flash.bin 8192
python3 tools/validate_dump.py dumps/panel/flash.bin 8192
```

Checks size, the 32-entry vector table, erased-byte statistics, and an
Intel-HEX round trip.

---

## 2. Build the custom base firmware

Install SDCC 4.5 and put `sdcc` in `PATH`.

```bash
cd firmware
make
```

Outputs:

- `roadshock.ihx`: application image.
- the full 8 KB image used for flashing.

Prebuilt images are in `firmware/prebuilt/`.

---

## 3. Flash

12 V **off**. ST-Link on `V+`, `GND`, `SWIM`, `RST`.

```bash
stm8flash -c stlinkv2 -p stm8s003f3 -w firmware/prebuilt/roadshock_full.ihx
```

To run: disconnect `RST` / remove the ST-Link. The MCU is held in reset while
`RST` is wired.

---

## 4. Restore stock

The repository ships the verified stock flash and EEPROM images.

```powershell
# verify only (read-only, default)
powershell -File restore\restore_stock.ps1

# actually restore
powershell -File restore\restore_stock.ps1 -Write
```

The script uses `stm8flash` from `PATH`; pass `-Flash <path>` if needed.

`restore/firmware_stock.bin` is byte-identical to the device dump
(`a730e8b0…`). Restore is always possible.

---

## 5. Capture the 2400-baud bus

Use an RP2040 running CircuitPython.

1. Copy [`rp2040/dual_listen.py`](../rp2040/dual_listen.py) to `CIRCUITPY` as
   `code.py`.
2. Wire:

   | Feather | Board |
   |---|---|
   | `RX` (GP1) | one signal wire |
   | `D9` (GP9) | the other signal wire |
   | `GND` | GND |

   Leave TX disconnected.
3. Open the USB console (115200) and press buttons.

Check the idle voltage first. ~3.3 V is safe; ~5 V needs a divider or level
shifter (the RP2040 is not 5 V tolerant).

Output:

```
F 992338 B 00 00 08 0c 10 00 00 00 00 00 24
F 992366 A 00 ff 18 00 10 00 00 00 00 00 27
```

---

## 6. Inject frames (panel impersonator)

Use [`rp2040/impersonator.py`](../rp2040/impersonator.py) on the Feather.

| Feather | Base |
|---|---|
| `TX` (GP0) | base RX, **panel TX disconnected** |
| `RX` (GP1) | base TX |
| `GND` | GND |

Console commands:

| Command | Effect |
|---|---|
| `k1` … `k8` | press + release a button |
| `kd1` … `kd8` | hold a button |
| `ku` | release all |
| `pwr0` / `p1` | master off / on |
| `raw 08 0c 10 00 00 00 00 00` | send a raw frame |
| `listen on/off` | echo received frames |

Python helpers: `tools/pwm_test.py`, `tools/duty_sweep.py`.

---

## 7. Test the panel standalone

[`rp2040/base_emulator.py`](../rp2040/base_emulator.py) emulates the base:

- sends the stock `0x1B` startup frame,
- answers panel frames with the stock `18` / `17` replies.

Wiring:

| Feather | Panel |
|---|---|
| `TX` (GP0) | panel RX |
| `RX` (GP1) | panel TX |
| `GND` | GND |

Power the panel normally. The status LEDs should start responding if the ASR
was only waiting for a base.

---

## Safety

- 12 V automotive. Fuse outputs. Do not work live.
- Never connect the ST-Link 3.3 V with 12 V present.
- `RST` holds the MCU in reset; remove it to run.
- The RP2040 is 3.3 V only.
