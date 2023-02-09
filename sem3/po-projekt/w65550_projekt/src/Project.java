import utils.validation.Validation;
import utils.validation.ValidationException;

public class Project {
    private String nazwa, opis;
    private final int id;

    private Boolean editMode = false;

    public void toggleEditMode() {
        editMode = !editMode;
    }

    public Boolean getEditMode() {
        return editMode;
    }

    public Validation validation = new Validation();
    public int getId() {
        return id;
    }

    public String getNazwa() {
        return nazwa;
    }

    public String getOpis() {
        return opis;
    }

    private void validateUserInput(String nazwa, String opis) throws ValidationException {
        Validation validation = new Validation();

        if (nazwa.length() == 0) {
            validation.messages.add("name is required");
        }

        if (opis.length() == 0) {
            validation.messages.add("description is required");
        }

        if (nazwa.length() > 30) {
            validation.messages.add("name can't be longer than 30 characters");
        }
        if (opis.length() > 100) {
            validation.messages.add("description can't be longer than 100 characters");
        }

        try {
            validation.validate();
        } catch (ValidationException e) {
            throw new ValidationException(e.getMessage());
        }
    }

    public String toCSV() {
        return this.id + "~" + this.nazwa + '~' + this.opis;
    }

    public Project(int id, String nazwa, String opis) throws ValidationException  {
        validateUserInput(nazwa, opis);
        this.nazwa = nazwa;
        this.opis = opis;
        this.id = id;
    }

    public void PUT(String nazwa, String opis) throws ValidationException {
        validateUserInput(nazwa, opis);
        this.nazwa = nazwa;
        this.opis = opis;
    }
}
