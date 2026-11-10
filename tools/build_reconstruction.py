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
 * tools/ghidra/build_project.py and docs/protocol.md (section "Stock channel modes"),
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
    0x8000: "reset vector",
    0x9CD8: "reset/startup: SP=0x03FF",
    0x8F7E: "UART1 configure (CR1/CR3/BRR1/BRR2/CR2)",
    0x9B17: "UART1 init for 2400 baud (DAT_0002=0x960)",
    0x9780: "UART1 control-bit set/clear",
    0x9F7E: "UART1 read data register",
    0x9F82: "UART1 write data register",
    0x9F36: "IWDG refresh",
    0x9F3D: "IWDG start (KR=0xCC)",
    0x9EC1: "GPIO read-modify-AND helper",
    0x9ECB: "TIM2 ARR low write",
    0x993C: "clock tree configure",
    0x9C76: "queue slot pointer (message queue)",
    0x9C82: "reset/init entry (SP=0x03FF)",
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
    0x8252: "wide multiply helper",
    0x833B: "mode dispatch block variant (pointer param)",
    0x8700: "mode tick (DAT_02d7 /3, pin_state_d3/d4)",
    0x896D: "panel main loop (UART/GPIO/display)",
    0x8A46: "type-7 param block apply (calls config_mode_handler)",
    0x8B96: "button frame builder (gated by DAT_01f9)",
    0x8C31: "idle reply builder (0x88 fill)",
    0x8D31: "wide multiply helper",
    0x8DC3: "32-bit division/modulo helper",
    0x8E5C: "system init (UART/clock/pins, enable IRQs, post 0x1B)",
    0x8EE6: "link service loop (RX frame -> frame_handler)",
    0x8FB5: "UART1 configure with explicit params",
    0x917B: "state table init (UNK_01bf, ret_935e/ret_8700 ptrs)",
    0x9223: "ACC sense sample (PA_IDR bit1, 8-sample debounce)",
    0x92C2: "channels apply (DAT_0182, 12 entries)",
    0x935E: "TX queue drain (msg_post/msg_peek 0..9)",
    0x93E5: "clock switch helper (SWCR/SWR)",
    0x94D6: "outputs init (GPIO_Init PD + pin table)",
    0x9541: "GPIO_Init helper (ODR/DDR/CR1/CR2)",
    0x966A: "ITC priority write (SPR1/SPR2)",
    0x9728: "UART1 control register write (CR1/CR2/CR4)",
    0x9823: "mode remap (0<->1, 2<->3, 4<->5, 6->7, 7->next)",
    0x9872: "pin table apply (DAT_02df, 12 entries)",
    0x98B6: "clock/baud lookup (CMSR -> 0x2400/0xF400)",
    0x995A: "memory compare (returns 0/-1/1)",
    0x99B6: "small multiply helper",
    0x9A34: "block move (backward copy)",
    0x8A15: "message alloc loop",
    0x9AAA: "load pair a",
    0x9AB7: "load pair b",
    0x9BEB: "TIM2 IER write",
    0x9C03: "TIM4 ETR write",
    0x9C6F: "message alloc",
    0x9E3D: "channel ptr 5 store",
    0x9ED6: "TX index return",
    0x9EFE: "block copy call",
    0x9F22: "UART1 DR read",
    0x9F26: "UART1 DR write",
    0x9F39: "NOP spin",
    0x9F4B: "noop",
    0x8D00: "noop",
    0x8DBB: "divide path",
    0x908A: "bank call 0",
    0x912A: "save pair 2 call",
    0x9135: "frame push call",
    0x99DC: "shift right 4",
    0x9A84: "queue scan",
    0x9E85: "noop",
    0x9F3C: "unused vector filler",
    0x9F3E: "unused vector filler",
    0x9F3F: "unused vector filler",
    0x9F40: "unused vector filler",
    0x9F41: "unused vector filler",
    0x9F42: "unused vector filler",
    0x9F43: "unused vector filler",
    0x9F44: "unused vector filler",
    0x9F45: "unused vector filler",
    0x9F46: "unused vector filler",
    0x9F47: "unused vector filler",
    0x9F48: "unused vector filler",
    0x9F49: "unused vector filler",
    0x9F4A: "unused vector filler",
    0x9F4C: "unused vector filler",
    0x9F5D: "unused vector filler",
    0x9F6E: "unused vector filler",
    0x9F7F: "unused vector filler",
    0x9F90: "unused vector filler",
    0x81CD: "mode dispatch tail (Ghidra split)",
    0x82A8: "TIM2 path set",
    0x82AA: "TIM2 path set (second)",
    0x8490: "set 6",
    0x8495: "pin table pointers",
    0x84C5: "mode head",
    0x86C2: "post dispatch",
    0x86C8: "noop",
    0x9B72: "PA outputs init",
    0x9B92: "block copy",
    0x9F30: "NOP spin (thunk)",
    0x9608: "TIM4 scheduler interrupt",
    0x97D3: "UART1 receive interrupt",
    0x99E1: "PA1 (EXT0) interrupt",
    0x84E4: "flag set 1",
    0x9A0B: "TIM4 reset",
    0x8B79: "index add 7",
    0x8B8A: "index set",
    0x8B6E: "message step",
    0x845E: "channel step",
    0x828E: "channel step (second)",
    0x845D: "channel state write (second)",
    0x8480: "channel pointer +2",
    0x8112: "channel pointer +4",
    0x8118: "channel pointer +3",
    0x84D5: "flag clear pair",
    0x84A5: "flag init pair",
    0x84CC: "mode-off prelude",
    0x84B3: "mode-off entry",
    0x8E30: "noop",
    0x8DC0: "divide small",
    0x95DE: "store pair 0",
    0x95EC: "store pair 1",
    0x95FA: "store pair 2",
    0x95B5: "load pair 0",
    0x95C1: "load pair 1",
    0x90F3: "save pair 0",
    0x90FE: "save pair 1",
    0x9109: "save pair 2",
    0x9114: "save pair 3",
    0x9139: "save regs 0",
    0x9140: "save regs 1",
    0x9127: "save regs 2",
    0x912E: "save regs chain",
    0x9CD2: "shift left 6",
    0x9E34: "load 000c",
    0x9E46: "sum add",
    0x9CA7: "flash unlock",
    0x9CB8: "poll busy",
    0x9CF6: "byte store increment",
    0x9DF9: "sequence increment",
    0x9E0D: "sequence allocate",
    0x9F02: "sequence allocate (second)",
    0x9CE7: "sequence allocate (third)",
    0x9E03: "block copy at +7",
    0x9E05: "block copy at +7 (second)",
    0x9F06: "TIM2 off",
    0x9D76: "TIM2 enable",
    0x9D83: "TIM2 CR1 OR 0x80",
    0x9D90: "TIM4 enable",
    0x9D9D: "UART1 clear 0x20",
    0x9E58: "ITC clear",
    0x9E73: "TIM4 EGR set",
    0x9EE6: "TIM2 SR1 clear",
    0x9EEB: "TIM4 IER set",
    0x9EF0: "TIM4 IER set (second)",
    0x9E4F: "clock trim clear",
    0x9F16: "IWDG KR write",
    0x9F1A: "IWDG PR write",
    0x9F1E: "IWDG RLR write",
    0x9EDC: "IWDG refresh",
    0x9EE1: "IWDG kick 0xCC",
    0x9C95: "IWDG setup",
    0x9C47: "init walker",
    0x9C5B: "frame get",
    0x86E8: "EEPROM sequencer",
    0x86AB: "post if 0xFF",
    0x86A6: "EEPROM flush",
    0x86DF: "reset state",
    0x86D3: "DAT_0002 return",
    0x8B71: "to button frame",
    0x8B8E: "channel index set",
    0x908F: "bank post 8",
    0x9094: "bank post 0xC",
    0x90C2: "bank set 0",
    0x90C7: "bank set 4",
    0x90CC: "bank set 8",
    0x90D1: "bank set 0xC",
    0x9099: "bank function",
    0x90D6: "identity",
    0x90AC: "frame push 0",
    0x90B3: "frame push 1",
    0x90BA: "stack return",
    0x911F: "stack return (second)",
    0x9147: "save pointer 0",
    0x9154: "save pointer 1",
    0x9161: "save pointer 2",
    0x916E: "save pointer 3",
    0x9F12: "pin clear (AND)",
    0x9EBA: "pin set (OR)",
    0x9D23: "flash AND 0x505A",
    0x9DDA: "flash AND 0x505F",
    0x9DC3: "pointer 02C4",
    0x9DE5: "EEPROM offset",
    0x9E61: "pin bit A",
    0x9E6A: "pin bit B",
    0x9E95: "poll and load",
    0x9E9D: "multiply wide call",
    0x9EA5: "byte store +0x24",
    0x9EB3: "poll call",
    0x9D05: "bit scan A",
    0x9D14: "bit scan B",
    0x9D5C: "clock enable A",
    0x9D40: "clock enable B",
    0x9D4E: "clock register A",
    0x9D69: "clock shift",
    0x9DB7: "increment pair",
    0x9E21: "flag 1 clear 2",
    0x99D4: "shift loop",
    0x9CC8: "shift left loop",
    0x9D32: "pack pair",
    0x84B9: "toggle head",
    0x8B5D: "state step",
    0x8E51: "init pair",
    0x9E17: "address + 0x10",
    0x95A5: "get arg pointer",
    0x95CD: "get arg pointer 2",
    0x9C31: "memset-like",
    0x9B3A: "boot chain",
    0x8828: "bank prelude",
    0x8811: "noop",
    0x8814: "tick B",
    0x881C: "tick C",
    0x9F33: "return 1",
    0x9F0A: "store 0002",
    0x9F0E: "load 0002",
    0x9E2B: "EEPROM init A",
    0x9DCF: "sequence save",
    0x9E7C: "nibble map",
    0x9E8D: "noop",
    0x9EC8: "noop",
    0x9EF5: "table lookup",
    0x9AC4: "identity (second)",
    0x9ACF: "EEPROM read A",
    0x9BCF: "register clear A",
    0x998A: "TX index",
    0x8D16: "arithmetic subtract",
    0x8D03: "counter increment",
    0x8E40: "register snapshot",
    0x9A5C: "bad-code filler",
    0x811E: "mode convert",
    0x8841: "state dispatch loop",
    0x8FB5: "UART1 configure (explicit)",
    0x8F7E: "UART1 configure",
    0x9B17: "UART1 init 2400",
    0x816D: "mode handler",
    0x8146: "type-7 config mode handler",
    0x82B3: "button bitmask handler",
    0x848B: "channel index get",
    0x8485: "channel pair get",
    0x828D: "channel state write",
    0x8504: "channel advance",
    0x851A: "frame handler",
    0x8640: "hidden command 0x0B handler",
    0x8689: "hidden command 0x0D handler",
    0x860C: "hidden command 0x19 handler",
    0x86CB: "message post",
    0x86D1: "message next",
    0x86D8: "message peek",
    0x86C2: "post dispatch",
    0x86C8: "noop",
    0x9927: "EEPROM write",
    0x9AF3: "state clear",


    0x85E6: "EEPROM flush",
    0x9464: "clock divider set",
    0x96CB: "interrupt priority (ITC_SPR1/2)",
    0x98F1: "peripheral clock gate 1",
    0x9CD8: "reset/startup: SP=0x03FF",
    0x9DAA: "peripheral clock gate 2",
    0x9DEF: "TIM4 init",
    0x9E40: "channel pointer +5",
    0x9EAC: "peripheral clock gate 3",
    0x9ECF: "TIM4 clear EGR",
    0x9F2A: "pin clear (AND)",
    0x9F2D: "pin set (OR)",

    0x8018: "external interrupt 1 vector",
    0x801C: "external interrupt 2 vector",
    0x8AB4: "LED pin table (24 records)",

    0x8237: "arithmetic subtract",
    0x82DC: "divide",
    0x82E1: "divide (second)",
    0x82E4: "divide helper",
    0x8351: "register write A",
    0x8362: "bank 0",
    0x8367: "bank 8",
    0x836C: "identity (second)",
    0x837F: "save pointer",
    0x838E: "bank 0 (second)",
    0x8393: "bank 4",
    0x8398: "bank 8 (second)",
    0x839D: "bank 0xC",
    0x83A2: "identity function",
    0x83BF: "save pointer 0",
    0x83CA: "save pointer 1",
    0x83D5: "save pointer 2",
    0x83E0: "save pointer 3",
    0x83EB: "stack return",
    0x83F3: "save chain C",
    0x83F6: "save chain A",
    0x83FA: "save chain B",
    0x83FE: "save regs 0",
    0x840B: "save regs 1",
    0x8418: "save regs 2",
    0x8425: "save regs 3",
    0x8432: "save regs 4",
    0x843F: "save regs 5",
    0x8508: "frame fail",
    0x85C1: "UART1 control bits, checked",
    0x89EF: "LED state read",
    0x8A52: "LED self-test",
    0x8AC3: "decompiler desync artifact",
    0x8AF0: "LED nibble dispatch",
    0x8B0C: "interrupt vector (slot 8B0C)",
    0x8B62: "load pair 0",
    0x8B72: "load pair 1",
    0x8B7E: "load pair 2",
    0x8BA9: "baud lookup",
    0x8BE4: "pin control A",
    0x8C1E: "pin init",
    0x8C81: "UART BRR clear",
    0x8CAC: "pin control B",
    0x8CD6: "pin control C",
    0x8D4D: "interrupt vector",
    0x8D74: "pin set call",
    0x8D81: "pin set call 2",
    0x8D8E: "identity",
    0x8DA3: "pin control",
    0x8DBD: "pin control 2",
    0x8DD6: "pin control 3",
    0x8DEF: "UART control A",
    0x8E05: "address lookup",
    0x8E1B: "init walker",
    0x8E2F: "register read A",
    0x8E43: "reset chain",
    0x8E56: "LED shift",
    0x8E65: "display kick",
    0x8E8C: "UART clear 0x20",
    0x8E99: "shift loop",
    0x8EA1: "shift right 4",
    0x8EA6: "step pair",
    0x8EB1: "trap setup A",
    0x8EBC: "trap setup B",
    0x8EC7: "trap setup C",
    0x8ED2: "trap setup D",
    0x8EDD: "trap setup E",
    0x8EE8: "trap setup F",
    0x8EF3: "shift loop 2",
    0x8F06: "LED off",
    0x8F0F: "clock trim clear",
    0x8F18: "nibble map",
    0x8F21: "multiply wide call",
    0x8F29: "UART prelude",
    0x8F31: "pin OR (low level)",
    0x8F4A: "nibble get",
    0x8F50: "bank helper",
    0x8F59: "pin AND (low level)",
    0x8F5D: "UART1 DR read",
    0x8F61: "UART1 DR write",
    0x8F6B: "condition return",
    0x8F6E: "NOP spin (second)",
    0x8F71: "return 1",
    0x8F74: "bank helper 2",
    0x8F77: "NOP spin",
    0x8F7A: "watchdog spin",
    0x8F7C: "unused vector",
    0x8F7D: "unused vector",
    0x8F7F: "unused vector",
    0x8F80: "unused vector",
    0x8F81: "unused vector",
    0x8F82: "unused vector",
    0x8F83: "unused vector",
    0x8F84: "unused vector",
    0x8F85: "unused vector",
    0x8F86: "unused vector",
    0x8F87: "unused vector",
    0x8F88: "unused vector",
    0x8F89: "unused vector",
    0x8F8A: "unused vector",
    0x8F8B: "unused vector",
    0x8F8C: "unused vector",
    0x8F8D: "unused vector",
    0x8F8E: "noop",
    0x8F8F: "unused interrupt filler",
    0x8FA0: "unused interrupt filler",
    0x8FA9: "UART1 configure",
    0x8FBA: "unused interrupt filler",
    0x8FCB: "unused interrupt filler",
    0x8FDC: "unused interrupt filler",
    0x8FED: "unused interrupt filler",
    0x8FFE: "unused interrupt filler",
    0x9510: "decompiler desync artifact",
    0x9824: "decompiler desync artifact",

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
