package Zad3;

public class Podrecznik extends Ksiazka {

    String przedmiot;

    public Podrecznik(String tytul, int rokWydania) {
        super(tytul, rokWydania);
    }

    public Podrecznik(String tytul, int rokWydania, String przedmiot) {
        super(tytul, rokWydania);
        this.przedmiot = przedmiot;
    }

    public String getPrzedmiot() {
        return przedmiot;
    }

    public void setPrzedmiot(String przedmiot) {
        this.przedmiot = przedmiot;
    }

    @Override
    public String toString() {
        return "Podrecznik{" +
                "przedmiot='" + przedmiot + '\'' +
                ", tytul='" + tytul + '\'' +
                ", rokWydania=" + rokWydania +
                '}';
    }
}

