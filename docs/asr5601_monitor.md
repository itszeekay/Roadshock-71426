# ASR5601S ROM download monitor

What the mask ROM monitor accepts, measured on the panel. The ROM is in
[`dumps/asr/asr_rom.bin`](../dumps/asr/asr_rom.bin), 8 KB at `0x00000000`.

## Entering it

Hold `SEL0` high at power-on. The monitor prints at 115200 8N1:

```
1F2E3D00
```

The strap is sampled at power-on only. A soft reset through SWD returns to the
monitor even if `SEL0` is low at that moment.

## Line protocol

The monitor is line based. The handshake is required before any command:

1. Send `AsrIot560x ` followed by CRLF.
2. The monitor answers `1F2E3D00`, `1F2E3D01`, `1F2E3D02`.
3. Send one command name per line.
4. Each command then reads its arguments, one value per line.

Measured exchange:

```
host: AsrIot560x \r\n
chip: 1F2E3D00
      1F2E3D01
      1F2E3D02
host: rdreg\r\n
host: 0x20000000\r\n
chip: 0x22022084
      1F2E3D02
```

## Commands

The command table is four entries at `0x13BC` in the ROM.

| Command | Handler | Arguments | Effect |
|---|---|---|---|
| `init` | `0x0E21` | baud | reconfigures the monitor UART |
| `boot` | `0x0C91` | address, size | receives a RAM image at address, verifies it, jumps |
| `wrreg` | `0x0D99` | address, value | writes one 32-bit word |
| `rdreg` | `0x0DF1` | address | reads one 32-bit word and prints it |

There is no `erase` or `burn`. Those strings exist in the DOGO host tool, not in
this monitor. See [asr5601_dump.md](asr5601_dump.md) for what that means for
flashing.

## Status codes

| Code | Meaning |
|---|---|
| `1F2E3D00` | ready, printed every idle loop |
| `1F2E3D01` | handshake accepted, step 1 |
| `1F2E3D02` | handshake accepted, or command complete |
| `1F2E3D03` | handshake stage 3 |
| `1F2E3D04` | `boot`: image received |
| `1F2E3D05` | `boot`: image verified, about to jump |
| `1F2E3D06` | `wrreg`: write done |
| `1F2E3D81` | communication error |
| `1F2E3D85` | `boot`: image verify failed |
| `1F2E3D87` | command rejected |
| `1F2E3D88` | `boot`: address out of range |
| `1F2E3D89` | `boot`: size out of range |

## Word access

`rdreg` and `wrreg` give 32-bit read and write to any address, with one
protected range:

| Range | Behaviour |
|---|---|
| `0x40031FFF` < address <= `0x4003203F` | rejected with `1F2E3D88` |

That range covers part of the GPIO and pin mux block. Everything else,
including RAM and the flash controller region, is open. A write to RAM can be
verified by reading it back.

This means the monitor alone is enough to inspect and modify RAM over J3,
without SWD.

## RAM boot

`boot` takes an address and a size, then receives an image into memory and
jumps to it.

| Check | Value |
|---|---|
| address | above `0x1FFFFFFF` |
| address + size | at most `0x20016000` |
| size | `0x81` to `0x16000` |

The verifier compares the first bytes against `ASR SONATA BLE DL NON` or
`ASR SONATA BLE DL SEC`, expects the payload length at offset `0x20`, a key at
offset `0x30`, and a 4-byte digest at offset `0x4C`. The total size is
`0x80 + payload length`.

The payload is decrypted in place with RC4, using the key at `0x30` repeated to
256 bytes for the key schedule. The digest is CRC32 of the decrypted payload:
polynomial `0x04C11DB7`, initial value `0xFFFFFFFF`, most significant bit first,
no final XOR.

The key length and the digest offset overlap in the code as read, so the exact
header layout still needs confirmation before an image is sent. A wrong image
fails the verify step and prints `1F2E3D85`; it does not touch flash.

That path allows running a supplied image from RAM. It is the route to a
J3-only flash programmer, because a RAM stub can then use the ROM flash
routines. The image digest algorithm has not been reproduced yet.
