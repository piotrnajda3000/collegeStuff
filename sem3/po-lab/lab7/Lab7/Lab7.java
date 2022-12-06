package Lab7;

import Lab7.Zad1.Samolot;
import Lab7.Zad1.Statek;
import Lab7.Zad2.Wieloryb;
import Lab7.Zad3.*;

public class Lab7 {
    public Lab7() {
        zad1();
        zad2();
        zad3();
    }

    public static void zad1() {
        Statek statek = new Statek();
        statek.plyn();
        Samolot samolot = new Samolot();
        samolot.lec();
    }

    public static void zad2() {
        Wieloryb wieloryb = new Wieloryb();
        wieloryb.plyn();
        wieloryb.wynurz();
        wieloryb.zanurz();
        wieloryb.lec();
        wieloryb.wyladuj();
        wieloryb.wydalaj();
    }

    public static void zad3()  {
        // 3.1, 3.2

        Prostokat maly_prostokat = new Prostokat(3, 6, "czerwony");
        Trojkat rownoboczny = new Trojkat(7, 4, "bialy");
        Kwadrat kwadrat = new Kwadrat(2, "bialy");

        System.out.println(maly_prostokat.opis());
        System.out.println(rownoboczny.opis());
        System.out.println(kwadrat.opis());

        // 3.6
        Figura[] figury = new Figura[10];
        figury[0] = maly_prostokat;
        figury[1] = rownoboczny;
        figury[2] = kwadrat;
        figury[3] = new Prostokat(2, 2, "czarny");
        figury[4] = new Prostokat(2, 2, "czarny");
        figury[5] = new Prostokat(2, 2, "czarny");
        figury[6] = new Prostokat(2, 2, "czarny");
        figury[7] = new Prostokat(2, 2, "czarny");
        figury[8] = new Prostokat(2, 2, "czarny");
        figury[9] = new Prostokat(2, 2, "czarny");

        // 3.7
        for (Figura figura : figury) {
            System.out.println(figura.opis());
        }

        // 3.8
        System.out.println("3.8");

        System.out.println(maly_prostokat.opis());
        maly_prostokat.skaluj(2);
        System.out.println(maly_prostokat.opis());

        System.out.println(rownoboczny.opis());
        rownoboczny.skaluj(2);
        System.out.println(rownoboczny.opis());

        System.out.println(kwadrat.opis());
        kwadrat.skaluj(2);
        System.out.println(kwadrat.opis());

        // 3.9
        IFigura[] figury2 = new IFigura[3];
        figury2[0] = maly_prostokat;
        figury2[1] = kwadrat;
        figury2[2] = rownoboczny;

        System.out.println("3.9");

        for (IFigura figura : figury2) {
            if (figura instanceof Figura) {
                System.out.println(((Figura) figura).opis());
            }
            System.out.println(figura.getPowierzchnia());
            System.out.println(figura.wPolu(new Punkt(5, 1)));
        }

        System.out.println("Zad 3, sprawdzanie dzialania interfesju RuchFigury");
        Okrag okrag = new Okrag(2, new Punkt(0, 0));
        System.out.println(okrag.opis());
        okrag.przesun(2, 3);
        System.out.println(okrag.opis());
    }
}
