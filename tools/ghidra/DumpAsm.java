// Prep + dump STM8 firmware: seed functions from vector table, linear-sweep code,
// then write full instruction listing and peripheral references.
// Usage: -postScript DumpAsm.java <outputPath>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class DumpAsm extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String out = (args.length > 0) ? args[0] : "analysis/asm.txt";
        Listing lst = currentProgram.getListing();

        // --- 1. Seed handlers from the STM8 vector table (0x8000..0x807F, 4 bytes each)
        for (int i = 0; i < 32; i++) {
            Address v = toAddr(0x8000L + i * 4);
            long target;
            try {
                int hi = getByte(v.add(2)) & 0xff;
                int lo = getByte(v.add(3)) & 0xff;
                target = (hi << 8) | lo;
            } catch (Exception e) {
                continue;
            }
            if (target < 0x8000L || target > 0x9fffL) continue;
            Address t = toAddr(target);
            if (getInstructionAt(t) == null) {
                try { disassemble(t); } catch (Exception e) { /* overlapping data */ }
            }
            if (getFunctionAt(t) == null && getInstructionAt(t) != null) {
                try { createFunction(t, String.format("vec%02d_%04x", i, target)); }
                catch (Exception e) { /* ignore */ }
            }
        }

        // --- 2. Linear sweep the code region (only if explicitly requested)
        boolean sweep = args.length > 1 && args[1].equals("sweep");
        if (sweep) {
            Address a = toAddr(0x8080L);
            while (a.getOffset() <= 0x9fffL) {
                if (getInstructionAt(a) == null) {
                    try { disassemble(a); } catch (Exception e) { /* ignore */ }
                }
                a = a.add(1);
            }
        }

        // --- 3. Dump
        PrintWriter w = new PrintWriter(out);
        w.println("== PROGRAM " + currentProgram.getName() + " lang="
                + currentProgram.getLanguageID() + " base=" + currentProgram.getImageBase());
        w.println();
        w.println("== FUNCTIONS ==");
        FunctionIterator fit = lst.getFunctions(true);
        while (fit.hasNext()) {
            Function f = fit.next();
            w.printf("FUNC %04x %s%n", f.getEntryPoint().getOffset(), f.getName());
        }
        w.println();
        w.println("== REFS TO PERIPHERALS 0x5000-0x57FF ==");
        for (long r = 0x5000; r <= 0x57ff; r++) {
            ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(toAddr(r));
            while (rit.hasNext()) {
                Reference ref = rit.next();
                Instruction ins = lst.getInstructionAt(ref.getFromAddress());
                w.printf("REF %04x -> %04x  %s%n", ref.getFromAddress().getOffset(), r,
                        ins == null ? "?" : ins.toString());
            }
        }
        w.println();
        w.println("== LISTING ==");
        InstructionIterator it = lst.getInstructions(true);
        int n = 0;
        List<String> lines = new ArrayList<>();
        while (it.hasNext()) {
            Instruction ins = it.next();
            StringBuilder sb = new StringBuilder();
            sb.append(String.format("%04x:", ins.getAddress().getOffset()));
            byte[] bs = ins.getBytes();
            for (byte b : bs) sb.append(String.format(" %02x", b & 0xff));
            for (int i = bs.length; i < 5; i++) sb.append("   ");
            sb.append("  ").append(ins.toString());
            lines.add(sb.toString());
            n++;
        }
        for (String s : lines) w.println(s);
        w.println();
        w.println("TOTAL INSTRUCTIONS: " + n);
        w.close();
        println("DumpAsm wrote " + n + " instructions to " + out);
    }
}
