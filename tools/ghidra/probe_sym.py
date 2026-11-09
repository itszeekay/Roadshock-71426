# @category STM8
for a in (0x5234, 0x5230, 0x023E, 0x025E, 0x8000):
    blk = currentProgram.getMemory().getBlock(toAddr(a))
    sym = currentProgram.getSymbolTable().getPrimarySymbol(toAddr(a))
    print "%04x block=%s primary=%s" % (a, blk.getName() if blk else "NONE",
                                        sym.getName() if sym else "NONE")
print "blocks:", [b.getName() for b in currentProgram.getMemory().getBlocks()]
