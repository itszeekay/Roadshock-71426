# Seed functions at addresses that follow terminator instructions
# (RET 0x81, IRET 0x80, JP 0xCC hh ll) - typical compiler layout for STM8.
# @category STM8
LO = 0x8000L
HI = 0x9FFFL

created = 0
a = LO
while a <= HI - 1:
    try:
        b = getByte(toAddr(a)) & 0xFF
    except:
        break
    nxt = None
    if b == 0x81:              # RET
        nxt = a + 1
    elif b == 0x80:            # IRET
        nxt = a + 1
    elif b == 0xCC:            # JP hh ll
        nxt = a + 3
    if nxt is not None and LO <= nxt <= HI and getInstructionAt(toAddr(nxt)) is None:
        try:
            disassemble(toAddr(nxt))
            if getInstructionAt(toAddr(nxt)) is not None and getFunctionAt(toAddr(nxt)) is None:
                createFunction(toAddr(nxt), "ret_%04x" % nxt)
                created += 1
        except:
            pass
    a += 1

print "seeded %d functions after terminators" % created
