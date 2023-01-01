import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.println(getRoot());

        try {
            System.out.println(fac(5));
            System.out.println(fac(-1));
        } catch (SilniaException e) {
            System.out.println("Blad: " + e.getMessage());
        }

        try {
            Adres address = new Adres("a", "b", "c", 2);
            Adres address2 = new Adres(null, "b", "c", -1);
        } catch (ExceptionAddress e) {
            System.out.println("Blad: " + e.getMessage());
        }
    }

    public static String getRoot() {
        double input = 0;

        while (true) {
            try {
                System.out.println("Podaj liczbe");
                input = scanner.nextDouble();
                break;
            } catch (InputMismatchException e) {
                System.out.println("Podaj poprawna wartosc");
                scanner.next();
            }
        }

        if (input < 0) {
            throw new IllegalArgumentException(String.format("Dla liczby %.2f nie istnieje pierwiastek kwadratowy", input));
        }

        return String.format("Pierwiastek z liczby %.2f wynosi %.2f", input, Math.sqrt(input));
    }

    public static class SilniaException extends Exception {
        public SilniaException(String message) {
            super(message);
        }
    }

    public static double fac(int n) throws SilniaException {
        if (n < 0) {
            throw new SilniaException("Wartosc silni nie moze byc ujemna");
        }

        if (n == 1) return 1;

        return n * fac(n - 1);
    }
}


