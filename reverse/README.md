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


## Backend independence

The analysis data (dumps under `dumps/`, reconstructions and indexes in this
directory, `tools/triage_firmware.py` reports) is backend-agnostic. Ghidra is
one possible backend for producing it; the annotations in
`tools/ghidra/build_project.py` and `tools/ghidra/build_panel_project.py`
are the replaceable layer. A different decompiler or a future Ghidra
version can regenerate the same data from the same dumps without renaming
anything in the data directory. See `tools/build_reconstruction.py` for the
concatenation step.

## Evidence discipline

Every functional claim names its source: dump hash, function address, or
captured frame. Where the decompilation disagrees on ambiguous points
(register-bank spills, dispatch twins, 0xFF filler), the conservative reading
is recorded in `docs/firmware.md` and `docs/mode_timing.md`, and bench or
dump work is named as the decider rather than guessing. Uncertain items stay
marked uncertain in the index roles.

## Licensing

The decompiled output is provided for interoperability and research on hardware
the author owns. The underlying stock firmware remains the property of its
respective owners. See [`../NOTICE.md`](../NOTICE.md).
