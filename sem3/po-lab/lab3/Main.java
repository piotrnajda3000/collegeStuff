import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        zad1();
        zad2();
        zad3();
        zad4();
        zad5();

    }

    public static void zad1() {
        int n;
        double avg = 0;
        int student = 0;

        System.out.println("Podaj liczbe studentow: ");

        do {
            n = getInt();
        } while (n <= 0);

        while (student < n) {
            System.out.println("Podaj liczbe pkt dla studenta " + (student + 1));
            avg += getInt();
            student++;
        }

        System.out.println("Srednia pkt: " + avg / n);
    }

    public static void zad2() {
        double nums[] = new double[10];
        double plusSum = 0, plusCount = 0;
        double negativeSum = 0, negativeCount = 0;

        for (int i = 0; i < 10; i++) {
            System.out.println("Wprowadz liczbe nr " + (i + 1));
            nums[i] = getDouble();
        }

        for (int i = 0; i < 10; i++) {
            if (nums[i] > 0) {
                plusSum += nums[i];
                plusCount += 1;
                continue;
            }
            if (nums[i] < 0) {
                negativeSum += nums[i];
                negativeCount += 1;
            }
        }

        System.out.println("Suma liczb na plusie: " + plusSum);
        System.out.println("Liczba liczb na plusie: " + plusCount);

        System.out.println("Suma liczb na minusie: " + negativeSum);
        System.out.println("Liczba liczb na minusie: " + negativeCount);
    }

    public static void zad3() {
        int n, sumEven = 0, ciag[];

        System.out.println("Ile liczb w ciagu?: ");
        do {
            n = getInt();
        } while (n <= 0);
        ciag = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Podaj " + (i + 1) + " liczbe ciagu: ");
            ciag[i] = getInt();
            if (ciag[i] % 2 == 0) {
                sumEven += ciag[i];
            }
        }

        System.out.println("Suma parzystych liczb w ciagu: " + sumEven);
    }

    public static void zad4() {
        Random rand = new Random();
        int n, sumEven = 0, ciag[];

        System.out.println("Ile liczb w ciagu?: ");
        do {
            n = getInt();
        } while (n <= 0);
        ciag = new int[n];

        for (int i = 0; i < n; i++) {
            ciag[i] = rand.nextInt(56) - 10;
            System.out.println("Wylosowano " + ciag[i]);
            if (ciag[i] % 2 == 0) {
                sumEven += ciag[i];
            }
        }

        System.out.println("Suma parzystych liczb w ciagu: " + sumEven);
    }

    public static void zad5() {
        String slowo;
        boolean isPalindrome = true;

        System.out.println("Podaj slowo: ");
        do {
            slowo = getString();
        } while (slowo.length() == 0);

        int first = 0;
        int last = slowo.length() - 1;
        do {
            if (slowo.charAt(first) != slowo.charAt(last)) {
                isPalindrome = false;
                break;
            }
            first = first + 1;
            last = last - 1;
        } while (first < last);

        if (isPalindrome) {
            System.out.println("Slowo jest palindromem");
        } else {
            System.out.println("Slowo nie jest palindromem");
        }

    }

    public static int getInt() {
        return new Scanner(System.in).nextInt();
    }

    public static double getDouble() {
        return new Scanner(System.in).nextDouble();
    }

    public static String getString() {
        return new Scanner(System.in).nextLine();
    }
}
