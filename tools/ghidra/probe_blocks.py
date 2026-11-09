# @category STM8
for b in currentProgram.getMemory().getBlocks():
    print "%-10s %s - %s  space=%s" % (b.getName(), b.getStart(), b.getEnd(),
                                       b.getStart().getAddressSpace().getName())
img = currentProgram.getImageBase()
print "imageBase=%s space=%s" % (img, img.getAddressSpace().getName())
