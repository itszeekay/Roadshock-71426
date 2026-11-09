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

## Ghidra

The scripts under `tools/ghidra/` expect a raw binary loaded at `0x8000` with
the STM8 SLEIGH language. Default output paths are relative (`analysis/...`);
override them with arguments. They are provided as the reproducible analysis
pipeline, not as a polished application.

## Dependencies

- Python 3
- `pyserial` for the serial tools
- Ghidra + JDK for the Ghidra scripts
