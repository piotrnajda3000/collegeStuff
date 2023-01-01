public class SomeClass {
    int id;

    private static int count = 0;
    public SomeClass() {
        this.id = count++;
    }
}
