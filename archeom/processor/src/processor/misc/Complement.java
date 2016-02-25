package processor.misc;

import processor.exceptions.ComplementException;

/**
 * Created by lionell on 25.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Complement {
    public static int[] fromDecimal(int decimal, int addressing) {
        int[] complement = toComplement(Math.abs(decimal), addressing);
        if (decimal < 0) {
            complement = negate(complement);
        }
        return complement;
    }

    private static int[] toComplement(int integer, int addressing) {
        int[] complement = new int[addressing];
        int i = addressing - 1;
        while (integer > 0) {
            complement[i] = integer % 2;
            integer /= 2;
            i--;
        }
        return complement;
    }

    private static int toDecimal(int[] complement) {
        int[] clone = complement.clone();
        if (isNegative(clone)) {
            clone = negate(clone);
        }
        int decimal = 0;
        int registerAddressing = clone.length;
        for (int i = registerAddressing - 1; i >= 0; i--) {
            decimal += clone[i] * (1 << (registerAddressing - 1 - i));
        }
        return decimal;
    }

    public static int[] negate(int[] complement) {
        int[] clone = complement.clone();
        int addressing = clone.length;
        for (int i = 0; i < addressing; i++) {
            clone[i] = 1 - clone[i];
        }
        int i = addressing - 1;
        clone[i]++;
        while (i > 0 && clone[i] > 1) {
            clone[i] = 0;
            clone[i - 1]++;
            i--;
        }
        if (clone[0] > 1) {
            clone[0] = 0;
        }
        return clone;
    }

    public static int[] add(int[] a, int[] b) {
        if (a.length != b.length) {
            throw new ComplementException("Operand sizes doesn't match.");
        }
        int registerAddressing = a.length;
        int[] c = new int[registerAddressing];
        for (int i = registerAddressing - 1; i > 0; i--) {
            c[i] += a[i] + b[i];
            if (c[i] > 1) {
                c[i] -= 2;
                c[i - 1]++;
            }
        }
        c[0] += a[0] + b[0];
        if (c[0] > 1) {
            c[0] -= 2;
        }
        return c;
    }

    public static int[] sub(int[] a, int[] b) {
        if (a.length != b.length) {
            throw new ComplementException("Operand sizes doesn't match.");
        }
        int[] aNegative = a.clone();
        negate(aNegative);
        return add(b, aNegative);
    }

    public static int[] lsh(int[] a, int b) {
        int registerAddressing = a.length;
        int[] c = new int[registerAddressing];
        System.arraycopy(a, b, c, 0, registerAddressing - b);
        return c;
    }

    public static int[] rsh(int[] a, int b) {
        int registerAddressing = a.length;
        int[] c = new int[registerAddressing];
        System.arraycopy(a, 0, c, b, registerAddressing - b);
        return c;
    }

    public static int[] llsh(int[] a, int[] b) {
        int registerAddressing = a.length;
        int aDec = toDecimal(a);
        int[] c = lsh(b, aDec);
        for (int i = registerAddressing - 1; i > registerAddressing - 1 - aDec; i--) {
            c[i] = 0;
        }
        return c;
    }

    public static int[] lrsh(int[] a, int[] b) {
        int aDec = toDecimal(a);
        int[] c = rsh(b, aDec);
        for (int i = 0; i < aDec; i++) {
            c[i] = 0;
        }
        return c;
    }

    public static int[] alsh(int[] a, int[] b) {
        return llsh(a, b);
    }

    public static int[] arsh(int[] a, int[] b) {
        int aDec = toDecimal(a);
        int[] c = rsh(b, aDec);
        for (int i = 0; i < aDec; i++) {
            c[i] = b[0];
        }
        return c;
    }

    public static int[] clsh(int[] a, int[] b) {
        int registerAddressing = a.length;
        int aDec = toDecimal(a);
        int[] c = lsh(b, aDec);
        for (int i = registerAddressing - 1; i > registerAddressing - 1 - aDec; i--) {
            c[i] = b[registerAddressing - 1 - i];
        }
        return c;
    }

    public static int[] crsh(int[] a, int[] b) {
        int registerAddressing = a.length;
        int aDec = toDecimal(a);
        int[] c = rsh(b, aDec);
        for (int i = 0; i < aDec; i++) {
            c[i] = b[registerAddressing - aDec + i];
        }
        return c;
    }

    public static int[] xor(int[] a, int[] b) {
        if (a.length != b.length) {
            throw new ComplementException("Operand sizes doesn't match.");
        }
        int registerAddressing = a.length;
        int[] c = new int[registerAddressing];
        for (int i = registerAddressing - 1; i >= 0; i--) {
            c[i] = (a[i] + b[i]) % 2;
        }
        return c;
    }

    public static int[] mod(int[] a, int[] b) {
        if (a.length != b.length) {
            throw new ComplementException("Operand sizes doesn't match.");
        }
        int registerAddressing = a.length;
        int aDec = toDecimal(a);
        int bDec = toDecimal(b);
        return fromDecimal(bDec % aDec, registerAddressing);
    }

    public static int[] and(int[] a, int[] b) {
        if (a.length != b.length) {
            throw new ComplementException("Operand sizes doesn't match.");
        }
        int registerAddressing = a.length;
        int[] c = new int[registerAddressing];
        for (int i = registerAddressing - 1; i >= 0; i--) {
            c[i] = (a[i] + b[i] == 2) ? 1 : 0;
        }
        return c;
    }

    public static int[] or(int[] a, int[] b) {
        if (a.length != b.length) {
            throw new ComplementException("Operand sizes doesn't match.");
        }
        int registerAddressing = a.length;
        int[] c = new int[registerAddressing];
        for (int i = registerAddressing - 1; i >= 0; i--) {
            c[i] = (a[i] + b[i] > 0) ? 1 : 0;
        }
        return c;
    }

    public static boolean isNegative(int[] complement) {
        return complement[0] == 1;
    }
}
