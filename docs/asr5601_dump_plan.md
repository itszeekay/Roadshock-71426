# ASR5601S dump plan

Status: the read path exists in DOGO's code, but nothing has been read from the
ASR yet. Two unknowns remain:

1. Does the ROM bootloader expose a read/stream command at all?
2. What is the command framing, and does it need `config.ini` or a licence?

Both can be answered at a desk and on a non-destructive bench session before
any write.

## What the DOGO decompile changed

`read_image` is **not** a command. It is a checkbox flag plus two host files:

- `checkBox_read_image` sets `self.read_image = True`.
- `data_receive` appends incoming payload to `flash_image_fname` when the flag is
  set.
- `rece_bin` then calls `write_to_bin_file` and `generate_real_bin`.
- `generate_real_bin` runs the regex `:(.*?)\$` over the text capture, converts
  each match with `int(m, 16)` and `struct.pack("B", ...)`, writes the `.bin` to
  `./recev_data/coredump/`, and prints `dumping done!!!`.

So the bootloader sends **text lines** containing `:hex$`, and the host builds
the binary. The protocol is a text CLI, not binary framing:

- prompt: `welcome to download\r\n>>>`
- commands are ASCII, CRLF-terminated
- examples seen in the binary: `get_chip_type`, `erase  0`,
  `boot <type> <addr>`, `init <baud>`
- `1F2E3D00` is the handshake; `1F2E3D81` is a communication error
- `CT:` plus a regex is the chip-ID exchange
- `1048576` and `2097152` are the 1 MB and 2 MB part sizes

Two config files matter, and they are not the same:

| File | Role | Needed for a dump? |
|---|---|---|
| `config/config.ini` | chip database: addresses, image slots, verbs per chip | **Yes for DOGO**. Without it `chip_data` is empty and `upload_bin` has nothing to send |
| `config/script.ini` | multi-send macro tab | No, unrelated to burn/read |

Neither ships inside the exe. A clean machine has neither, and the tool is
licence-gated (`LicenseManager`, registry-backed, XOR-obfuscated), so some
controls may stay hidden.

The cheap route is therefore **not DOGO**. It is the `>>>` prompt over J3, which
needs no ASR files and answers whether a read verb exists.

## Hardware

Already available:

| Item | Use |
|---|---|
| Feather RP2040 DVI (CircuitPython) | UART bridge to J3, appears as a COM port, handles 921600 |
| ST-Link V2 | SWD fallback only |
| 12 V bench supply | run the panel as built |
| Multimeter | continuity on PZ20 and J2 |
| Scope | optional, verify idle levels |

Still needed:

| Item | Why | Notes |
|---|---|---|
| 6-pin header or pogo block for J3 | the only physical connection required | measure the pitch first; the J3 pads look about 1.27 mm, not 0.1 inch. A 6-pin pogo strip held by hand is enough for a read-only session |
| Dupont jumpers, 3.3 V | J3 to bridge | five wires: TX, RX, GND, RST, SEL0. Leave J3 +3.3 unconnected if the panel is powered |
| CP2102 or FT232 USB-UART | alternative to the Feather | avoid CH340 at 921600; DOGO's high mode drops frames on it |
| 0.1 to 0.2 mm magnet wire and a fine iron | SWD only, and only if PZ20 fails | 0.4 mm pitch, three wires |

No level shifting. The ASR is a 3.3 V part here. No flash clip, socket or decap.

## Phase 0: static work, no hardware

1. Set up a Python 3.5 environment. The payload magic is `170d`. A Windows 3.5.4
   install in a throwaway directory, or a `python:3.5` container, is enough.
2. Extract `PYZ-00.pyz` properly. `pyinstxtractor` skipped it on the version
   mismatch, so the tool's config and protocol modules are still packed.
3. Decompile `pyserial_demo.pyc` and the PYZ modules. Targets, in order:
   `get_cmd_cfg`, `cmd_dict`, `send_cmd`, `read_image`, `recv_flash_image`,
   `coredump_data`.
4. Recover the command opcodes, payload layout, checksum or CRC, the read
   request's address and length fields, and the handshake after `1F2E3D00`.
5. Check what the licence gate actually guards. If it guards `read_image`, a
   licence is not needed; about 30 lines of Python speaking the same frames is
   enough.

The annotated disassembly in
`reference/asr560x/drive/DOGO_extract/dump_path.dis.txt` already covers
`recv_flash_image`, `generate_real_bin`, `get_cmd_cfg`, `send_cmd` and
`data_receive`.

Exit criterion: you can write down the exact byte sequence for "read N bytes at
`0x10000000`".

## Phase 1: handshake on the bench, non-destructive

1. Power the panel and disconnect J2 so the base's STM8 cannot drive the line.
2. Wire J3: `TX` to bridge RX, `RX` to bridge TX, `GND` to GND, `RST` and
   `SEL0` to two free GPIOs. Do not connect +3.3.
3. Check the idle level on J3 TX, about 3.3 V, before connecting anything.
4. Assert `SEL0 = 1`, pulse `RST` low, release. At 115200 8N1 you should see
   `1F2E3D00`. `1F2E3D81` means a communication error: check wiring and baud.
5. Stop if you only get silence. Do not open any burn or erase screen.

Exit criterion: `1F2E3D00` received. This proves the whole electrical path
without writing a byte.

## Phase 2: probe the text prompt

1. After `1F2E3D00`, send a bare CRLF and read the reply. Expect
   `welcome to download` and a `>>>` prompt.
2. Send `help`, then `?`, then `get_chip_type`, one at a time, and capture the
   replies. Do not paste a script.
3. Do not send anything containing `erase` or `burn`. Some `script.ini` macros
   contain erase steps; this is why they are not replayed blindly.
4. Record the command vocabulary. The question is whether it includes a read or
   upload verb.

Exit criterion: a command list, or clear evidence that no read verb is exposed.

## Phase 3: first read

Choose one route:

**A. The CLI has a read verb.** Request a small block first, for example 256
bytes at `0x10000000`. Inspect the reply shape. If it is text `:hex$` lines,
capture them and run the same `generate_real_bin` logic. Then try
`0x10040000`, the app base used by DOGO's default.

**B. DOGO with `config.ini` and a licence.** Tick `read_image`, run the session,
then press generate bin. The capture plumbing is already in the tool.

If the first block looks plausible, read the full 1 MB. A sensible first block
has a stack pointer around `0x2000xxxx` and a reset vector into flash.

Read the full 1 MB **twice**, in separate power cycles, to two files.

Exit criterion: two 1,048,576-byte files with identical SHA-256.

## Phase 4: verify and archive

1. Compare the two reads. Any difference means retry; do not rationalise it.
2. Check the vector table at `0x10000000` and carve the partitions using
   `docs/asr5601_reference_archive.md` and the Memory Layout page. The offsets
   have not been confirmed on hardware yet.
3. Run `strings -a` for BLE names and UUIDs to confirm this is real code and
   not `0xFF` padding.
4. Commit `dumps/asr/flash.bin`, `.hex`, `SHA256SUMS` and a short
   `dumps/asr/README.md`. Exclude the ASR BLE stack ROM range if the dump is
   published.

Exit criterion: a committed, reproducible image. Only then does the ASR become
flashable, and it still has no factory restore file.

## Phase 5: SWD fallback

Only if Phases 2 and 3 fail.

1. Board unpowered. Beep J3 TX against the PZ20 pads. If it beeps, PZ20 is on
   the ASR side; map all six pads.
2. Beep PZ20 against QFN pins 36 and 37. If either connects, SWD costs a wire,
   not a rework.
3. OpenOCD with the ST-Link: `cortex_m` target, connect-under-reset,
   `dump_image asr.bin 0x10000000 0x100000`.
4. If reads return zeros or fault, the debug port is locked. Stop. That is
   decap territory and out of scope.

## Decision table

| Situation | Call |
|---|---|
| `read_image` is licence-gated | write your own sender from the decompile; do not hunt for a cracked licence |
| No `1F2E3D00` at 115200 | check baud and swap TX/RX before suspecting the chip; try 9600 |
| Read returns all `0xFF` | wrong base address or an erase-protected region; try `0x10040000`, the app base from the binary |
| Only one clean read, second differs | treat it as no dump; the ASR has no restore image |
| SWD locked, UART has no read | stop and reassess; no cheap path left |
| CLI help lists erase but no read | do not experiment with erase; the restore image does not exist |

## Definition of done

Two byte-identical 1 MB images, their SHA-256, a carved partition map, and a
note in `docs/` describing exactly how they were read. That matches the standard
used for the STM8 dumps.

Realistic effort: Phase 0 is the long pole, a few hours of decompiler work.
Phases 1 to 3 are an afternoon if the protocol is clean.

## Risks

- There is no factory restore image for the ASR. Do not run `Flash Erase` or
  `Burn` before a verified dump exists.
- The text CLI commands are destructive by nature. Type one command at a time
  and read the echo.
- The tool is licence-gated; the read checkbox may be hidden or inert in a stock
  install.
- The ASR560X datasheet is still gated, so the memory map comes from the
  Peripheral User's Guide, the Memory Layout page and the binary constants.
