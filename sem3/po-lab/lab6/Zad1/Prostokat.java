package Zad1;

public class Prostokat extends Figura  {
    double wys=0, szer=0;

    public Prostokat(double wys, double szer){
        super();
        this.wys = wys;
        this.szer = szer;
    }

    public Prostokat(double wys, double szer, String kolor) {
        super(kolor);
        this.wys = wys;
        this.szer = szer;
    }

    public String opis() {
        return toString();
    }

    @Override
    public String toString() {
        return "Zad1.Prostokat{" +
                "wys=" + wys +
                ", szer=" + szer +
                ", punkt=" + punkt.toString() +
                ", kolor='" + kolor + '\'' +
                '}';
    }

    public double getPowierzchnia() {
        return (szer * wys);
    }

    public void przesun(float x, float y) {
        this.punkt.przesun(x, y);
    }

}