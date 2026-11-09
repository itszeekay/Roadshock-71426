#!/usr/bin/env python3
"""Build single-file reconstructions from the per-function DecompileTree output.

Usage:
    python3 tools/build_reconstruction.py --board base
    python3 tools/build_reconstruction.py --board panel
    python3 tools/build_reconstruction.py --board base --out reverse/base_firmware.c

Inputs (working tree):
    analysis/decomp12_ghidra/        (base, Roadstm8true, 256 files)
    analysis/decomp_panel_ghidra/    (panel, Roadstm8Panel, 147 files)
    analysis/decomp12_ghidra/_manifest.txt
    analysis/decomp_panel_ghidra/_manifest.txt

Outputs:
    reverse/base_firmware.c          (base, 256 functions)
    reverse/panel_firmware.c         (panel, 147 functions)
    reverse/base_function_index.md   (from the manifest + role map)
    reverse/panel_function_index.md
    reverse/base_symbols.md / panel_symbols.md
"""
import argparse
import os
import re
import sys

HEADER_BASE = """/*
 * Roadshock 8-Gang switch panel - base board firmware
 * STM8S003F3P6, 8 KB flash @ 0x8000, 1 KB RAM
 *
 * Reconstructed from the corrected dump (sha256
 * a730e8b0bd32861a02fdfd75ada5a78f632b85e54de8cb0b6a3d2d85f1dcef62)
 * with Ghidra 11.3.1 + STM8 SLEIGH (STM8:BE:16, base 0x8000),
 * project Roadstm8true. 256/256 functions decompiled.
 *
 * This is decompiler output, not original source. Types are
 * approximate. Reading order: the function index first, then each
 * function in address order. Names marked here (uart1_configure,
 * uart1_init_2400, mode_handler, frame_handler, cmd_0b_handler,
 * cmd_0d_handler, cmd_19_handler, config_mode_handler, etc.) were
 * assigned from call sites and confirmed against assembly; see
 * tools/ghidra/build_project.py and docs/mode_timing.md,
 * docs/hidden_commands.md. Generic names
 * (sub_*, FUN_*, gap_*, vec_*) are Ghidra defaults for code that has
 * not been given a role yet.
 *
 * Data consumed directly from the driver regions is in flash at
 * 0x9E85 (nibble table), 0x9AA8 (pin descriptor table), and the
 * panel pin table at 0x8AB4. Ghidra 11.3.1 decompilation is the source
 * of truth; cross-check against asm/base.lst and captures/.
 */
"""

HEADER_PANEL = """/*
 * Roadshock 8-Gang switch panel - button panel firmware
 * STM8S003K3, 8 KB flash @ 0x8000, 1 KB RAM
 *
 * Reconstructed from the dump (sha256
 * 00ea5024bf5dbdf62edcb86bc1158b5ec1f22a7c82eef7e60a5bd2ab26565fe3)
 * with Ghidra 11.3.1 + STM8 SLEIGH (STM8:BE:16, base 0x8000),
 * project Roadstm8Panel. 147/147 functions decompiled.
 *
 * This is decompiler output, not original source. Types are
 * approximate. Reading order: the function index first, then each
 * function in address order. Names marked here
 * (display_frame_handler, pin1_set_low/high, pin2_set_high,
 * get_pin1/2/3, pin_clear, pin_set, led_gpio_init, gpio_init,
 * uart1_configure) were assigned from call sites and confirmed
 * against assembly; see tools/ghidra/build_panel_project.py and
 * docs/panel_led_map.md. Generic names (sub_*, FUN_*, gap_*, vec_*)
 * are Ghidra defaults for code that has not been given a role yet.
 *
 * The display link runs at 115200 (9-byte 0x5A...0xEE frames).
 * The 24-record pin table is at flash 0x8AB4 (RAM 0x0010).
 * Ghidra 11.3.1 decompilation is the source of truth; cross-check
 * against asm/panel.lst. LEDs are active-low (common-anode).
 */
"""

ROLE = {
    # base (Roadstm8true)
    0x9CD8: "reset/startup: SP=0x03FF",
    0x8F7E: "UART1 configure (CR1/CR3/BRR1/BRR2/CR2)",
    0x9B17: "UART1 init for 2400 baud (DAT_0002=0x960)",
    0x9780: "UART1 control-bit set/clear",
    0x9F7E: "UART1 read data register",
    0x9F82: "UART1 write data register",
    0x9F36: "IWDG refresh",
    0x9F3D: "IWDG start (KR=0xCC)",
    0x9EC1: "TIM2 CCR1L write (PWM duty)",
    0x9ECB: "TIM2 ARRH write (PWM period)",
    0x993C: "clock tree configure",
    0x9C76: "flash key 0xAE write",
    0x9C82: "flash key 0x56 write",
    0x9C1B: "flash key dispatch (0x5062/0x5064)",
    0x9B92: "block copy",
    0x8080: "message post (types 0x17/0x18/0x1B seen)",
    0x816D: "event decoder (maps 1,3,5,7 -> 0,2,4,6)",
    0x8146: "type-7 config mode handler (12 nibbles)",
    0x82B3: "button bitmask handler (type 8)",
    0x848B: "channel index get (DAT_000e)",
    0x8485: "channel pair get (DAT_000e >> 1)",
    0x828D: "channel state write",
    0x8504: "channel advance",
    0x851A: "frame handler (checksum, type dispatch)",
    0x8640: "hidden command 0x0B handler",
    0x8689: "hidden command 0x0D handler",
    0x860C: "hidden command 0x19 handler",
    0x86CB: "message post (0x25)",
    0x86D1: "message next (DAT_0002++)",
    0x86D8: "message peek",
    0x9927: "EEPROM write helper",
    0x9AF3: "state clear helper",
    # panel (Roadstm8Panel)
    0x844C: "display frame handler (0x5A...0xEE, nibble dispatch)",
    0x8F38: "pin1 set low (on)",
    0x8F44: "pin1 set high (off)",
    0x8F3E: "pin2 set high (off)",
    0x8EFD: "get pin1 (mask+port)",
    0x8E7F: "get pin2 (mask+port)",
    0x8E72: "get pin3 (mask+port)",
    0x8F65: "pin clear (AND ~mask)",
    0x8F68: "pin set (OR mask)",
    0x8C52: "LED GPIO init (24 pins, mode 0xF0)",
    0x8510: "GPIO_Init helper",
    0x8D26: "UART1 configure for display link (115200)",
}

MANIFEST_RE = re.compile(r"^0x([0-9a-f]{4})\t(\S+)\t(\S+)\t(\S+)$")


def load_manifest(dirpath):
    entries = []
    man = os.path.join(dirpath, "_manifest.txt")
    with open(man, encoding="utf-8", errors="replace") as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            m = MANIFEST_RE.match(line)
            if not m:
                continue
            entries.append((int(m.group(1), 16), m.group(2), m.group(4)))
    entries.sort(key=lambda e: e[0])
    return entries


def build(board, decomp_dir, header, out_path, index_path, sym_path):
    entries = load_manifest(decomp_dir)
    print("%s: %d functions in %s" % (board, len(entries), decomp_dir))
    with open(out_path, "w", encoding="utf-8") as w:
        w.write(header)
        w.write("\n/* ---- function index -------------------------------\n")
        w.write(" *  addr  name\n")
        for addr, name, _fn in entries:
            w.write(" *  %04X  %s\n" % (addr, name))
        w.write(" */\n\n")
        for addr, name, fn in entries:
            path = os.path.join(decomp_dir, fn)
            with open(path, encoding="utf-8", errors="replace") as f:
                body = f.read().strip()
            # decomp files start with "// FUNC 0x..." already
            w.write(body)
            w.write("\n\n")
    print("wrote %s" % out_path)

    with open(index_path, "w", encoding="utf-8") as w:
        w.write("# Function index\n\n")
        w.write("Generated by `tools/build_reconstruction.py` from the per-function "
                "DecompileTree output (%d functions).\n\n" % len(entries))
        w.write("| addr | name | role |\n|---|---|---|\n")
        for addr, name, _fn in entries:
            w.write("| 0x%04X | `%s` | %s |\n" % (addr, name, ROLE.get(addr, "")))
    print("wrote %s" % index_path)

    with open(sym_path, "w", encoding="utf-8") as w:
        w.write("# Symbol table\n\n| address | name |\n|---|---|\n")
        for addr, name, _fn in entries:
            w.write("| 0x%04X | `%s` |\n" % (addr, name))
    print("wrote %s" % sym_path)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--board", choices=["base", "panel"], required=True)
    ap.add_argument("--decomp", default=None)
    ap.add_argument("--out", default=None)
    args = ap.parse_args()

    here = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    root = os.environ.get("ROADSHOCK_ROOT", here)

    if args.board == "base":
        decomp = args.decomp or os.path.join(root, "analysis", "decomp12_ghidra")
        out = args.out or os.path.join(root, "reverse", "base_firmware.c")
        index = os.path.join(root, "reverse", "base_function_index.md")
        sym = os.path.join(root, "reverse", "base_symbols.md")
        build("base", decomp, HEADER_BASE, out, index, sym)
    else:
        decomp = args.decomp or os.path.join(root, "analysis", "decomp_panel_ghidra")
        out = args.out or os.path.join(root, "reverse", "panel_firmware.c")
        index = os.path.join(root, "reverse", "panel_function_index.md")
        sym = os.path.join(root, "reverse", "panel_symbols.md")
        build("panel", decomp, HEADER_PANEL, out, index, sym)


if __name__ == "__main__":
    main()
