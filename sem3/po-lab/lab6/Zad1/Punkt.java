package Zad1;

public class Punkt {
    private float x, y;

    public Punkt() {
        this.x = 0;
        this.y = 0;
    }

    public Punkt(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public float getX() {
        return x;
    }

    public void setX(float x) {
        this.x = x;
    }

    public float getY() {
        return y;
    }

    public void setY(float y) {
        this.y = y;
    }

    public void zeruj() {
        this.x = 0;
        this.y = 0;
    }

    public String opis() {
        return toString();
    }

    @Override
    public String toString() {
        return "Zad1.Punkt{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    public void przesun(float x, float y) {
        this.x = this.x + x;
        this.y = this.y + y;
    }

}
