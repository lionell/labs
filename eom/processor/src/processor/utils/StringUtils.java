package processor.utils;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class StringUtils {
    public static String convertToString(int[] digits) {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < digits.length; i++) {
            if (i > 0 && i % 4 == 0) {
                builder.append(" ");
            }
            builder.append(digits[i]);
        }
        return builder.toString();
    }
}
