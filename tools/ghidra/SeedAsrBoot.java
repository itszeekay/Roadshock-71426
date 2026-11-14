// Seed the ASR5601S bootloader program: mark the vector table and version
// string as data, split functions that Ghidra merged across entry points, and
// create functions for every BL target in the boot code.
//
// Usage: -process boot.bin -noanalysis -postScript SeedAsrBoot.java
// @category ASR
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.DWordDataType;
import ghidra.program.model.data.StringDataType;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;

import java.util.LinkedHashSet;
import java.util.Set;

public class SeedAsrBoot extends GhidraScript {

    private static final long CODE_LO = 0x10000120L;
    private static final long CODE_HI = 0x10004ED0L;

    /** Entry points that Ghidra merged into the preceding function. */
    /** Flash copies of the RAM blob that the 0x10004Exx veneers jump to. */
    private static final long[] RAM_ENTRIES = {
        0x10000120L, // flash begin
        0x10000134L, // flash end
        0x1000014CL, // flash status
        0x1000015CL, // flash wait helper
        0x100003B8L, // second-stage main
        0x100003D8L, // image update
        0x10000450L, // flash write page
        0x10000730L, // fill helper
    };

    private static final long[] ENTRIES = {
        0x100014A0L, // boot_printf
        0x100014C4L, // reset handler (from the vector table)
        0x100014CEL, // default handler
        0x100014D0L, // startup
        0x10001614L, // image header helper
        0x1000162CL, // SystemInit
        0x10001680L, // boot command / UART setup
        0x100018A8L, // register wait helper
        0x1000193CL, // boot main
        0x10001944L, // flash region table access
        0x10001CE6L, // boot info copy
        0x10001CF8L, // boot info compare
    };

    private FunctionManager fm;



    private void dropContaining(long ea) {
        Address a = toAddr(ea);
        Function f = getFunctionContaining(a);
        if (f != null && f.getEntryPoint().getOffset() != ea) {
            fm.removeFunction(f.getEntryPoint());
        }
    }

    private void seed(long ea, String name) {
        if (ea < CODE_LO || ea > CODE_HI) {
            return;
        }
        Address a = toAddr(ea);
        try {
            if (getInstructionAt(a) == null) {
                disassemble(a);
            }
            if (getInstructionAt(a) != null && getFunctionAt(a) == null) {
                createFunction(a, name);
            }
        } catch (Exception e) {
            println("seed failed at " + a + ": " + e);
        }
    }

    private Set<Long> callTargets() {
        Set<Long> out = new LinkedHashSet<>();
        InstructionIterator it = currentProgram.getListing().getInstructions(true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            if (!ins.getFlowType().isCall()) {
                continue;
            }
            for (Address f : ins.getFlows()) {
                long v = f.getOffset();
                if (v >= CODE_LO && v <= CODE_HI) {
                    out.add(v);
                }
            }
        }
        return out;
    }

    @Override
    public void run() throws Exception {
        if (!currentProgram.getName().contains("boot")) {
            println("SeedAsrBoot: skipped " + currentProgram.getName());
            return;
        }
        fm = currentProgram.getFunctionManager();

        // The first 0x120 bytes are the vector table and the version string,
        // not code. Ghidra loaded them as one bogus function.
        Address start = toAddr(0x10000000L);
        Function vf = getFunctionAt(start);
        if (vf != null) {
            fm.removeFunction(start);
        }
        clearListing(start, toAddr(0x1000011FL));
        DataType dword = new DWordDataType();
        for (long a = 0x10000000L; a < 0x10000100L; a += 4) {
            createData(toAddr(a), dword);
        }
        DataType str = new StringDataType();
        createData(toAddr(0x10000100L), str);
        createLabel(toAddr(0x10000000L), "boot_vector_table", true);

        // Split functions Ghidra merged across real entry points.
        for (long e : ENTRIES) {
            dropContaining(e);
        }

        for (long e : RAM_ENTRIES) {
            seed(e, null);
        }
        for (long e : ENTRIES) {
            seed(e, null);
        }

        // Pull in every call target, then repeat because new code adds calls.
        int before = 0;
        for (int pass = 0; pass < 6; pass++) {
            Set<Long> targets = callTargets();
            int made = 0;
            for (long t : targets) {
                if (getFunctionAt(toAddr(t)) == null) {
                    seed(t, null);
                    if (getFunctionAt(toAddr(t)) != null) {
                        made++;
                    }
                }
            }
            println("SeedAsrBoot pass " + pass + ": targets=" + targets.size()
                    + " new=" + made);
            if (made == 0 && targets.size() == before) {
                break;
            }
            before = targets.size();
        }

        // Switch jump-table case blocks are reached with BL in Thumb code but
        // are not separate functions. Drop the ones the seeding pass created.
        int dropped = 0;
        java.util.List<Function> bogus = new java.util.ArrayList<>();
        for (Function f : fm.getFunctions(true)) {
            long ea = f.getEntryPoint().getOffset();
            if (ea >= CODE_LO && ea <= CODE_HI
                    && (f.getName().startsWith("caseD_")
                        || f.getName().startsWith("switchD_"))) {
                bogus.add(f);
            }
        }
        for (Function f : bogus) {
            fm.removeFunction(f.getEntryPoint());
            dropped++;
        }
        println("SeedAsrBoot: dropped " + dropped + " switch case blocks");

        int funcs = 0;
        for (Function f : fm.getFunctions(true)) {
            if (f.getEntryPoint().getOffset() >= CODE_LO
                    && f.getEntryPoint().getOffset() <= CODE_HI) {
                funcs++;
            }
        }
        println("SeedAsrBoot: functions in boot code = " + funcs);
    }
}
