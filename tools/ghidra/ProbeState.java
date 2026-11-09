// Report project state: memory blocks, key symbols, function count, language.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Symbol;

public class ProbeState extends GhidraScript {
    @Override
    public void run() throws Exception {
        println("language: " + currentProgram.getLanguageID());
        println("image base: " + currentProgram.getImageBase());
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            println(String.format("block %-16s %s-%s", b.getName(), b.getStart(), b.getEnd()));
        }
        long[] addrs = {0x5234, 0x5230, 0x023E, 0x025E, 0x8000, 0x8FA9};
        for (long a : addrs) {
            Symbol s = currentProgram.getSymbolTable().getPrimarySymbol(toAddr(a));
            Function f = getFunctionAt(toAddr(a));
            println(String.format("0x%04x symbol=%s function=%s", a,
                    s == null ? "NONE" : s.getName(),
                    f == null ? "-" : f.getName()));
        }
        int n = 0;
        FunctionIterator it = currentProgram.getListing().getFunctions(true);
        while (it.hasNext()) { it.next(); n++; }
        println("functions: " + n);
    }
}
