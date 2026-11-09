# ASR5601S reference archive and dump findings

Companion note to [`reference/asr560x/`](../reference/asr560x/). It covers what
is archived, what it changed, and where the dump work stands.

## What is archived

A curated subset of ASR's public ASR560X material, chosen for the dump work:

| Path | Contents |
|---|---|
| `reference/asr560x/docs-en/ASR560X/` | Hardware reference, schematics, reference design, hardware design, developer guide, memory layout, DOGO manual, FAQ |
| `reference/asr560x/docs-en/_sources/ASR560X/` | The clean reStructuredText twins |
| `reference/asr560x/docs-zh/ASR560X/软件快速入门/` | AT command list and SDK firmware types |
| `reference/asr560x/drive/` | QFN48 EVB schematic, Peripheral User's Guide, Development Board guide, Security notes, DOGO tool, extracted entry module |
| `reference/asr560x/SOURCES.md` | Source URL or Drive ID for each file |
| `reference/asr560x/MANIFEST.sha256` | Hashes of the published files |

Not included: the full site mirror, unrelated ASR product families, the ASR
SDK, and the datasheet (credit or form gated). PDF author and creator metadata
was stripped before publication.

## The finding that changes the dump plan

`DOGO_VP2.3.8.exe` is a PyInstaller one-file build of a Python 3.5/Qt app. Its
entry module is `pyserial_demo.pyc`. The annotated disassembly of
`recv_flash_image`, `generate_real_bin`, `get_cmd_cfg`, `send_cmd` and
`data_receive` is in `reference/asr560x/drive/DOGO_extract/dump_path.dis.txt`.

`read_image` is **not** a command. It is a checkbox flag plus two host files:

- `checkBox_read_image` sets `self.read_image = True`.
- `data_receive` appends incoming payload to `flash_image_fname` when the flag
  is set.
- `rece_bin` calls `write_to_bin_file` and `generate_real_bin`.
- `generate_real_bin` runs the regex `:(.*?)\$`, converts each match with
  `int(m, 16)` and `struct.pack("B", ...)`, writes the `.bin` to
  `./recev_data/coredump/`, and prints `dumping done!!!`.

The bootloader is a **text CLI**, not binary framing:

- prompt `welcome to download\r\n>>>`
- ASCII, CRLF-terminated commands
- `get_chip_type`, `erase  0`, `boot <type> <addr>`, `init <baud>`
- `1F2E3D00` handshake, `1F2E3D81` communication error
- `CT:` plus a regex for the chip ID
- `1048576` and `2097152` for the 1 MB and 2 MB parts

Two config files are involved, and they are not the same:

| File | Role | Needed for a dump? |
|---|---|---|
| `config/config.ini` | chip database: addresses, image slots, verbs | **Yes for DOGO** |
| `config/script.ini` | multi-send macros | No, unrelated |

Neither ships inside the exe, and the tool is licence-gated (`LicenseManager`,
registry-backed, XOR-obfuscated), so the read control may be hidden. The
cheapest first move is the `>>>` prompt over J3, which needs no ASR files. See
[asr5601_dump_plan.md](asr5601_dump_plan.md).

## Pins: what reaches a pad

From the panel photos: `U1` is the ASR5601S QFN-48, `U2` the STM8S003K3, `J3`
the 6-pad ASR UART header, `J1` the 3-pad STM8 SWIM header, and `PZ20` a 6-pin
unlabelled header to the right of the ASR, on the pin 36-43 side.

| Signal | Pin | Pad |
|---|---|---|
| GND | 25 / 49 | `J3 GND` |
| 3.3 V | 12 / 22 | `J3 +3.3` |
| P04 / UART1_TX | 13 | `J3 TX` |
| P05 / UART1_RX | 14 | `J3 RX` |
| RSTN | 44 | `J3 RST` |
| P00 / SEL0 | 40 | `J3 SEL0` |
| P01 / SEL1 | 41 | no pad; internal pull-down = 0 |
| P06 / SWCLK | 37 | **no known pad** |
| P07 / SWDIO | 36 | **no known pad**; `PZ20` is the only candidate |

The ROM bootloader signal set is on a labelled header. SWD is not, which is why
the DOGO read path matters more than the SWD fallback.

Continuity checks still worth running with the board unpowered:

- `PZ20` to `J3 TX`: is PZ20 on the ASR side?
- `PZ20` to QFN pin 36 or 37: is SWD a wire or a rework?
- `J3 TX/RX` to the `J2` signal wires: must J2 be disconnected during a
  bootloader session?

## Next steps

1. Decompile `pyserial_demo.pyc` (Python 3.5) and recover `cmd_dict` and the
   `read_image` sequence.
2. Run DOGO at 115200 with `SEL0=1` and confirm `1F2E3D00`. This proves the link
   and writes nothing.
3. Dump over UART via J3, then read twice and compare SHA-256, the same rule
   used for the STM8 images.
4. Use SWD only if the read path is licence-blocked and PZ20 carries P06/P07.

Do not run `Flash Erase` or `Burn` before a verified dump exists. There is no
factory restore image for the ASR.
