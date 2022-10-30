import static java.lang.Math.sqrt;

public class Main {
    public static void main(String[] args) {
        System.out.println("Zad 1");
        zad1RownanieKwadratowe(2, 2, -12);
        zad1RownanieKwadratowe(2, 4, 2);
        zad1RownanieKwadratowe(-4, 2, -5);

        System.out.println("Zad 3");
        zad3(53, 221, 23);

        System.out.println("Zad 4");
        zad4(false, false);
        zad4(false, true);
        zad4(true, false);
        zad4(true, true);

        System.out.println("Zad 5");
        zad5(false, false);
        zad5(false, true);
        zad5(true, false);
        zad5(true, true);

        System.out.println("Zad 6");
        System.out.println(zad6(5, 2, '+'));
        System.out.println(zad6(5, 2, '-'));
        System.out.println(zad6(5, 2, '*'));
        System.out.println(zad6(5, 2, '/'));
    }

    public static void zad1RownanieKwadratowe (double a, double b, double c){
        double delta = (b * b) - (4 * a * c);
        double x1, x2;
        if (delta > 0) {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            System.out.println("x1: " + x1 + ", x2: " + x2);
            return;
        }
        if (delta == 0) {
            x1 = -b / (2 * a);
            System.out.println("Jedno rozwiazanie, x1: " + x1);
            return;
        }
        System.out.println("Brak rozwiazan");
    }

    public static double zad2a (double x) {
        if (x > 0) {
            return 2 * x;
        }
        if (x < 0) {
            return -3 * x;
        }
        return 0;
    }

    public static double zad2b (double x) {
        if (x >= 1) {
            return x * x;
        }
        return x;
    }

    public static double zad2c (double x) {
        if (x > 2) {
            return 2 + x;
        }
        if (x < 2) {
            return x - 4;
        }
        return 8;
    }

    public static void zad3 (double a, double b, double c) {
        double max = Math.max(a, Math.max(b, c));
        double min = Math.min(a, Math.min(b, c));
        double mid = a + b + c - max - min;
        System.out.printf("Po kolei: %f %f %f%n", min, mid, max);
    }

    public static void zad4(boolean rain, boolean bus) {
        if (rain && bus) {
            System.out.println("\nWez parasol");
            System.out.println("Dostaniesz sie na uczelnie\n");
            return;
        }
        if (rain && !bus) {
            System.out.println("Nie dostaniesz sie na uczelnie \n");
            return;
        }
        if (!rain && bus) {
            System.out.println("\nDostaniesz sie na uczelnie");
            System.out.println("Milego dnia i pieknej pogody\n");
        }
    }

    public static void zad5(boolean z, boolean p) {
        if (z || p) {
            System.out.println("\nMozesz kupic samochod");
            if (!z) {
                System.out.println("Znizki na samochod nie ma\n");
            }
        } else {
            System.out.println("\nZakup samochodu trzeba odlozyc na pozniej");
            System.out.println("Znizki na samochod nie ma\n");
        }
    }

    public static double zad6(double a, double b, char operacja) {
        switch (operacja) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '/':
                return a / b;
            case '%':
                return a % b;
            case '*':
                return a * b;
            default:
                System.out.println("Nieprawidlowa operacja");
                return -1;
        }
    }



}