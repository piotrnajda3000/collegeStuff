import Zad1.*;
import Zad2.Samochod;
import Zad2.SamochodOsobowy;
import Zad3.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Punkt p1 = new Punkt(1, 2);
        Punkt p2 = new Punkt();
        Punkt p3 = new Punkt(3, 4);

        p1.opis();
        p1.zeruj();
        p1.opis();
        p1.przesun(1, 2);
        p1.opis();

        Figura f1 = new Figura();
        System.out.println(f1.opis());

        Prostokat pr1 = new Prostokat(5, 2);
        System.out.println(pr1.getPowierzchnia());

        Trojkat t1 = new Trojkat(3, 2);

        Okrag o1 = new Okrag(1, new Punkt(0, 0));
        System.out.println(o1.toString());
        System.out.println(o1.wSrodku(new Punkt(0, 0)));
        System.out.println(o1.wSrodku(new Punkt(0, 1)));
        System.out.println(o1.wSrodku(new Punkt(0, 2)));

        Prostokat pr2 = new Prostokat(2, 3, "niebieski");
        System.out.println(pr2.opis());

        Trojkat t2 = new Trojkat(2, 3, "czerwony");
        System.out.println(t2.opis());

        System.out.println(pr1.opis());
        pr1.przesun(3, 5);
        System.out.println(pr1.opis());

        Kwadrat k1 = new Kwadrat(3);

        System.out.println("Zad 19");
        System.out.println(p1.opis());
        System.out.println(f1.opis());
        System.out.println(pr1.opis());
        System.out.println(t1.opis());
        System.out.println(o1.opis());
        System.out.println(k1.opis());

        // Zad 2

        SamochodOsobowy so1 = new SamochodOsobowy("volvo", "xc75", "suv", "niebieskie", 1991, 12340, 2300, 5, 2.0);
        Samochod s1 = new Samochod("bmw", "m2", "coupe", "biale", 2015, 20000);

        System.out.println(so1.opis());
        System.out.println(s1.opis());

        // Zad 3

        Ksiazka ks1 = new Ksiazka("Ksiazka 1", 1991);
        Podrecznik podr1 = new Podrecznik("Matematyka", 1992, "matematyka");
        Powiesc powiesc1 = new Powiesc("Nowe Przygody Tuptupa", 2007, "Przygody Tuptupa");

        Ksiazka[] ksiazki = {ks1, podr1, powiesc1};

        Ksiazka ks2 = (Ksiazka) podr1;

        if (ks2 instanceof Podrecznik) {
            System.out.println("Downcasting");
            System.out.println(((Podrecznik) ks2).toString());
        }

        Ksiegarnia ksiegarnia = new Ksiegarnia(ksiazki);

        System.out.println(ksiegarnia.toString());

        Klient kl = new Klient("Jan", 3000);

        System.out.println(kl.sprawdzKsiazke(ksiegarnia, "Ksiazka 1"));
        System.out.println(kl.sprawdzKsiazke(ksiegarnia, "Ksiazka 123"));

        ksiegarnia.setKlienci(new Klient[]{kl});
        System.out.println(ksiegarnia.getKlienci()[0].toString());
    }
}