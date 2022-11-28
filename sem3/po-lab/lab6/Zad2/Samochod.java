package Zad2;

public class Samochod {
    String marka, model, nadwozie, kolor;
    int rokProdukcji;
    int przebieg;

    public Samochod(String marka, String model, String nadwozie, String kolor, int rokProdukcji, int przebieg) throws Exception {
        if (przebieg < 0)
            throw new Exception("Za maly przebieg");

        this.marka = marka;
        this.model = model;
        this.nadwozie = nadwozie;
        this.kolor = kolor;
        this.rokProdukcji = rokProdukcji;
        this.przebieg = przebieg;
    }

    public String opis() {
        return toString();
    }

    @Override
    public String toString() {
        return "Zad2.Samochod{" +
                "marka='" + marka + '\'' +
                ", model='" + model + '\'' +
                ", nadwozie='" + nadwozie + '\'' +
                ", kolor='" + kolor + '\'' +
                ", rokProdukcji=" + rokProdukcji +
                ", przebieg=" + przebieg +
                '}';
    }
}
