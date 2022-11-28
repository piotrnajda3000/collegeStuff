package Zad3;

import java.util.Arrays;
import java.util.stream.Stream;

public class Klient {
    String imie;
    int pieniadze;

    public Klient(String imie, int pieniadze) {
        this.imie = imie;
        this.pieniadze = pieniadze;
    }

    public Boolean sprawdzKsiazke(Ksiegarnia ksiegarnia, String tytul) {
        for (Ksiazka k : ksiegarnia.ksiazki) {
         if (k.tytul == tytul) {
            return true;
         }
        }
        return false;
    }

    @Override
    public String toString() {
        return "Klient{" +
                "imie='" + imie + '\'' +
                ", pieniadze=" + pieniadze +
                '}';
    }
}
