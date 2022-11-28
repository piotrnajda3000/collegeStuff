package Zad2;

public class SamochodOsobowy extends Samochod {
    double waga, pojemnoscSilnika;
    int iloscOsob;

    public SamochodOsobowy(String marka, String model, String nadwozie, String kolor, int rokProdukcji, int przebieg, double waga, int iloscOsob, double pojemnoscSilnika) throws Exception {
        super(marka, model, nadwozie, kolor, rokProdukcji, przebieg);

        if (waga < 2000 || waga > 4500)
            throw new Exception("Waga miedzy 2000-4500 kg");

        if (pojemnoscSilnika < 0.8 || pojemnoscSilnika > 3.0)
            throw new Exception("0.8-3.0 pojemnosc silnika");

        this.pojemnoscSilnika = pojemnoscSilnika;
        this.waga = waga;
        this.iloscOsob = iloscOsob;
    }

    public String opis() {
        return toString();
    }

    @Override
    public String toString() {
        return "Zad2.SamochodOsobowy{" +
                "waga=" + waga +
                ", pojemnoscSilnika=" + pojemnoscSilnika +
                ", iloscOsob=" + iloscOsob +
                ", marka='" + marka + '\'' +
                ", model='" + model + '\'' +
                ", nadwozie='" + nadwozie + '\'' +
                ", kolor='" + kolor + '\'' +
                ", rokProdukcji=" + rokProdukcji +
                ", przebieg=" + przebieg +
                '}';
    }
}
