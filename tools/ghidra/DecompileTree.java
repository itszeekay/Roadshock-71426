// Decompile every function to its own file (Ghidra 12.x, Java).
// Usage: -postScript DecompileTree.java <outputDir>
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompiledFunction;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.util.task.ConsoleTaskMonitor;

import java.io.File;
import java.io.PrintWriter;

public class DecompileTree extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String dir = args.length > 0 ? args[0] : "analysis/decomp12";
        File d = new File(dir);
        if (!d.exists()) {
            d.mkdirs();
        }

        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        ConsoleTaskMonitor mon = new ConsoleTaskMonitor();

        int ok = 0, total = 0, failed = 0;
        PrintWriter man = new PrintWriter(new File(d, "_manifest.txt"));
        man.println("# addr\tname\tstatus\tfile");

        FunctionIterator fit = currentProgram.getListing().getFunctions(true);
        while (fit.hasNext()) {
            Function f = fit.next();
            total++;
            long ea = f.getEntryPoint().getOffset();
            String name = f.getName();
            String fn = String.format("%04x_%s.c", ea, name.replaceAll("[^A-Za-z0-9_]", "_"));
            String status = "ok";
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
                        status = "no-C";
                        failed++;
                    }
                } else {
                    status = "fail:" + (res == null ? "null" : res.getErrorMessage());
                    failed++;
                }
            } catch (Exception e) {
                status = "exc:" + e.getMessage();
                failed++;
            }
            man.println(String.format("0x%04x\t%s\t%s\t%s", ea, name, status, fn));
        }
        man.close();
        println("DecompileTree: " + ok + " ok / " + failed + " failed / " + total + " total -> " + dir);
    }
}
