package processor;

import processor.cores.TwoAddress;
import processor.memory.Memory;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class App {
    public static void main(String[] args) {
        Computer computer = new Computer();
        computer.setCore(new TwoAddress());
        computer.setMemory(new Memory(16, 3));
        computer.prepareProcessor();
        computer.loadInstructions("res/two_core_example.llp");
        computer.runInstructions();
    }
}
