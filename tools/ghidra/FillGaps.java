// Post-script: iteratively fill uncovered code gaps in the persistent Ghidra project.
// Safe to re-run: it only touches byte ranges that have no instruction yet.
// Usage: -postScript FillGaps.java [minGapLen]
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;

import java.util.ArrayList;
import java.util.List;

public class FillGaps extends GhidraScript {

    private static final long LO = 0x8000L;
    private static final long HI = 0x9FFFL;

    /** Returns {start, length} pairs of ranges with no instruction, length >= minLen. */
    private List<long[]> gaps(int minLen) {
        List<long[]> out = new ArrayList<>();
        long start = -1;
        long len = 0;
        for (long a = LO; a <= HI; a++) {
            if (getInstructionAt(toAddr(a)) == null) {
                if (start < 0) { start = a; len = 0; }
                len++;
            } else {
                if (start >= 0 && len >= minLen) out.add(new long[]{start, len});
                start = -1;
            }
        }
        if (start >= 0 && len >= minLen) out.add(new long[]{start, len});
        return out;
    }

    private long coverage() {
        long covered = 0;
        ghidra.program.model.listing.InstructionIterator it =
                currentProgram.getListing().getInstructions(true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            try {
                covered += ins.getBytes().length;
            } catch (Exception e) {
                // skip unreadable instruction
            }
        }
        return covered;
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        int minLen = (args.length > 0) ? Integer.parseInt(args[0]) : 4;

        long before = coverage();
        println(String.format("coverage before: %d / %d bytes", before, HI - LO + 1));

        for (int pass = 0; pass < 5; pass++) {
            List<long[]> g = gaps(minLen);
            int created = 0;
            for (long[] range : g) {
                Address a = toAddr(range[0]);
                if (getInstructionAt(a) != null) continue;
                try {
                    disassemble(a);
                } catch (Exception e) {
                    continue;
                }
                if (getInstructionAt(a) == null) continue;
                try {
                    if (getFunctionAt(a) == null) {
                        createFunction(a, String.format("gap_%04x", range[0]));
                    }
                    created++;
                } catch (Exception e) {
                    // overlapping function body; ignore
                }
            }
            long after = coverage();
            println(String.format("pass %d: gaps=%d entries=%d coverage=%d (+%d)",
                    pass, g.size(), created, after, after - before));
            if (after == before) break;
            before = after;
        }

        println(String.format("coverage after: %d / %d (%.1f%%)", coverage(),
                HI - LO + 1, 100.0 * coverage() / (HI - LO + 1)));
    }
}
