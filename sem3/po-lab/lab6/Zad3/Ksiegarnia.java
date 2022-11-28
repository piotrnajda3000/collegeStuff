package Zad3;

import java.util.Arrays;

public class Ksiegarnia {
    Ksiazka[] ksiazki;
    Klient[] klienci;

    public Ksiegarnia(Ksiazka[] ksiazki) {
        this.ksiazki = ksiazki;
    }

    public Ksiazka[] getKsiazki() {
        return ksiazki;
    }

    public void setKsiazki(Ksiazka[] ksiazki) {
        this.ksiazki = ksiazki;
    }

    public Klient[] getKlienci() {
        return klienci;
    }

    public void setKlienci(Klient[] klienci) {
        this.klienci = klienci;
    }

    @Override
    public String toString() {
        return "Ksiegarnia{" +
                "ksiazki=" + Arrays.toString(ksiazki) +
                '}';
    }
}
