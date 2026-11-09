// List function names and comments for review.
// Usage: -postScript ListAnnotations.java
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class ListAnnotations extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionIterator fit = currentProgram.getListing().getFunctions(true);
        while (fit.hasNext()) {
            Function f = fit.next();
            long ea = f.getEntryPoint().getOffset();
            String name = f.getName();
            String comment = f.getComment();
            String plate = currentProgram.getListing().getComment(1, f.getEntryPoint());
            boolean interesting = comment != null || plate != null ||
                (!name.startsWith("sub_") && !name.startsWith("FUN_") &&
                 !name.startsWith("gap_") && !name.startsWith("ret_") &&
                 !name.startsWith("x_") && !name.startsWith("thunk_") &&
                 !name.startsWith("vec_") && !name.startsWith("VEC"));
            if (interesting) {
                println(String.format("0x%04x %s", ea, name));
                if (comment != null) println("    comment: " + comment);
                if (plate != null) println("    plate: " + plate);
            }
        }
    }
}
