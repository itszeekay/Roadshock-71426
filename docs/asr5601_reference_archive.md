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
entry module is `pyserial_demo.pyc` (extracted copy in
`reference/asr560x/drive/DOGO_extract/`). The binary's own names show a flash
read-back path that the manual does not document:

- `read_image`, `checkBox_read_image`, `recv_flash_image`, `direct_download_image`
- the completion string `dumping done!!!`, plus `dump_datalist`
- `\recev_data\coredump\` and `coredump_data` (core/RAM dump)
- `get_cmd_cfg` / `save_cmd_cfg` / `cmd_dict` / `cmd1..3`, so the serial commands
  are table-driven from a config file
- address constants `0x10000000` and `0x10040000`
- `erase %s 4096`, `boot %s %d`, `image verify success`, `get_chip_id`
- `please check license file.` / `update_license`

The manual documents download and erase only. The read path exists in the
binary, but the GUI is licence-gated, so it is present in code and not yet
proven to run.

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
