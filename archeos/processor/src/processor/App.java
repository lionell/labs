package processor;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class App {
    public static void main(String[] args) {
        Processor processor = new Processor(2, 8, 2);
        processor.runInstruction("mov", "1", "R2");
        processor.runInstruction("add", "1", "R2");
    }
}
