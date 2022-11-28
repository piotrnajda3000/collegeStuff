package Zad3;

public class Powiesc extends Ksiazka {
    String seria;

    public Powiesc(String tytul, int rokWydania) {
        super(tytul, rokWydania);
    }

    public Powiesc(String tytul, int rokWydania, String seria) {
        super(tytul, rokWydania);
        this.seria = seria;
    }

    @Override
    public String toString() {
        return "Powiesc{" +
                "seria='" + seria + '\'' +
                ", tytul='" + tytul + '\'' +
                ", rokWydania=" + rokWydania +
                '}';
    }
}
