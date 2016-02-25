package processor;

import processor.cores.Core;
import processor.memory.Memory;
import processor.misc.Instruction;
import processor.utils.Lexer;
import processor.utils.Parser;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Computer {
    private Core core;
    private Memory memory;
    private Processor processor;
    private Instruction[] instructions;

    public Computer() {
    }

    public void setCore(Core core) {
        this.core = core;
    }

    public void setMemory(Memory memory) {
        this.memory = memory;
    }

    public void prepareProcessor() {
        processor = new Processor(core, memory);
    }

    public void loadInstructions(String filename) {
        instructions = Parser.process(Lexer.process(filename));
    }

    public void runInstructions() {
        processor.runInstructions(instructions);
    }
}
