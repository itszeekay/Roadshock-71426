// Print program info and a checksum of the flash image.
// Usage: -postScript DumpInfo.java
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.MemoryBlock;
import java.security.MessageDigest;

public class DumpInfo extends GhidraScript {
    @Override
    public void run() throws Exception {
        println("program: " + currentProgram.getName());
        println("language: " + currentProgram.getLanguageID());
        println("compiler: " + currentProgram.getCompilerSpec().getCompilerSpecID());
        MemoryBlock b = currentProgram.getMemory().getBlock(toAddr(0x8000));
        if (b == null) {
            println("no block at 0x8000");
            return;
        }
        println("block: " + b.getName() + " start=" + b.getStart() + " size=" + b.getSize());
        byte[] data = new byte[(int) b.getSize()];
        b.getBytes(toAddr(0x8000), data);
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] hash = md.digest(data);
        StringBuilder sb = new StringBuilder();
        for (byte x : hash) sb.append(String.format("%02x", x));
        println("sha256(0x8000.." + (0x8000 + b.getSize()) + "): " + sb);
        // first 16 bytes
        StringBuilder fb = new StringBuilder();
        for (int i = 0; i < 16 && i < data.length; i++) fb.append(String.format("%02x ", data[i]));
        println("first16: " + fb);
    }
}
