#!/usr/bin/env python3
"""Disassemble the ASR5601S dump (ARM Cortex-M0+, Thumb).

Regions of the 1 MB image at 0x10000000:

    boot  0x00000 - 0x08000   ASRBOOTLOADER
    rom   0x0D000 - 0x48000   BLE stack ROM
    app   0x48000 - 0x5BA14   application

The output is a linear listing, a symbol table built from the vector table and
BL targets, and a string table. This is a first pass; it does not follow data
references or build control flow.
"""
import argparse
import pathlib
import re
import struct
import sys

from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_MCLASS, CS_OP_IMM

BASE = 0x10000000
REGIONS = {
    "boot": (0x00000, 0x08000),
    "rom": (0x0D000, 0x48000),
    "app": (0x48000, 0x5BA14),
}
VECTOR_NAMES = [
    "sp", "reset", "nmi", "hardfault", "rsvd4", "rsvd5", "rsvd6", "rsvd7",
    "rsvd8", "rsvd9", "rsvd10", "svc", "rsvd12", "rsvd13", "pendsv", "systick",
]


def load(path):
    return pathlib.Path(path).read_bytes()


def is_code_ptr(v, lo, hi):
    return lo <= v < hi and (v & 1) == 1


def vectors(data, lo, hi):
    out = []
    n = min(64, (hi - lo) // 4)
    for i in range(n):
        v = struct.unpack_from("<I", data, i * 4)[0]
        name = VECTOR_NAMES[i] if i < len(VECTOR_NAMES) else "irq%d" % (i - 16)
        out.append((i, v, name))
    return out


def strings_in(data, lo, hi, minlen=5):
    out = []
    cur = bytearray()
    start = 0
    for off in range(lo, hi):
        b = data[off]
        if 32 <= b <= 126 or b == 9:
            if not cur:
                start = off
            cur.append(b)
        else:
            if len(cur) >= minlen:
                out.append((start, bytes(cur).decode("ascii")))
            cur = bytearray()
    if len(cur) >= minlen:
        out.append((start, bytes(cur).decode("ascii")))
    return out


LDR_PC = re.compile(r"\[pc, #(0x[0-9a-fA-F]+|\d+)\]")


def literal_value(data, addr, ops):
    """Resolve an LDR (literal) target and return (value, address)."""
    m = LDR_PC.search(ops)
    if not m:
        return None, None
    imm = int(m.group(1), 0)
    ea = ((addr + 4) & ~3) + imm
    off = ea - BASE
    if 0 <= off <= len(data) - 4:
        return struct.unpack_from("<I", data, off)[0], ea
    return None, None


def sweep(data, lo, hi, md):
    """Linear sweep, skipping long 0xFF runs and never crossing the end."""
    off = lo
    out = []
    ff_run = 0
    while off < hi:
        if data[off] == 0xFF:
            ff_run += 1
            if ff_run >= 8:
                off += 1
                continue
        else:
            ff_run = 0
        addr = BASE + off
        chunk = data[off:off + 4]
        if len(chunk) < 2:
            break
        got = False
        for insn in md.disasm(chunk, addr):
            ops = insn.op_str
            hint = ""
            if insn.mnemonic == "ldr":
                val, ea = literal_value(data, addr, ops)
                if val is not None:
                    hint = "  ; =0x%08X" % val
            out.append((addr, insn.mnemonic, ops + hint, insn.size, data[off:off + insn.size]))
            off += insn.size
            got = True
            break
        if not got:
            off += 2
    return out


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("image", help="asr_flash.bin")
    p.add_argument("--region", choices=sorted(REGIONS), default="app")
    p.add_argument("--outdir", default="reverse/asr")
    args = p.parse_args()

    data = load(args.image)
    lo, hi = REGIONS[args.region]
    hi = min(hi, len(data))
    outdir = pathlib.Path(args.outdir)
    outdir.mkdir(parents=True, exist_ok=True)

    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS)
    md.detail = True

    # symbols from the vector table
    syms = {}
    stack_top = None
    for i, v, name in vectors(data, lo, hi):
        if i == 0:
            stack_top = v
        elif is_code_ptr(v, BASE + lo, BASE + hi):
            syms.setdefault(v & ~1, "vec_%s" % name)

    insns = sweep(data, lo, hi, md)

    # BL targets
    bl_targets = {}
    for addr, mn, ops, size, raw in insns:
        if mn in ("bl", "blx"):
            m = re.search(r"#(0x[0-9a-fA-F]+)", ops)
            if not m:
                continue
            try:
                target = int(m.group(1), 0)
            except ValueError:
                continue
            bl_targets[target] = bl_targets.get(target, 0) + 1
            syms.setdefault(target & ~1, "sub_%08X" % (target & ~1))

    listing = outdir / ("%s.lst" % args.region)
    with listing.open("w", encoding="utf-8", newline="\n") as fh:
        for addr, mn, ops, size, raw in insns:
            key = addr & ~1
            label = syms.get(key)
            if label:
                fh.write("\n; ---- %s ----\n" % label)
            fh.write("%08X  %-10s  %-7s %s\n" % (addr, raw.hex(" "), mn, ops))

    symfile = outdir / ("%s_symbols.md" % args.region)
    with symfile.open("w", encoding="utf-8", newline="\n") as fh:
        fh.write("# %s symbols\n\n" % args.region)
        fh.write("| Address | Name | BL callers |\n|---|---|---|\n")
        for addr in sorted(syms):
            if not isinstance(addr, int):
                continue
            fh.write("| `0x%08X` | `%s` | %d |\n" % (addr, syms[addr], bl_targets.get(addr, 0)))

    strfile = outdir / ("%s_strings.md" % args.region)
    strs = strings_in(data, lo, hi)
    with strfile.open("w", encoding="utf-8", newline="\n") as fh:
        fh.write("# %s strings\n\n" % args.region)
        fh.write("| Address | Text |\n|---|---|\n")
        for off, s in strs:
            fh.write("| `0x%08X` | `%s` |\n" % (BASE + off, s.replace("|", "\\|")))

    print("region      %s  0x%05X-0x%05X" % (args.region, lo, hi))
    print("instructions %d" % len(insns))
    print("symbols      %d" % len([a for a in syms if isinstance(a, int)]))
    print("strings      %d" % len(strs))
    print("wrote        %s" % listing)
    print("wrote        %s" % symfile)
    print("wrote        %s" % strfile)


if __name__ == "__main__":
    sys.exit(main())
