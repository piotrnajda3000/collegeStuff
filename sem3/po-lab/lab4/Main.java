import java.util.Arrays;
import java.util.Random;
import java.lang.Math;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        zad1();
        System.out.println();
        zad2();
        System.out.println();
        zad3();
        System.out.println();
        zad4();
        System.out.println();
        zad5();
        System.out.println();
        zad6();
        System.out.println();
        zad7();
    }


    public static void zad1() {
        RandomInterval interval = new RandomInterval();
        System.out.println("Przedzial od: " + interval.start + " " + interval.end);

        for (int h : interval.nums) {
            System.out.println("Losowa liczba: " + h);
        }

        int sum = 0;
        double avg = 0;

        for (int i = 0; i < interval.length; i++) {
            sum = sum + interval.nums[i];
        }

        avg = (double) sum / interval.length;

        System.out.println("Suma: " + sum);
        System.out.println("Srednia: " + avg);
    }

    public static void zad2() {
        System.out.println();

        RandomInterval evenInterval = new RandomInterval(true);
        RandomInterval oddInterval = new RandomInterval(false);

        System.out.println("Random even interval:");
        for (int j : evenInterval.nums) {
            System.out.print(j + "\t");
        }

        System.out.println();

        System.out.println("Every second even interval num: ");
        for (int i = 0; i < evenInterval.length; i++) {
            if (i % 2 == 0) {
                System.out.print(evenInterval.nums[i] + "\t");
            } else {
                System.out.print("\t");
            }
        }

        System.out.println();

        System.out.println("Random odd interval:");
        for (int j : oddInterval.nums) {
            System.out.print(j + "\t");
        }

        System.out.println();

        System.out.println("Every second odd interval num: ");
        for (int i = 0; i < oddInterval.length; i++) {
            if (i % 2 == 0) {
                System.out.print(oddInterval.nums[i] + "\t");
            } else {
                System.out.print("\t");
            }
        }
    }

    public static void zad3() {
        System.out.println();

        String[] arr = {"ab", "cd", "ef"};

        for (String s : arr) {
            System.out.println(s.toUpperCase());
        }
    }

    public static String getString() {
        return new Scanner(System.in).nextLine();
    }

    public static void zad4() {
        System.out.println("Podaj slowo: ");

        String[] words = new String[5];

        for (int i = 0; i < words.length; i++) {
            words[i] = getString();
        }

        for (int i = words.length - 1; i > -1; i--) {
            String newWord = "";
            for (int j = words[i].length() - 1; j > -1; j--) {
                newWord = newWord + words[i].charAt(j);
            }
            System.out.println(newWord);
        }
    }

    public static int getInt() {
        return new Scanner(System.in).nextInt();
    }

    public static void zad5() {
        int[] nums = new int[8];

        for (int i = 0; i < nums.length; i++) {
            System.out.println("Podaj liczbe: ");
            nums[i] = getInt();
        }

        // Insert sort
        for (int i = 1; i < nums.length; ++i) {
            int key = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j = j - 1;
            }
            nums[j + 1] = key;
        }

        for (int i : nums) {
            System.out.print(i + "\t");
        }
    }

    public static long fac(int n) {
        if (n < 2 && n >= 0) return 1;

        return n * fac(n - 1);
    }

    public static void zad6() {
        int N = 5;

        int[] nums = new int[N];
        long[] numsFac = new long[N];

        for (int i = 0; i < N; i++) {
            System.out.println("Podaj liczbe: ");
            nums[i] = getInt();
        }

        for (int i = 0; i < N; i++) {
            numsFac[i] = fac(nums[i]);
        }

        for (int i = 0; i < N; i++) {
            System.out.println("Silnia z " + nums[i] + " wynosi: " + numsFac[i]);
        }

    }


    public static boolean compareStringArrs(String[] a, String[] b) {
        if (a.length != b.length) return false;

        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length(); j++) {
                if (a[i].charAt(j) != b[i].charAt(j)) {
                   return false;
                }
            }
        }

        return true;
    }
    public static void zad7() {
        String[] a = {"a", "b", "cd"};
        String[] b = {"a", "b", "cd"};

        String[] c = {"a", "b", "ce"};
        String[] d = {"a", "e", "cd"};

        for (String s : a) {
            System.out.println(s + "\t");
        }
        System.out.println();
        for (String s : b) {
            System.out.println(s + "\t");
        }
        System.out.println("Czy tablice sa takie same? " + (compareStringArrs(a, b) ? "tak" : "nie"));

        System.out.println();

        for (String s : c) {
            System.out.println(s + "\t");
        }
        System.out.println();
        for (String s : d) {
            System.out.println(s + "\t");
        }

        System.out.println("Czy tablice sa takie same? " + (compareStringArrs(c, d) ? "tak" : "nie"));
    }
}

class RandomInterval {
    private Random rand = new Random();
    int start, end;
    int length;
    int[] nums;

    private int lowerBound = 10;
    private int maxBound = 15;

    private void generateRandomNums() {
        for (int i = 0; i < length; i++) {
            nums[i] = rand.nextInt(end + 1 - start) + start;
        }
    }

    RandomInterval() {
        this.start = rand.nextInt(5);

        do {
            this.end = rand.nextInt(maxBound);
        } while (this.end <= this.start);

        this.length = Math.abs(end - start);

        nums = new int[length];

        generateRandomNums();
    }

    RandomInterval(boolean evenLength) {
        this.start = rand.nextInt(5);

        if (evenLength) {
            do {
                this.end = rand.nextInt(lowerBound);
                this.length = Math.abs(this.end - this.start);
            } while (this.end <= this.start || this.length % 2 != 0);
        } else {
            do {
                this.end = rand.nextInt(lowerBound);
                this.length = Math.abs(this.end - this.start);
            } while (this.end <= this.start || this.length % 2 == 0);
        }

        nums = new int[length];

        generateRandomNums();
    }
}