package floating;

import java.util.ArrayList;

/**
 * Created by lionell on 25.02.16.
 *
 * @author Ruslan Sakevych
 */
public class FloatingPoint {
    private ArrayList<Integer> bits;
    public static final int BITS_PER_EXPONENT = 3;
    public static final int BITS_PER_MANTISSA = 4;
    public static final int EXPONENT_SHIFT = (1 << (BITS_PER_EXPONENT - 1)) - 1;

    public static final FloatingPoint MIN_ABS_FLOAT = new FloatingPoint() {
        {
            ArrayList<Integer> exponentBits = BinaryUtils.getFilled(BITS_PER_EXPONENT, 0);
            ArrayList<Integer> mantissaBits = BinaryUtils.getFilled(BITS_PER_MANTISSA, 0);
            mantissaBits.set(mantissaBits.size() - 1, 1);
            setBits(combine(0, exponentBits, mantissaBits));
        }
    };
    public static final FloatingPoint MIN_FLOAT = new FloatingPoint() {
        {
            ArrayList<Integer> exponentBits = BinaryUtils.fromInteger((1 << BITS_PER_EXPONENT) - 2, BITS_PER_EXPONENT);
            ArrayList<Integer> mantissaBits = BinaryUtils.getFilled(BITS_PER_MANTISSA, 1);
            setBits(combine(1, exponentBits, mantissaBits));
        }
    };
    public static final FloatingPoint MAX_FLOAT = new FloatingPoint() {
        {
            ArrayList<Integer> exponentBits = BinaryUtils.fromInteger((1 << BITS_PER_EXPONENT) - 2, BITS_PER_EXPONENT);
            ArrayList<Integer> mantissaBits = BinaryUtils.getFilled(BITS_PER_MANTISSA, 1);
            setBits(combine(0, exponentBits, mantissaBits));
        }
    };
    public static final FloatingPoint ONE = new FloatingPoint() {
        {
            ArrayList<Integer> exponentBits = BinaryUtils.fromInteger(EXPONENT_SHIFT + 1, BITS_PER_EXPONENT);
            ArrayList<Integer> mantissaBits = BinaryUtils.getFilled(BITS_PER_MANTISSA, 0);
            setBits(combine(0, exponentBits, mantissaBits));
        }
    };
    public static final FloatingPoint POSITIVE_ZERO = new FloatingPoint() {
        {
            ArrayList<Integer> exponentBits = BinaryUtils.getFilled(BITS_PER_EXPONENT, 0);
            ArrayList<Integer> mantissaBits = BinaryUtils.getFilled(BITS_PER_MANTISSA, 0);
            setBits(combine(0, exponentBits, mantissaBits));
        }
    };
    public static final FloatingPoint NEGATIVE_ZERO = new FloatingPoint() {
        {
            ArrayList<Integer> exponentBits = BinaryUtils.getFilled(BITS_PER_EXPONENT, 0);
            ArrayList<Integer> mantissaBits = BinaryUtils.getFilled(BITS_PER_MANTISSA, 0);
            setBits(combine(1, exponentBits, mantissaBits));
        }
    };
    public static final FloatingPoint POSITIVE_INFINITY = new FloatingPoint(Double.POSITIVE_INFINITY);
    public static final FloatingPoint NEGATIVE_INFINITY = new FloatingPoint(Double.NEGATIVE_INFINITY);
    public static final FloatingPoint NaN = new FloatingPoint(Double.NaN);

    private FloatingPoint() {
    }

    public FloatingPoint(double decimal) {
        int sign = BinaryUtils.getRandomBit();
        ArrayList<Integer> exponentBits = new ArrayList<>();
        ArrayList<Integer> mantissaBits = new ArrayList<>();
        if (Double.isNaN(decimal)) {
            exponentBits = BinaryUtils.getFilled(BITS_PER_EXPONENT, 1);
            mantissaBits = BinaryUtils.getRandomNotNull(BITS_PER_MANTISSA);
        } else if (Double.isInfinite(decimal)) {
            sign = decimal == Double.POSITIVE_INFINITY ? 0 : 1;
            exponentBits = BinaryUtils.getFilled(BITS_PER_EXPONENT, 1);
            mantissaBits = BinaryUtils.getFilled(BITS_PER_MANTISSA, 0);
        } else if (Double.compare(decimal, Math.pow(2.0, -(EXPONENT_SHIFT + BITS_PER_MANTISSA - 1))) == -1) {
            exponentBits = BinaryUtils.getFilled(BITS_PER_EXPONENT, 0);
            mantissaBits = BinaryUtils.getFilled(BITS_PER_MANTISSA, 0);
        } else if (Double.compare(decimal, Math.pow(2.0, -(EXPONENT_SHIFT - 1))) == -1) {
            // subnormal
            sign = Double.compare(decimal, 0) == -1 ? 1 : 0;
            decimal = Math.abs(decimal);
            decimal *= Math.pow(2.0, EXPONENT_SHIFT - 1);
            exponentBits = BinaryUtils.getFilled(BITS_PER_EXPONENT, 0);
            mantissaBits = BinaryUtils.fromFraction(decimal, BITS_PER_MANTISSA);
        } else {
            sign = Double.compare(decimal, 0) == -1 ? 1 : 0;
            decimal = Math.abs(decimal);
            int integer = (int) decimal;
            double fraction = decimal - integer;
            ArrayList<Integer> integerBits = BinaryUtils.fromInteger(integer);
            int exponent = Math.max(integerBits.size() - 1, 0);
            ArrayList<Integer> fractionBits = BinaryUtils.fromFraction(fraction, 2 * BITS_PER_MANTISSA);
            // normalizing
            mantissaBits.addAll(integerBits);
            mantissaBits.addAll(fractionBits);
            while (mantissaBits.get(0) != 1) {
                mantissaBits.remove(0);
                exponent--;
            }
            mantissaBits.remove(0);
            while (mantissaBits.size() < BITS_PER_MANTISSA) {
                mantissaBits.add(0);
            }
            while (mantissaBits.size() > BITS_PER_MANTISSA) {
                mantissaBits.remove(mantissaBits.size() - 1);
            }
            // prepare exponent
            exponent += EXPONENT_SHIFT;
            exponentBits = BinaryUtils.fromInteger(exponent, BITS_PER_EXPONENT);
        }
        bits = combine(sign, exponentBits, mantissaBits);
    }

    public FloatingPoint(String decimalString) {
        this(Double.parseDouble(decimalString));
    }

    private static ArrayList<Integer> combine(int sign, ArrayList<Integer> exponentBits, ArrayList<Integer> mantissaBits) {
        ArrayList<Integer> bits = new ArrayList<>();
        bits.add(sign);
        bits.addAll(exponentBits);
        bits.addAll(mantissaBits);
        return bits;
    }

    public ArrayList<Integer> getBits() {
        return bits;
    }

    public void setBits(ArrayList<Integer> bits) {
        this.bits = bits;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append(bits.get(0));
        builder.append(' ');
        for (int i = 1; i <= BITS_PER_EXPONENT; i++) {
            builder.append(bits.get(i));
        }
        builder.append(" (");
        builder.append(BinaryUtils.isZero(bits.subList(1, BITS_PER_EXPONENT + 1)) ? "0" : "1");
        builder.append(")");
        for (int i = 1 + BITS_PER_EXPONENT; i < bits.size(); i++) {
            builder.append(bits.get(i));
        }
        return builder.toString();
    }
}
