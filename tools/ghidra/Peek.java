// Print instructions in an address range: Peek.java <startHex> <endHex>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;

public class Peek extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        long start = Long.parseLong(a[0].replace("0x", ""), 16);
        long end = Long.parseLong(a[1].replace("0x", ""), 16);
        Address addr = toAddr(start);
        while (addr.getOffset() <= end) {
            Instruction ins = getInstructionAt(addr);
            if (ins == null) {
                println(String.format("%04x: ?? (no instruction)", addr.getOffset()));
                addr = addr.add(1);
                continue;
            }
            StringBuilder hex = new StringBuilder();
            for (byte b : ins.getBytes()) hex.append(String.format("%02x ", b));
            println(String.format("%04x: %-14s %s", addr.getOffset(), hex.toString().trim(),
                    ins.toString()));
            addr = addr.add(ins.getBytes().length);
        }
    }
}
