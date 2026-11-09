# Tools

Python helpers for protocol work, dump validation, and Ghidra analysis.

| Tool | Purpose |
|---|---|
| `protocol_ref.py` | frame builder/parser, reply model, `0x09` helper; self-test |
| `validate_dump.py` | size / vector table / erased stats / Intel-HEX round trip |
| `pwm_test.py` | channel-6 frequency and duty sweep through the impersonator console |
| `duty_sweep.py` | duty sweep only |
| `read_serial.py` | read a serial console for N seconds |
| `parse_tap.py` | parse an older `FRAME A/B len=…` capture |
| `asr5601_dump.py` | read-only ASR560X UART probe, capture and image parser |
| `asr5601_fake_monitor.py` | socket-backed fake monitor for testing the dump tool without hardware |
| `extract_pyz.py` | extract Python 3.5 modules from DOGO's `PYZ-00.pyz` |
| `ghidra/` | Java/Python Ghidra scripts used to build the reverse-engineering tree |

## Protocol self-test

No hardware required:

```bash
python3 tools/protocol_ref.py
```

It verifies the checksum, the stock reply model, and the button frames against
captured pairs.

## Dump validation

```bash
python3 tools/validate_dump.py dumps/base/flash.bin 8192
python3 tools/validate_dump.py dumps/panel/flash.bin 8192
```

## PWM tests

These talk to the **CircuitPython impersonator's USB console** (115200), which
in turn sends frames to the base.

```bash
python3 tools/pwm_test.py  --port COM5
python3 tools/duty_sweep.py --port COM5
```

Set `ROADSHOCK_PORT` instead of passing `--port` if you prefer.

## ASR5601S read-only probe and dump

This tool speaks only the text monitor on the ASR's UART1. It refuses any
command containing `erase`, `burn`, `boot`, `write` or `program`.

```bash
python3 tools/asr5601_dump.py --selftest
python3 tools/asr5601_dump.py --port COM7 --probe
python3 tools/asr5601_dump.py --port COM7 --dump dumps/asr
python3 tools/asr5601_dump.py --parse dumps/asr/capture-20261109-120000.txt
```

The board must already be in download mode: `SEL0 = 1`, `SEL1 = 0`, reset.
Start at 115200; use `--baud 921600` for high-speed mode. See
[`docs/asr5601_dump_plan.md`](../docs/asr5601_dump_plan.md) for the wiring and
the exact command order.

The full capture path can be tested without hardware. The fake monitor answers
the banner, `get_chip_type`, `help` and `coredump flash all` with a small
synthetic image:

```bash
python3 tools/asr5601_fake_monitor.py --port 5555 --one &
python3 tools/asr5601_dump.py --port socket://127.0.0.1:5555 --idle 0.5 --dump /tmp/asr-test
```

It exercises the socket link, the command sequence, the frame parser and the
flat-image rebuild. It does not emulate the chip.

## DOGO PYZ extraction

`data.pyc` and the other application modules were extracted from the PYZ inside
`DOGO_VP2.3.8.exe`. The helper is reproducible:

```bash
python3 tools/extract_pyz.py PYZ-00.pyz out --list
python3 tools/extract_pyz.py PYZ-00.pyz out data "License.license"
```

The output files use the Python 3.5 twelve-byte header. A 3.5 interpreter is
required to load them; 3.12 rejects the bytecode.

## Ghidra

The scripts under `tools/ghidra/` expect a raw binary loaded at `0x8000` with
the STM8 SLEIGH language. Default output paths are relative (`analysis/...`);
override them with arguments. They are provided as the reproducible analysis
pipeline, not as a polished application.

## Dependencies

- Python 3
- `pyserial` for the serial tools
- Ghidra + JDK for the Ghidra scripts
