import static java.lang.Math.*;

public class Prostokat {
    int w, h;

    public Prostokat(int w, int h) {
        this.w = w;
        this.h = h;
    }

    double area() {
        return w * h;
    }

    double perimeter() {
        return 2 * w + 2 * h;
    }

    double diagonal() {
        return sqrt(pow(w, 2) * pow(h, 2));
    }

    @Override
    public String toString() {
        return "Prostokat{" +
                "w=" + w +
                ", h=" + h +
                ", area=" + diagonal() +
                ", perimeter=" + perimeter() +
                ", diagonal=" + diagonal() +
                '}';
    }
}


