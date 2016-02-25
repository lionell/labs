package processor;

import processor.cores.Core;
import processor.cores.TwoAddress;
import processor.exceptions.ProcessorException;
import processor.utils.Logger;
import processor.utils.StringUtils;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Processor {
    private int instructionAddressing;
    private int registerAddressing;
    private int registerCount;
    private Core core;
    private Memory memory;
    private int instructionCount;
    private boolean statusFlag;

    public Processor(int instructionAddressing, int registerAddressing, int registerCount) {
        this.instructionAddressing = instructionAddressing;
        this.registerAddressing = registerAddressing;
        this.registerCount = registerCount;
        switch (instructionAddressing) {
            case 0:
//                core = new ZeroAddress();
                break;
            case 1:
//                core = new OneAddress();
                break;
            case 2:
                core = new TwoAddress();
                break;
            case 3:
//                core = new ThreeAddress();
                break;
            default:
                throw new ProcessorException("Unknown instruction addressing.");
        }
        memory = new Memory(registerAddressing, registerCount);
        instructionCount = 0;
        statusFlag = false;
    }

    public void runInstruction(String... instruction) {
        if (instruction.length != instructionAddressing + 1) {
            throw new ProcessorException("Instruction addressing doesn't match.");
        }
        printStatus(instruction, 0);
        core.runInstruction(instruction);
        printStatus(instruction, 1);
    }

    private void printStatus(String[] instruction, int tickCount) {
        Logger.printSeparator();
        Logger.println("INS = " + StringUtils.instructionToString(instruction));
        Logger.println("PC = " + instructionCount);
        Logger.println("TC = " + tickCount);
        Logger.println("PS = " + statusFlag);
        memory.printDump();
        Logger.printSeparator();
    }

    public void run(String[][] instructions) {
        for (String[] instruction : instructions) {
            runInstruction(instruction);
        }
    }

    private void printStatus() {
//        System.out.println("Command: " + );
    }

    public int getInstructionAddressing() {
        return instructionAddressing;
    }

    public int getRegisterAddressing() {
        return registerAddressing;
    }

    public int getRegisterCount() {
        return registerCount;
    }

    public int getInstructionCount() {
        return instructionCount;
    }

    public boolean isStatusFlag() {
        return statusFlag;
    }
}
