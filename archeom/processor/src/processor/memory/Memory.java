package processor.memory;

import processor.exceptions.MemoryException;
import processor.utils.io.Logger;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Memory {
    private int registerAddressing;
    private int registerCount;
    private Register[] registers;

    public Memory(int registerAddressing, int registerCount) {
        this.registerAddressing = registerAddressing;
        this.registerCount = registerCount;
        registers = new Register[registerCount];
        for (int i = 0; i < registerCount; i++) {
            registers[i] = new Register(registerAddressing);
        }
    }

    public void printDump() {
        for (int i = 0; i < registers.length; i++) {
            Logger.println("R" + i + " = " + registers[i]);
        }
    }

    public Register getRegister(int index) {
        if (index < 0 || index >= registerCount) {
            throw new MemoryException("Invalid index.");
        }
        return registers[index];
    }

    public int[] getData(int index) {
        return getRegister(index).getData();
    }

    public void setRegister(int index, int[] data) {
        if (index < 0 || index >= registerCount) {
            throw new MemoryException("Invalid index.");
        }
        registers[index].setData(data);
    }

    public int getRegisterAddressing() {
        return registerAddressing;
    }

    public int getRegisterCount() {
        return registerCount;
    }
}
