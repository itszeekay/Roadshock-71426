# RP2040 / Feather helpers

CircuitPython examples for the 2400-baud link. Copy the file you want to
`CIRCUITPY/code.py` (or run it from the REPL with
`exec(open('/file.py').read())`).

| File | Purpose |
|---|---|
| `dual_listen.py` | passive two-channel listen-only logger |
| `impersonator.py` | send panel frames to the base (interactive console) |
| `base_emulator.py` | emulate the base for a standalone panel |
| `can_gateway.ino` | Arduino CAN-gateway skeleton (not yet validated) |

## Passive listen

| Feather | Board |
|---|---|
| `RX` (GP1) | one signal wire |
| `D9` (GP9) | the other signal wire |
| `GND` | GND |

Leave TX disconnected. Check the idle level: 3.3 V is safe; 5 V needs a divider.

## Impersonator (drive the base)

| Feather | Base |
|---|---|
| `TX` (GP0) | base RX, **panel TX disconnected** |
| `RX` (GP1) | base TX |
| `GND` | GND |

Console commands: `k1`…`k8`, `kd1`…`kd8`, `ku`, `pwr0`/`p1`, `raw …`,
`listen on/off`, `stats`.

## Base emulator (panel standalone)

| Feather | Panel |
|---|---|
| `TX` (GP0) | panel RX |
| `RX` (GP1) | panel TX |
| `GND` | GND |

Sends the stock `0x1B` startup frame (flag 2, plus a flag-0 variant as an
experiment) and replies to panel frames with the stock `18` / `17` format.

The exact startup requirement of the ASR is not proven; this is the experiment.

## Two-driver rule

Never connect a Feather TX to a line that another push-pull output is already
driving. For listening, use RX only. For injection, disconnect the other
transmitter or insert the Feather in series.
