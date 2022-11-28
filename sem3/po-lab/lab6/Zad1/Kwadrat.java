package Zad1;

public class Kwadrat extends Prostokat {
    double bok;

    public Kwadrat(double bok) {
        super(bok, bok);
        this.bok = bok;
    }

    public double getBok() {
        return bok;
    }

    public void setBok(double bok) {
        this.bok = bok;
    }

    @Override
    public String toString() {
        return "Zad1.Kwadrat{" +
                "bok=" + bok +
                '}';
    }

    public String opis() {
        return toString();
    }
}
