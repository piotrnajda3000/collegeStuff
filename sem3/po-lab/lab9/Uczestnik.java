import java.util.Objects;

public class Uczestnik {
    private static int idCount = 0;
    int id, age;
    String firstName, lastName;

    public int getAge() {
        return age;
    }

    public Uczestnik(int age, String firstName, String lastName) {
        this.id = idCount++;
        this.age = age;
        this.firstName = firstName;
        this.lastName = lastName;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Uczestnik that = (Uczestnik) o;
        return id == that.id && age == that.age && Objects.equals(firstName, that.firstName) && Objects.equals(lastName, that.lastName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, age, firstName, lastName);
    }

    @Override
    public String toString() {
        return "Uczestnik{" +
                "id=" + id +
                ", age=" + age +
                ", firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                '}';
    }
}
