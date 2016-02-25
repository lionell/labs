package processor.memory;

import processor.utils.StringUtils;

import java.util.Random;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Register {
    private int[] data;

    public Register(int addressing) {
        Random random = new Random();
        data = new int[addressing];
        for (int i = 0; i < addressing; i++) {
            data[i] = random.nextInt(2);
        }
    }

    public int[] getData() {
        return data;
    }

    public void setData(int[] data) {
        this.data = data.clone();
    }

    public int getAddressing() {
        return data.length;
    }

    @Override
    public String toString() {
        return StringUtils.convertToString(data);
    }
}
