package processor.exceptions;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class ProcessorException extends RuntimeException {
    public ProcessorException(String message) {
        super(message);
    }

    @Override
    public String getMessage() {
        return "Processor Error: " + super.getMessage();
    }
}
