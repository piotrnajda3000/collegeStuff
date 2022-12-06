package Lab7.Zad3;

public class Okrag extends Figura implements RuchFigury {
    Punkt srodek;
    public double r;

    @Override
    public void przesun(int x, int y) {
        this.srodek.x = this.srodek.x + x;
        this.srodek.y = this.srodek.y + y;
    }


    public Okrag(double r, Punkt srodek) {
        this.r = r;
        this.srodek = srodek;
    }

    @Override
    public String opis() {
        return "Okrag promien " + r + "srodek x: " + srodek.x + " srodek y: " + srodek.y;
    }

    @Override
    public void skaluj(float skala) {
        this.r = r * skala;
    }

    @Override
    public float getPowierzchnia() {
        return (float) (Math.PI * r * r);
    }

    @Override
    public boolean wPolu(Punkt p) {
        return Math.pow((p.x - srodek.x), 2) +
                Math.pow((p.y - srodek.y), 2) <=
                Math.pow(r, 2);
    }
}
