package utils.validation;
import utils.Utils;
import java.util.ArrayList;

/**
 * 1. Create new instance
 * 2. Add validation messages based on conditions
 * 3. Use validate method to see if inputs are correct
 * Example usage in Person and Project classes
 */
public class Validation {
    public ArrayList<String> messages = new ArrayList<>();
    private String message = "";
    public String getMessage() {
        if (messages.size() > 0) {
            String firstMessage = messages.get(0);
            messages.set(0, Utils.capitalizeFirstLetter(firstMessage));
            message = String.join(", ", messages);
            message += ".";
        }
        setMessage(message);
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public void validate() throws ValidationException {
        if (getMessage().length() > 0) {
            throw new ValidationException(message);
        }
    }

    public Validation() {
    }
}
