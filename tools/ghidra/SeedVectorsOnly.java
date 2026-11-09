// Seed ONLY from the hardware vector table (no raw byte scanning, no gap fill).
// Used to test whether clean recursive descent decodes the drifted regions.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;

public class SeedVectorsOnly extends GhidraScript {
    @Override
    public void run() throws Exception {
        int seeded = 0;
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
            if (target < 0x8000L || target > 0x9fffL) continue;
            try {
                if (getInstructionAt(toAddr(target)) == null) {
                    disassemble(toAddr(target));
                }
                if (getFunctionAt(toAddr(target)) == null) {
                    createFunction(toAddr(target), String.format("vec%02d", i));
                }
                seeded++;
            } catch (Exception e) {
                // ignore
            }
        }
        println("SeedVectorsOnly: " + seeded + " handlers");
    }
}
