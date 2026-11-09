# Reverse engineering

Decompiled reconstructions of the two STM8 images, plus annotated listings and
function indexes.

| File | Contents |
|---|---|
| `base_firmware.c` | base STM8S003F3P6, 256/256 functions (Roadstm8true) |
| `panel_firmware.c` | panel STM8S003K3, 147/147 functions (Roadstm8Panel) |
| `base_function_index.md` | address / name / role |
| `panel_function_index.md` | same for the panel |
| `base_symbols.md`, `panel_symbols.md` | symbol notes |

Annotated listings are generated on demand with
`tools/ghidra/dump_asm.py` (output to `analysis/asm_named_true.txt` /
`analysis/asm_panel.txt`); the large `.lst` listings are not tracked.

## Method

- Ghidra 11.3.1 with the community STM8 SLEIGH module for analysis
  (projects `Roadstm8true` and `Roadstm8Panel`).
- Loader: raw binary, base `0x8000`, language `STM8:BE:16`.
- Pipeline: seed vectors -> fill gaps -> seed after returns -> decompile
  every function with `tools/ghidra/DecompileTree.java`.
- Annotation layer (`build_project.py`, `build_panel_project.py`) names the
  verified routines; `tools/build_reconstruction.py` concatenates the
  per-function output into the single files above.

## Caveats

These are **reconstructions**, not original source. Variables are named by
address; register-bank helpers and SPL code can confuse the decompiler. Where
the behavior matters (protocol, pin table, display frame), the listing and the
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
