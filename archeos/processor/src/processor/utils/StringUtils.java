package processor.utils;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class StringUtils {
    public static String instructionToString(String... instruction) {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < instruction.length - 1; i++) {
            builder.append(instruction[i]);
            builder.append(" | ");
        }
        builder.append(instruction[instruction.length - 1]);
        return builder.toString();
    }
}
