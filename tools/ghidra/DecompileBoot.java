// Decompile all functions in the ASR bootloader and save per-function C files.
// Usage: -postScript DecompileBoot.java <outputDir>
// @category ASR
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.DecompliedFunction;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.util.task.ConsoleTaskMonitor;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class DecompileBoot extends GhidraScript {

    private static final long CODE_LO = 0x10000120L;
    private static final long CODE_HI = 0x10004ED0L;

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String dir = args.length > 0 ? args[0] : "analysis/asr_decomp_boot";
        File d = new File(dir);
        if (!d.exists()) {
            d.mkdirs();
        }

        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        ConsoleTaskMonitor mon = new ConsoleTaskMonitor();

        List<Function> funcs = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            long addr = f.getEntryPoint().getOffset();
            if (addr >= CODE_LO && addr <= CODE_HI) {
                funcs.add(f);
            }
        }
        funcs.sort((a, b) -> Long.compare(a.getEntryPoint().getOffset(), b.getEntryPoint().getOffset()));

        int ok = 0;
        for (Function f : funcs) {
            long ea = f.getEntryPoint().getOffset();
            String name = f.getName();
            String fn = String.format("%08x_%s.c", ea, name.replaceAll("[^A-Za-z0-9_]", "_"));

            try {
                DecompileResults res = di.decompileFunction(f, 60, mon);
                if (res != null && res.decompileCompleted()) {
                    DecompiledFunction df = res.getDecompiledFunction();
                    if (df != null) {
                        PrintWriter w = new PrintWriter(new File(d, fn));
                        w.println("// FUNC 0x" + Long.toHexString(ea) + "  " + name);
                        w.println(df.getC());
                        w.close();
                        ok++;
                    } else {
                        println("DecompileBoot: no C for " + name + " at 0x" + Long.toHexString(ea));
                    }
                } else {
                    println("DecompileBoot: failed " + name + " at 0x" + Long.toHexString(ea)
                            + " : " + (res == null ? "null" : res.getErrorMessage()));
                }
            } catch (Exception e) {
                println("DecompileBoot: exception " + name + " at 0x" + Long.toHexString(ea)
                        + " : " + e.getMessage());
            }
        }
        println("DecompileBoot: " + ok + "/" + funcs.size() + " decompiled -> " + dir);
    }
}
