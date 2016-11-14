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

    public static List<Integer> fromFraction(double decimal, int size) {
        List<Integer> bits = new ArrayList<>(size);
        while (bits.size() < size) {
            decimal *= 2.;
            bits.add((int) decimal);
            decimal = decimal - (int) decimal;
        }
        return bits;
    }

    public static List<Integer> fromInteger(int decimal, int size) {
        List<Integer> bits = new ArrayList<>(size);
        while (bits.size() < size) {
            bits.add(decimal % 2);
            decimal /= 2;
        }
        Collections.reverse(bits);
        return bits;
    }

    public static List<Integer> fromInteger(int decimal) {
        List<Integer> bits = new ArrayList<>();
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

    public static int toDecimal(List<Integer> bits) {
        int result = 0;
        int p = 1;
        for (int i = bits.size() - 1; i >= 0; i--) {
            result += bits.get(i) * p;
            p *= 2;
        }
        return result;
    }

    public static List<Integer> getFilled(int size, int pattern) {
        return new ArrayList<>(Collections.nCopies(size, pattern));
    }

    public static List<Integer> getRandom(int size) {
        List<Integer> result = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            result.add(getRandomBit());
        }
        return result;
    }

    public static List<Integer> getRandomNotNull(int size) {
        List<Integer> result = getRandom(size);
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

    public static boolean isOne(List<Integer> bits) {
        for (int bit : bits) {
            if (bit != 1) {
                return false;
            }
        }
        return true;
    }

    public static List<Integer> combine(int sign, List<Integer> exponentBits, List<Integer> mantissaBits) {
        List<Integer> bits = new ArrayList<>();
        bits.add(sign);
        bits.addAll(exponentBits);
        bits.addAll(mantissaBits);
        return bits;
    }
}
