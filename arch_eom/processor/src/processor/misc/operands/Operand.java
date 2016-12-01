package processor.misc.operands;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Operand {
    protected Operands type;
    protected int data;

    public Operand(Operands type, int data) {
        this.type = type;
        this.data = data;
    }

    public Operands getType() {
        return type;
    }

    public int getData() {
        return data;
    }

    @Override
    public String toString() {
        return (type == Operands.Address ? "R" : "") + data;
    }
}
