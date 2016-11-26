package processor.cores;

import processor.exceptions.CoreException;
import processor.memory.Memory;
import processor.misc.Complement;
import processor.misc.Instruction;
import processor.misc.operands.Operand;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class TwoAddress extends Core {
    public TwoAddress() {
        super(2);
    }

    @Override
    public boolean runInstruction(Instruction instruction, Memory memory) {
        switch (instruction.getType()) {
            case MOV:
                return processMov(instruction.getOperand(0), instruction.getOperand(1), memory);
            case ADD:
                return processAdd(instruction.getOperand(0), instruction.getOperand(1), memory);
            case SUB:
                return processSub(instruction.getOperand(0), instruction.getOperand(1), memory);
            case LLSH:
                return processLlsh(instruction.getOperand(0), instruction.getOperand(1), memory);
            case LRSH:
                return processLrsh(instruction.getOperand(0), instruction.getOperand(1), memory);
            case ALSH:
                return processAlsh(instruction.getOperand(0), instruction.getOperand(1), memory);
            case ARSH:
                return processArsh(instruction.getOperand(0), instruction.getOperand(1), memory);
            case CLSH:
                return processClsh(instruction.getOperand(0), instruction.getOperand(1), memory);
            case CRSH:
                return processCrsh(instruction.getOperand(0), instruction.getOperand(1), memory);
            case XOR:
                return processXor(instruction.getOperand(0), instruction.getOperand(1), memory);
            case MOD:
                return processMod(instruction.getOperand(0), instruction.getOperand(1), memory);
            case AND:
                return processAnd(instruction.getOperand(0), instruction.getOperand(1), memory);
            case OR:
                return processOr(instruction.getOperand(0), instruction.getOperand(1), memory);
            default:
                throw new CoreException("Unknown instruction.");
        }
    }

    private boolean processAdd(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.add(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }

    private boolean processSub(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.sub(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }

    private boolean processLlsh(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.llsh(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }

    private boolean processLrsh(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.lrsh(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }

    private boolean processAlsh(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.alsh(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }

    private boolean processArsh(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.arsh(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }

    private boolean processClsh(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.clsh(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }

    private boolean processCrsh(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.crsh(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }

    private boolean processXor(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.xor(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }

    private boolean processMod(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.mod(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }

    private boolean processAnd(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.and(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }

    private boolean processOr(Operand a, Operand b, Memory memory) {
        checkAddresses(a, b);
        int[] aData = memory.getData(a.getData());
        int[] bData = memory.getData(b.getData());
        int[] cData = Complement.or(aData, bData);
        memory.setRegister(b.getData(), cData);
        return Complement.isNegative(cData);
    }
}
