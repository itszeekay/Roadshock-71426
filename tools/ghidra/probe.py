# Jython probe
from ghidra.program.model.listing import Instruction

addr = currentProgram.getImageBase()
print "PROBE OK base=%s lang=%s" % (addr, currentProgram.getLanguageID())
