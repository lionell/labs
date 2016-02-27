package floating;

/**
 * Created by lionell on 25.02.16.
 *
 * @author Ruslan Sakevych
 */
public class App {
    public static void main(String[] args) {
        System.out.printf("%20s %15s %25s %n", "TITLE", "");
        System.out.printf("%20s %15d %n", "BITS_PER_EXPONENT = ", FloatingPoint.BITS_PER_EXPONENT);
        System.out.printf("%20s %15d %n", "BITS_PER_MANTISSA = ", FloatingPoint.BITS_PER_MANTISSA);
        System.out.printf("%20s %15s %15.10f %n", "MIN_ABS_FLOAT = ", FloatingPoint.MIN_ABS_FLOAT, FloatingPoint.MIN_ABS_FLOAT.toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "MIN_FLOAT = ", FloatingPoint.MIN_FLOAT, FloatingPoint.MIN_FLOAT.toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "MAX_FLOAT = ", FloatingPoint.MAX_FLOAT, FloatingPoint.MAX_FLOAT.toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "ONE = ", FloatingPoint.ONE, FloatingPoint.ONE.toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "POSITIVE_ZERO = ", FloatingPoint.POSITIVE_ZERO, FloatingPoint.POSITIVE_ZERO.toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "NEGATIVE_ZERO = ", FloatingPoint.NEGATIVE_ZERO, FloatingPoint.NEGATIVE_ZERO.toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "POSITIVE_INFINITY = ", FloatingPoint.POSITIVE_INFINITY, FloatingPoint.POSITIVE_INFINITY.toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "NEGATIVE_INFINITY = ", FloatingPoint.NEGATIVE_INFINITY, FloatingPoint.NEGATIVE_INFINITY.toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "NaN = ", FloatingPoint.NaN, FloatingPoint.NaN.toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "NORMAL = ", new FloatingPoint(1. / 1024), new FloatingPoint(1. / 1024).toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "NORMAL = ", new FloatingPoint(1. / 512), new FloatingPoint(1. / 512).toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "NORMAL = ", new FloatingPoint(1. / 256), new FloatingPoint(1. / 256).toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "NORMAL = ", new FloatingPoint(1. / 128), new FloatingPoint(1. / 128).toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "NORMAL = ", new FloatingPoint(1. / 64), new FloatingPoint(1. / 64).toDecimal());
        System.out.printf("%20s %15s %15.10f %n", "NORMAL = ", new FloatingPoint(1. / 32), new FloatingPoint(1. / 32).toDecimal());
    }
}
