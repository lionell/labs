package processor;

import processor.cores.Core;
import processor.exceptions.ProcessorException;
import processor.memory.Memory;
import processor.misc.Instruction;
import processor.utils.io.Logger;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Processor {
    private Core core;
    private Memory memory;
    private int instructionCount;
    private boolean statusFlag;

    public Processor(Core core, Memory memory) {
        this.core = core;
        this.memory = memory;
        instructionCount = 1;
        statusFlag = false;
    }

    public void runInstruction(Instruction instruction) {
        printStatus(instruction, 1);
        statusFlag = core.runInstruction(instruction, memory);
        Logger.printSeparator();
        printStatus(instruction, 2);
        Logger.printHugeSeparator();
        instructionCount++;
    }

    private void printStatus(Instruction instruction, int tickCount) {
        Logger.println("INS = " + instruction);
        Logger.println("PC = " + instructionCount);
        Logger.println("TC = " + tickCount);
        Logger.println("PS = " + (statusFlag ? '-' : '+'));
        memory.printDump();
    }

    public void runInstructions(Instruction[] instructions) {
        for (Instruction instruction : instructions) {
            runInstruction(instruction);
        }
    }

    public int getInstructionCount() {
        return instructionCount;
    }
}
