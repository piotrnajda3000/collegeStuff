import utils.validation.Validation;
import utils.validation.ValidationException;

import java.util.ArrayList;

public class Person {
    static int totalId = 0;
    private String first, last;
    private final int id;

    private Boolean editMode = false;

    ArrayList<Project> projects = new ArrayList<>();

    public void toggleEditMode() {
        editMode = !editMode;
    }

    public String getFullName() {
        return first + " " + last;
    }

    public String getFirst() {
        return first;
    }

    public String getLast() {
        return last;
    }

    public Boolean getEditMode() {
        return editMode;
    }

    public Validation validation = new Validation();
    public int getId() {
        return id;
    }

    private void validateUserInput(String first, String last) throws ValidationException {
        Validation validation = new Validation();

        if (first.length() == 0 || last.length() == 0) {
            validation.messages.add("full name is required");
        }

        try {
            validation.validate();
        } catch (ValidationException e) {
            throw new ValidationException(e.getMessage());
        }
    }

    public String toCSV() {
        return this.first + '~' + this.last;
    }

    public Person(String first, String last) throws ValidationException  {
        validateUserInput(first, last);
        this.first = first;
        this.last = last;
        this.id = totalId++;
    }

    public void PUT(String first, String last) throws ValidationException {
        validateUserInput(first, last);
        this.first = first;
        this.last = last;
    }
}
