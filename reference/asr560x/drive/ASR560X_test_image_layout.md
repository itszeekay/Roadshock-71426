# ASR560X test image layout

ASR's `sonata_hl_data_trans_demo.bin` is a 400 KB full-flash image from the
transparent-transmission demo. It is written at `0x10000000`. Its partition
boundaries match the ASR560X developer guide, so it is a useful template for
carving the panel dump.

ASR publishes the image at the Drive link in [SOURCES.md](../SOURCES.md). The
image contains the bootloader, BLE ROM and app. This note records its partition
offsets and signatures.

| Offset in image | Address | Size | Signature found |
|---|---|---|---|
| `0x00000` | `0x10000000` | 28 KB | SP `0x20012000`, reset `0x10000D59` |
| `0x07000` | `0x10007000` | 8 KB | `7F 7F FF FF`, then `FDB0` |
| `0x08000` | `0x10008000` | tag inside OTA info | same `7F 7F FF FF`, then `FDB0`; this is DOGO's `ota_tag_addr` |
| `0x09000` | `0x10009000` | 4 KB | `FF` (unused OTA backup) |
| `0x0A000` | `0x1000A000` | 8 KB | ASCII `NVDS` |
| `0x0C000` | `0x1000C000` | 4 KB | `FF` (empty coredump area) |
| `0x0D000` | `0x1000D000` | 236 KB | ASCII `rom-1.0.0` |
| `0x48000` | `0x10048000` | 112 KB | SP `0x20006000`, reset `0x10049F0D` |
| `0x64000` | `0x10064000` | 112 KB | not present; image ends here |

The published image is exactly `0x64000` bytes, so it stops at the OTA/ATE base.
The app reset vector is `0x10049F0D`, which is inside the app region.

## How to use this

After the panel dump is rebuilt, compare it with this table:

- The bootloader should start with a plausible stack pointer at `0x2000xxxx`
  and a reset vector inside `0x10000000..0x10007000`.
- The OTA info block should contain `FDB0` near the start. In the test image the
  first four bytes are `7F 7F FF FF`, then `FDB0`, and the same eight bytes
  appear again at `0x10008000`.
- The NVDS block should contain ASCII `NVDS`.
- The BLE ROM block should start with a version string such as `rom-1.0.0`.
- The app block should start with a stack pointer and a reset vector inside the
  app region.

If the panel dump does not show these signatures, either the read is incomplete
or the base address is wrong. Do not write anything until two independent reads
agree.

## Note on the coredump area

The 4 KB coredump area at `0x1000C000` is empty in this image. The read command
`coredump flash all` is documented as a capture. If it only reports this area,
it is not a full flash read. The full read must cover the bootloader, BLE ROM
and app regions above.

## Measured against the panel dump

The published image was downloaded from the link in
[SOURCES.md](../SOURCES.md). It is 409600 bytes (`0x64000`) and its SHA-256
begins `9e40558422a39f0d`.

It is a different build of the same SDK, not a byte-identical reference:

| Region | Bytes equal to the panel dump |
|---|---|
| bootloader `0x00000`-`0x08000` | 36 % |
| OTA and NVDS `0x08000`-`0x0D000` | 68 % |
| BLE ROM `0x0D000`-`0x48000` | 28 % |
| application `0x48000`-`0x64000` | 32 % |

The boundaries and signatures match, but the versions differ: the test image
bootloader resets at `0x10000D59` and its ROM string is `rom-1.0.0`, while the
panel uses reset `0x100014C5` and `rom-asr-1.00`. Treat the test image as a
layout template, not as shared code.
