package processor.misc;

import processor.misc.operands.Operand;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Instruction {
    private Instructions type;
    private Operand[] operands;

    public Instruction(Instructions type, Operand[] operands) {
        this.type = type;
        this.operands = operands;
    }

    public Instructions getType() {
        return type;
    }

    public Operand getOperand(int index) {
        return operands[index];
    }

    public int getAddressing() {
        return operands.length;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append(type);
        for (Operand operand : operands) {
            builder.append(" | ");
            builder.append(operand);
        }
        return builder.toString();
    }
}
