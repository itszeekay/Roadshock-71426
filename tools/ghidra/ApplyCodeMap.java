// Build a clean listing from an externally computed code map.
// Args: codeStartsFile codeFuncsFile
import ghidra.app.script.GhidraScript;
import ghidra.program.disassemble.Disassembler;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Function;
import ghidra.util.task.ConsoleTaskMonitor;

import java.io.BufferedReader;
import java.io.FileReader;

public class ApplyCodeMap extends GhidraScript {

    private java.util.List<Long> readAddrs(String path) throws Exception {
        java.util.List<Long> out = new java.util.ArrayList<>();
        try (BufferedReader r = new BufferedReader(new FileReader(path))) {
            String line;
            while ((line = r.readLine()) != null) {
                line = line.trim();
                if (line.length() >= 4) {
                    try {
                        out.add(Long.parseLong(line.substring(0, 4), 16));
                    } catch (NumberFormatException e) {
                        // skip
                    }
                }
            }
        }
        return out;
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String startsFile = args.length > 0 ? args[0] : "analysis/code_starts.txt";
        String funcsFile = args.length > 1 ? args[1] : "analysis/code_funcs.txt";

        java.util.List<Long> starts = readAddrs(startsFile);
        java.util.List<Long> funcs = readAddrs(funcsFile);
        println("ApplyCodeMap: " + starts.size() + " starts, " + funcs.size() + " funcs");

        // wipe any existing code
        AddressSet all = new AddressSet(toAddr(0x8000L), toAddr(0x9FFFL));
        clearListing(all);

        Disassembler dis = Disassembler.getDisassembler(currentProgram,
                new ConsoleTaskMonitor(), (ghidra.program.disassemble.DisassemblerMessageListener) null);

        int made = 0;
        for (long a : starts) {
            Address addr = toAddr(a);
            AddressSetView restricted = new AddressSet(addr, addr.add(7));
            try {
                dis.disassemble(addr, restricted, false);
                if (getInstructionAt(addr) != null) {
                    made++;
                }
            } catch (Exception e) {
                // leave as data
            }
        }

        int fns = 0;
        for (long a : funcs) {
            Address addr = toAddr(a);
            if (getInstructionAt(addr) == null) continue;
            try {
                if (getFunctionAt(addr) == null) {
                    createFunction(addr, String.format("f_%04x", a));
                    fns++;
                }
            } catch (Exception e) {
                // skip
            }
        }
        println("ApplyCodeMap: disassembled " + made + " starts, created " + fns + " functions");
    }
}
