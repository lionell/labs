package processor.cores;

import processor.exceptions.CoreException;
import processor.memory.Memory;
import processor.misc.Complement;
import processor.misc.Instruction;
import processor.misc.operands.Operand;
import processor.misc.operands.Operands;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public abstract class Core {
    protected int instructionAddressing;

    public Core(int instructionAddressing) {
        this.instructionAddressing = instructionAddressing;
    }

    public abstract boolean runInstruction(Instruction instruction, Memory memory);

    protected boolean processMov(Operand a, Operand b, Memory memory) {
        checkAddresses(b);
        int[] aData;
        if (a.getType() == Operands.Address) {
            aData = memory.getRegister(a.getData()).getData();
        } else {
            aData = Complement.fromDecimal(a.getData(), memory.getRegisterAddressing());
        }
        memory.setRegister(b.getData(), aData);
        return Complement.isNegative(aData);
    }

    protected void checkAddresses(Operand... operands) {
        for (Operand operand : operands) {
            if (operand.getType() != Operands.Address) {
                throw new CoreException("Operand should be address.");
            }
        }
    }

    public int getInstructionAddressing() {
        return instructionAddressing;
    }
}
