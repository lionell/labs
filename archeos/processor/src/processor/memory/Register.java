package processor.memory;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Register {
    private int addressing;
    private int[] data;

    public Register(int addressing) {
        this.addressing = addressing;
        data = new int[addressing];
    }

    public int[] getData() {
        return data;
    }

    public int getAddressing() {
        return addressing;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < data.length; i++) {
            if (i > 0 && i % 4 == 0) {
                builder.append(" ");
            }
            builder.append(data[i]);
        }
        return builder.toString();
    }
}
