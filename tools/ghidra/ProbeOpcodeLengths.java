// Probe the STM8 language module for instruction lengths of every opcode.
// Writes: 0xKEY len=N mnemonic   (len=0 means the module rejects the pattern)
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.MemoryBlock;

import java.io.PrintWriter;

public class ProbeOpcodeLengths extends GhidraScript {

    private static final long BASE = 0x0000L;
    private Address base;

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String out = args.length > 0 ? args[0] : "analysis/opcode_lengths.txt";

        base = toAddr(BASE);
        if (getMemoryBlock(base) == null) {
            MemoryBlock blk = createMemoryBlock("probe", base, new byte[512], false);
            blk.setRead(true);
            blk.setWrite(true);
            blk.setExecute(true);
        }

        PrintWriter w = new PrintWriter(out);
        w.println("# key len mnemonic");

        for (int op = 0; op < 256; op++) {
            w.println(probe(op, -1));
        }
        int[] prefixes = {0x72, 0x90, 0x91, 0x92};
        for (int p : prefixes) {
            for (int second = 0; second < 256; second++) {
                String line = probe(p, second);
                if (!line.contains("len=0")) {
                    w.println(line);
                }
            }
        }
        w.close();
        println("ProbeOpcodeLengths -> " + out);
    }

    private void clearProbe() {
        for (int i = 0; i < 8; i++) {
            try {
                setByte(base.add(i), (byte) 0);
            } catch (Exception e) {
                // ignore
            }
        }
        try {
            clearListing(base, base.add(7));
        } catch (Exception e) {
            // ignore
        }
    }

    private String probe(int first, int second) {
        int key = (second < 0) ? first : ((first << 8) | second);
        try {
            clearProbe();
            setByte(base, (byte) first);
            if (second >= 0) {
                setByte(base.add(1), (byte) second);
            }
            try {
                disassemble(base);
            } catch (Exception e) {
                // rejected
            }
            Instruction ins = getInstructionAt(base);
            if (ins == null) {
                return String.format("0x%04x len=0 -", key);
            }
            return String.format("0x%04x len=%d %s", key, ins.getBytes().length, ins.toString());
        } catch (Exception e) {
            return String.format("0x%04x len=0 !%s", key, e.getMessage());
        }
    }
}
