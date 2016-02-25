package processor.exceptions;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class ComplementException extends RuntimeException {
    public ComplementException(String message) {
        super(message);
    }

    @Override
    public String getMessage() {
        return "Complement Error: " + super.getMessage();
    }
}
