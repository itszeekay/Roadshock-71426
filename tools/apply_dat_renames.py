#!/usr/bin/env python3
"""Apply the STM8 data-global rename mappings to the Ghidra decomp output.

Renames Ghidra ``DAT_``/``_DAT_`` tokens to the semantic names in
tools/renames/dat_base.py and dat_panel.py, in-place, on the decomp source tree.
Uses word-boundary regex so a name like DAT_000a does not match DAT_000ab.

This layer is NOT tracked in the repo (the decomp tree is a local analysis
artifact); it is the source for the tracked reverse/base_firmware.c and
reverse/panel_firmware.c, which are rebuilt by tools/build_reconstruction.py.
"""

import re, sys
sys.path.insert(0, "tools/renames")
from dat_base import BASE_DAT
from dat_panel import PANEL_DAT

def apply(base_dir, mapping, dry=False):
    import glob
    count = 0
    for f in sorted(glob.glob(base_dir + "/*.c")):
        with open(f, encoding="utf-8", errors="replace") as fh:
            text = fh.read()
        for old, new in sorted(mapping.items(), key=lambda kv: -len(kv[0])):
            # word boundary to avoid prefix matches (e.g. DAT_000a vs DAT_000ab)
            text = re.sub(r"\b" + re.escape(old) + r"\b", new, text)
        if dry:
            continue
        with open(f, "w", encoding="utf-8", errors="replace") as fh:
            fh.write(text)
        count += 1
    print("renamed %d files" % count)

if __name__ == "__main__":
    import os
    base_dir = r"Z:\Roadshock-local\analysis\decomp12_ghidra"
    panel_dir = r"Z:\Roadshock-local\analysis\decomp_panel_ghidra"
    dry = "--dry" in sys.argv
    if not dry:
        os.makedirs(os.path.dirname(os.path.abspath(__file__)), exist_ok=True)
    apply(base_dir, BASE_DAT, dry)
    apply(panel_dir, PANEL_DAT, dry)
    print("done")
