# Debug: inspect operand representation and symbol state
# @category STM8
from ghidra.program.model.scalar import Scalar
from ghidra.program.model.address import Address

for a in (0x8FB9, 0x8FC5, 0x903F, 0x905A, 0x9F7E):
    ins = getInstructionAt(toAddr(a))
    print "--- %04x: %s" % (a, ins)
    if ins is None:
        continue
    n = ins.getNumOperands()
    for oi in range(n):
        objs = ins.getOpObjects(oi)
        desc = ", ".join("%s(%s)" % (o.__class__.__name__, o) for o in objs)
        print "   op%d: %s" % (oi, desc)

for a in (0x5234, 0x5230, 0x023E, 0x025E):
    blk = currentProgram.getMemory().getBlock(toAddr(a))
    syms = currentProgram.getSymbolTable().getSymbols(toAddr(a))
    names = []
    while syms.hasNext():
        syms.next()
    print "addr %04x block=%s symbols=%s" % (a, "yes" if blk else "NO", syms)
