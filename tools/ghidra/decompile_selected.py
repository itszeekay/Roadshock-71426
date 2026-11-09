# Decompile selected functions (and all large ones) to C-like text.
# Usage: -postScript decompile_selected.py <outputPath>
# @category STM8
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
from java.io import PrintWriter

args = getScriptArgs()
out = args[0] if len(args) > 0 else "analysis/decompiled.c"

WANTED = [0x852E, 0x8080, 0x8EE7, 0x8FA9, 0x8FB5, 0x9780, 0x9CD8, 0x993C,
          0x9818, 0x816D, 0x92B7, 0x9B92, 0x993C, 0x96CB, 0x9EC1, 0x9ECB]

di = DecompInterface()
di.openProgram(currentProgram)
mon = ConsoleTaskMonitor()

listing = currentProgram.getListing()
targets = []

for a in WANTED:
    f = getFunctionAt(toAddr(a))
    if f is not None and f not in targets:
        targets.append(f)

# plus every function with >= 25 instructions
it = listing.getFunctions(True)
while it.hasNext():
    f = it.next()
    if f in targets:
        continue
    n = 0
    ins = listing.getInstructions(f.getBody(), True)
    while ins.hasNext():
        ins.next()
        n += 1
        if n >= 25:
            break
    if n >= 25:
        targets.append(f)

w = PrintWriter(out)
w.println("// STM8S003 base board - Ghidra decompilation")
w.println("// generated from project Roadstm8, language %s" % currentProgram.getLanguageID())
w.println()

ok = 0
for f in targets:
    w.println("// " + "=" * 74)
    w.println("// FUNC 0x%04x  %s" % (f.getEntryPoint().getOffset(), f.getName()))
    w.println("// " + "=" * 74)
    try:
        res = di.decompileFunction(f, 60, mon)
        if res is not None and res.decompileCompleted():
            w.println(res.getDecompiledFunction().getC())
            ok += 1
        else:
            w.println("// decompile failed: %s" % (res.getErrorMessage() if res else "no result"))
    except Exception as e:
        w.println("// exception: %s" % e)
    w.println()

w.println("// functions decompiled: %d of %d" % (ok, len(targets)))
w.close()
print "decompiled %d/%d functions -> %s" % (ok, len(targets), out)
