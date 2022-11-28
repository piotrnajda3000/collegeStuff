package Zad1;

public class Okrag extends Figura {
    Punkt srodek;
    double r;
    public Okrag(double r, Punkt punkt) {
        this.r = r;
        this.srodek = punkt;
    }

    public Okrag() {
        this.r = 0;
        this.srodek = new Punkt(0, 0);
    }

    @Override
    public String toString() {
        return "Zad1.Okrag{" +
                "srodek=" + srodek.getX()  + ", " + srodek.getY() +
                ", r=" + r +
                '}';
    }

    public double getPowierzchnia() {
        return Math.PI * Math.pow(r, 2);
    }

    public double getSrednica() {
        return r * 2;
    }

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;
    }

    public Boolean wSrodku(Punkt p) {
        return Math.pow((p.getX() - srodek.getX()), 2) +
                Math.pow((p.getY() - srodek.getY()), 2) <=
                Math.pow(r, 2);
    }

    public String opis() {
        return toString();
    }
}
