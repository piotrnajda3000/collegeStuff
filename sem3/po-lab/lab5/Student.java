public class Student extends Osoba {

    String nrAlbumu;

    public Student(String firstName, String lastName, int age, String nrAlbumu) {
        super(firstName, lastName, age);
        this.nrAlbumu = nrAlbumu;
    }
}
