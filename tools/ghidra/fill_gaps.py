# Fill uncovered code gaps in the persistent STM8 Ghidra project.
# Safe to re-run; only touches byte ranges that have no instruction yet.
# @param minGapLen minimum gap length in bytes to attempt
# @category STM8
from ghidra.program.model.listing import Instruction

LO = 0x8000L
HI = 0x9FFFL
mn = 4

args = getScriptArgs()
if len(args) > 0:
    mn = int(args[0])

listing = currentProgram.getListing()


def coverage():
    n = 0
    it = listing.getInstructions(True)
    while it.hasNext():
        n += len(it.next().getBytes())
    return n


def gaps(minlen):
    out = []
    start = -1
    ln = 0
    a = LO
    while a <= HI:
        if getInstructionAt(toAddr(a)) is None:
            if start < 0:
                start = a
                ln = 0
            ln += 1
        else:
            if start >= 0 and ln >= minlen:
                out.append((start, ln))
            start = -1
        a += 1
    if start >= 0 and ln >= minlen:
        out.append((start, ln))
    return out


before = coverage()
print "coverage before: %d / %d bytes" % (before, HI - LO + 1)

for p in range(5):
    g = gaps(mn)
    created = 0
    for (start, ln) in g:
        a = toAddr(start)
        if getInstructionAt(a) is not None:
            continue
        try:
            disassemble(toAddr(start))
        except Exception as e:
            if created == 0 and p == 0:
                print "  disasm fail at %04x: %s" % (start, e)
            continue
        if getInstructionAt(a) is None:
            continue
        try:
            if getFunctionAt(a) is None:
                createFunction(a, "gap_%04x" % start)
            created += 1
        except:
            pass
    after = coverage()
    print "pass %d: gaps=%d entries=%d coverage=%d (+%d)" % (p, len(g), created, after, after - before)
    if after == before:
        break
    before = after

print "coverage after: %d / %d (%.1f%%)" % (coverage(), HI - LO + 1,
                                            100.0 * coverage() / (HI - LO + 1))
