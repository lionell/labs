package floating;

import java.util.ArrayList;
import java.util.Collections;

/**
 * Created by lionell on 25.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Native {
    public static ArrayList<Integer> toIntBits(float decimal) {
        int binary = Float.floatToRawIntBits(decimal);
        ArrayList<Integer> bits = new ArrayList<>();
        while (binary > 0) {
            bits.add(binary % 2);
            binary /= 2;
        }
        Collections.reverse(bits);
        return bits;
    }
}
