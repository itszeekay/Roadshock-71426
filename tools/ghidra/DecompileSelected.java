import ghidra.app.script.GhidraScript;
// Decompile selected + large functions to C-like text (Ghidra 12.x, Java).
// Usage: -postScript DecompileSelected.java <outputPath>
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompiledFunction;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.util.task.ConsoleTaskMonitor;

import java.io.PrintWriter;

public class DecompileSelected extends GhidraScript {

    private static final long[] WANTED = {
        0x852E, 0x8080, 0x8EE7, 0x8FA9, 0x8FB5, 0x9780, 0x9CD8,
        0x993C, 0x9818, 0x816D, 0x92B7, 0x9B92, 0x96CB, 0x9EC1, 0x9ECB
    };

    private int countInstr(Function f) {
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        int n = 0;
        while (it.hasNext() && n < 25) {
            it.next();
            n++;
        }
        return n;
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String out = args.length > 0 ? args[0] : "analysis/decompiled.c";

        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        ConsoleTaskMonitor mon = new ConsoleTaskMonitor();

        java.util.List<Function> targets = new java.util.ArrayList<>();
        for (long a : WANTED) {
            Function f = getFunctionAt(toAddr(a));
            if (f != null && !targets.contains(f)) targets.add(f);
        }

        FunctionIterator fit = currentProgram.getListing().getFunctions(true);
        while (fit.hasNext()) {
            Function f = fit.next();
            if (targets.contains(f)) continue;
            if (countInstr(f) >= 25) targets.add(f);
        }

        PrintWriter w = new PrintWriter(out);
        w.println("// STM8S003 base board - Ghidra " +
                  ghidra.framework.Application.getApplicationVersion() +
                  " decompilation, language " + currentProgram.getLanguageID());
        w.println();

        int ok = 0;
        for (Function f : targets) {
            w.println("// ========================================================================");
            w.printf("// FUNC 0x%04x  %s%n", f.getEntryPoint().getOffset(), f.getName());
            w.println("// ========================================================================");
            try {
                DecompileResults res = di.decompileFunction(f, 60, mon);
                if (res != null && res.decompileCompleted()) {
                    DecompiledFunction df = res.getDecompiledFunction();
                    w.println(df != null ? df.getC() : "// no C");
                    if (df != null) ok++;
                } else {
                    w.println("// decompile failed: " + (res == null ? "no result" : res.getErrorMessage()));
                }
            } catch (Exception e) {
                w.println("// exception: " + e);
            }
            w.println();
        }
        w.println("// decompiled " + countOf(targets) + " functions, succeeded " + ok);
        w.close();
        println("DecompileSelected: " + ok + "/" + targets.size() + " -> " + out);
    }

    private int countOf(java.util.List<Function> l) { return l.size(); }
}
