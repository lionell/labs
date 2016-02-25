package processor;

import processor.cores.ThreeAddress;
import processor.memory.Memory;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class App {
    public static void main(String[] args) {
        Computer computer = new Computer();
        computer.setCore(new ThreeAddress());
        computer.setMemory(new Memory(8, 3));
        computer.prepareProcessor();
        computer.loadInstructions("res/three_core_example.llp");
        computer.runInstructions();
    }
}
