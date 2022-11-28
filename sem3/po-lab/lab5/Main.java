import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {

        Prostokat p = new Prostokat(5, 2);
        System.out.println(p.toString());

        Budynek b1 = new Budynek("A", 23, LocalDate.of(1999, 1, 1));
        Budynek b2 = new Budynek("A", 21, LocalDate.of(1815, 1, 1));
        Budynek b3 = new Budynek("A", 19, LocalDate.of(1992, 1, 1));
        System.out.println(b1.toString());
        System.out.println(b2.toString());
        System.out.println(b3.toString());

        Gatunek g1 = new Gatunek("a", "b", 1, 2);
        Gatunek g2 = g1.clone();

        System.out.println(g1.toString());

        System.out.println(g1.fullName());
        System.out.println(g1.getChX());

        System.out.println(g2.toString());

    }
}