import java.util.Random;
import java.util.Scanner;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public class Main {
    public static void main(String[] args) {
        System.out.println("Zad 1");
        System.out.println(zad1("Piotr", 22));

        System.out.println("Zad 2");

        double zad2A, zad2B;

        System.out.println("Wpisz Liczbe 1: ");
        zad2A = getDouble();

        System.out.println("Wpisz Liczbe 2: ");
        zad2B = getDouble();

        zad2(zad2A, zad2B);

        System.out.println("Zad 3");
        System.out.println(zad3IsEven(5));
        System.out.println(zad3IsEven(2));

        System.out.println("Zad 4");
        System.out.println(zad4(15));
        System.out.println(zad4(5));
        System.out.println(zad4(3));

        System.out.println("Zad 5");
        System.out.println(zad5PowerThree(3));

        System.out.println("Zad 6");
        System.out.println(zad6SquareRoot(4));
        System.out.println(zad6SquareRoot(3));

        System.out.println("Zad 7");

        Random random = new Random();
        int triangleSides[] = new int[3];
        int zad7A, zad7B;

        System.out.println("Wpisz poczatek przedzialu: ");
        zad7A = getInt();

        System.out.println("Wpisz koniec przedzialu: ");
        do {
            zad7B = getInt();
        } while (zad7B < zad7A);

        for (int side = 0; side < 3; side++) {
            triangleSides[side] = random.nextInt(zad7B - zad7A + 1) + zad7A;
        }

        System.out.println(zad7CanMakeARightTriangle(triangleSides[0], triangleSides[1], triangleSides[2]));
    }

    public static String zad1(String name, int age) {
        return name + " " + age;
    }

    public static void zad2(double a, double b) {
        System.out.println("Suma: " + (a + b));
        System.out.println("Roznica: " + (a - b));
        System.out.println("Iloczyn: " + (a * b));
    }

    public static boolean zad3IsEven(int a) {
        return (a % 2 == 0);
    }

    public static boolean zad4 (double a) {
        return (a % 3 == 0 && a % 5 == 0);
    }

    public static double zad5PowerThree(double a) {
        return a * a * a;
    }

    public static double zad6SquareRoot(double a) {
        return sqrt(a);
    }

    public static boolean zad7CanMakeARightTriangle(int a, int b, int c) {
        System.out.println("A: " + a + ", B: " + b + ", C: " + c);
        return (pow(a, 2) + pow(b, 2) == pow(c, 2));
    }

    public static double getDouble() {
        return new Scanner(System.in).nextDouble();
    }

    public static int getInt() {
        return new Scanner(System.in).nextInt();
    }
}