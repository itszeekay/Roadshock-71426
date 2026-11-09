# Reverse engineering

Decompiled reconstructions of the two STM8 images, plus annotated listings and
function indexes.

| File | Contents |
|---|---|
| `base_firmware.c` | base STM8S003F3P6, 256/256 functions |
| `panel_firmware.c` | panel STM8S003K3, 147/147 functions |
| `base_function_index.md` | address / size / calls / role |
| `panel_function_index.md` | same for the panel |
| `base_symbols.md`, `panel_symbols.md` | symbol notes |
| `asm/base.lst` | annotated base listing |
| `asm/panel.lst` | annotated panel listing |

## Method

- Ghidra 11.3.1 with the community STM8 SLEIGH module for analysis.
- Ghidra 12.x with Java scripts for the final tree (12.x removed Jython).
- Loader: raw binary, base `0x8000`, language `STM8:BE:16`.
- Pipeline: seed vectors → fill gaps → seed after returns → decompile every
  function.
- Scripts are in `tools/ghidra/`.

## Caveats

These are **reconstructions**, not original source. Variables are named by
address; register-bank helpers and SPL code can confuse the decompiler. Where
the behaviour matters (protocol, pin table, display frame), the listing and the
on-wire captures were used as the source of truth.

Known decompiler artifacts:

- The function lists include some data tables decoded as tiny "functions"
  (e.g. the pin table region).
- `sub_8398`/`sub_83A2` are compiler register-bank helpers, not application
  logic.

## Licensing

The decompiled output is provided for interoperability and research on hardware
the author owns. The underlying stock firmware remains the property of its
respective owners. See [`../NOTICE.md`](../NOTICE.md).
