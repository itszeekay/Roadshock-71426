// Pre-script: seed real entry points (vector table + all raw CALL/JP targets),
// so Ghidra's recursive descent disassembles with correct instruction boundaries.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import java.util.LinkedHashSet;
import java.util.Set;

public class SeedVectors extends GhidraScript {

    private void seed(long target, String name) {
        if (target < 0x8000L || target > 0x9fffL) return;
        Address t = toAddr(target);
        try {
            if (getInstructionAt(t) == null) {
                disassemble(t);
            }
            if (getFunctionAt(t) == null && getInstructionAt(t) != null) {
                createFunction(t, String.format("%s_%04x", name, target));
            }
        } catch (Exception e) {
            // ignore: overlapping data / bad decode
        }
    }

    @Override
    public void run() throws Exception {
        int vec = 0;
        for (int i = 0; i < 32; i++) {
            Address v = toAddr(0x8000L + i * 4);
            long target;
            try {
                int hi = getByte(v.add(2)) & 0xff;
                int lo = getByte(v.add(3)) & 0xff;
                target = ((long) hi << 8) | lo;
            } catch (Exception e) {
                continue;
            }
            seed(target, "vec");
            vec++;
        }

        // Explicit extra seeds for code regions the vector/raw scan missed
        long[] extra = {
            0x8080, 0x816d, 0x833b, 0x8841, 0x8c31,
            0x8f7e, 0x8fa9, 0x8fb5,      // UART init block
            0x908a, 0x9510, 0x95de,      // helpers, port D config
            0x9780, 0x97d3, 0x9824,      // UART ctrl bits, vec20, rx path
            0x9bcf, 0x9c31, 0x9c5b, 0x9cd8, // flash/EEPROM, startup
        };
        for (long t : extra) seed(t, "x");

        // raw scan for CALL (CD) / JP (CC) targets
        Set<Long> targets = new LinkedHashSet<>();
        long end = 0x9fffL;
        for (long a = 0x8000L; a < end - 2; a++) {
            byte op;
            try {
                op = getByte(toAddr(a));
            } catch (Exception e) {
                break;
            }
            if ((op & 0xff) == 0xCD || (op & 0xff) == 0xCC) {
                int hi = getByte(toAddr(a + 1)) & 0xff;
                int lo = getByte(toAddr(a + 2)) & 0xff;
                long t = ((long) hi << 8) | lo;
                if (t >= 0x8000L && t <= end) targets.add(t);
            }
        }
        for (long t : targets) {
            seed(t, "sub");
        }

        // second pass: after disassembly, scan again (new CALLs may now be visible)
        Set<Long> more = new LinkedHashSet<>();
        for (long a = 0x8000L; a < end - 2; a++) {
            if (getInstructionAt(toAddr(a)) == null) continue;
            byte op;
            try { op = getByte(toAddr(a)); } catch (Exception e) { break; }
            if ((op & 0xff) == 0xCD || (op & 0xff) == 0xCC) {
                int hi = getByte(toAddr(a + 1)) & 0xff;
                int lo = getByte(toAddr(a + 2)) & 0xff;
                long t = ((long) hi << 8) | lo;
                if (t >= 0x8000L && t <= end && getInstructionAt(toAddr(t)) == null) {
                    more.add(t);
                }
            }
        }
        for (long t : more) {
            seed(t, "sub2");
        }

        println("SeedVectors: vectors=" + vec + " rawTargets=" + targets.size()
                + " secondPass=" + more.size());
    }
}
