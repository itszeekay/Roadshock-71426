// minimal compile test
import ghidra.app.script.GhidraScript;

public class Probe extends GhidraScript {
    @Override
    public void run() throws Exception {
        println("PROBE OK base=" + currentProgram.getImageBase());
    }
}
