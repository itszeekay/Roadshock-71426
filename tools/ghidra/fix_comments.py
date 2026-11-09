# De-duplicate register-name tokens in per-instruction comments after a label fix.
# Comments look like "CLK_CSSR | CLK_PCKENR1"; symbol-like duplicates are collapsed
# to the last (most recent) value, descriptive sentences are kept once.
# @category STM8
import re

SYM = re.compile(r"^[A-Z][A-Z0-9_]*$")

listing = currentProgram.getListing()
it = listing.getInstructions(True)
fixed = 0
while it.hasNext():
    ins = it.next()
    c = ins.getComment(0)
    if not c or "|" not in c:
        continue
    parts = [p.strip() for p in c.split("|")]
    seen = set()
    out = []
    # keep descriptive parts (with spaces/punctuation) in order,
    # for symbol-like parts keep only the last occurrence
    last_sym = {}
    for p in parts:
        if not p:
            continue
        if SYM.match(p):
            idx = len([x for x in out if SYM.match(x)])
            last_sym[p] = idx
        if p in seen:
            continue
        seen.add(p)
        out.append(p)
    # remove earlier duplicates of symbol tokens
    final = []
    for p in out:
        if SYM.match(p):
            continue
        final.append(p)
    syms = []
    for p in parts:
        p = p.strip()
        if p and SYM.match(p) and p not in syms:
            syms.append(p)
    if syms:
        final.append(syms[-1])
    newc = " | ".join(final)
    if newc != c:
        try:
            ins.setComment(0, newc)
            fixed += 1
        except:
            pass

print "comments cleaned: %d" % fixed
