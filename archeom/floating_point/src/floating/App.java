package floating;

/**
 * Created by lionell on 25.02.16.
 *
 * @author Ruslan Sakevych
 */
public class App {
    public static void main(String[] args) {
        System.out.printf("%20s %15d%n", "BITS_PER_EXPONENT = ", FloatingPoint.BITS_PER_EXPONENT);
        System.out.printf("%20s %15d%n", "BITS_PER_MANTISSA = ", FloatingPoint.BITS_PER_MANTISSA);
        System.out.printf("%20s %15s%n", "MIN_ABS_FLOAT = ", FloatingPoint.MIN_ABS_FLOAT);
        System.out.printf("%20s %15s%n", "MIN_FLOAT = ", FloatingPoint.MIN_FLOAT);
        System.out.printf("%20s %15s%n", "MAX_FLOAT = ", FloatingPoint.MAX_FLOAT);
        System.out.printf("%20s %15s%n", "ONE = ", FloatingPoint.ONE);
        System.out.printf("%20s %15s%n", "POSITIVE_ZERO = ", FloatingPoint.POSITIVE_ZERO);
        System.out.printf("%20s %15s%n", "NEGATIVE_ZERO = ", FloatingPoint.NEGATIVE_ZERO);
        System.out.printf("%20s %15s%n", "POSITIVE_INFINITY = ", FloatingPoint.POSITIVE_INFINITY);
        System.out.printf("%20s %15s%n", "NEGATIVE_INFINITY = ", FloatingPoint.NEGATIVE_INFINITY);
        System.out.printf("%20s %15s%n", "NaN = ", FloatingPoint.NaN);
        System.out.printf("%20s %15s%n", "SUBNORMAL = ", new FloatingPoint(1. / 64));
    }
}
