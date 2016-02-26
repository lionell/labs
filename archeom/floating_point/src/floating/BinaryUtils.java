package floating;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

/**
 * Created by lionell on 26.02.16.
 *
 * @author Ruslan Sakevych
 */
public class BinaryUtils {
    private static Random random = new Random();

    public static ArrayList<Integer> fromFraction(double decimal, int size) {
        ArrayList<Integer> bits = new ArrayList<>(size);
        while (bits.size() < size) {
            decimal *= 2.;
            bits.add((int) decimal);
            decimal = decimal - (int) decimal;
        }
        return bits;
    }

    public static ArrayList<Integer> fromInteger(int decimal, int size) {
        ArrayList<Integer> bits = new ArrayList<>(size);
        while (bits.size() < size) {
            bits.add(decimal % 2);
            decimal /= 2;
        }
        Collections.reverse(bits);
        return bits;
    }

    public static ArrayList<Integer> fromInteger(int decimal) {
        ArrayList<Integer> bits = new ArrayList<>();
        if (decimal == 0) {
            bits.add(0);
            return bits;
        }
        while (decimal > 0) {
            bits.add(decimal % 2);
            decimal /= 2;
        }
        Collections.reverse(bits);
        return bits;
    }

    public static ArrayList<Integer> getFilled(int size, int pattern) {
        return new ArrayList<>(Collections.nCopies(size, pattern));
    }

    public static ArrayList<Integer> getRandom(int size) {
        ArrayList<Integer> result = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            result.add(getRandomBit());
        }
        return result;
    }

    public static ArrayList<Integer> getRandomNotNull(int size) {
        ArrayList<Integer> result = getRandom(size);
        result.set(0, 1);
        return result;
    }

    public static int getRandomBit() {
        return random.nextInt(2);
    }

    public static boolean isZero(List<Integer> bits) {
        for (int bit : bits) {
            if (bit != 0) {
                return false;
            }
        }
        return true;
    }
}
