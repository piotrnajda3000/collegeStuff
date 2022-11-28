package Zad3;

public class Ksiazka {
    String tytul;
    int rokWydania;

    public Ksiazka(String tytul, int rokWydania) {
        this.tytul = tytul;
        this.rokWydania = rokWydania;
    }

    public String getTytul() {
        return tytul;
    }

    public void setTytul(String tytul) {
        this.tytul = tytul;
    }

    public int getRokWydania() {
        return rokWydania;
    }

    public void setRokWydania(int rokWydania) {
        this.rokWydania = rokWydania;
    }

    @Override
    public String toString() {
        return "Ksiazka{" +
                "tytul='" + tytul + '\'' +
                ", rokWydania=" + rokWydania +
                '}';
    }
}
