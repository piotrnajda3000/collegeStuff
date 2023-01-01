import java.util.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");

        List<Uczestnik> uczestnicy = new ArrayList<Uczestnik>(Arrays.asList(
                new Uczestnik(15, "b", "b"),
                new Uczestnik(22, "b", "b"),
                new Uczestnik(23, "b", "b"),
                new Uczestnik(21, "b", "b"),
                new Uczestnik(23, "b", "b"),
                new Uczestnik(15, "c", "b")
        ));

        List<Uczestnik> uczestnicy2 = new LinkedList<Uczestnik>(Arrays.asList(
                new Uczestnik(15, "b", "b"),
                new Uczestnik(22, "b", "b")
        ));

        System.out.println("Przed filtracja niepelnoletnich");

        var over18Participants = new ArrayList<Uczestnik>(uczestnicy);

        for(Uczestnik uczestnik : over18Participants) {
            System.out.println(uczestnik.toString());
        }
        for (int i = 0; i < over18Participants.size(); i++) {
            if (over18Participants.get(i).getAge() < 18) {
                over18Participants.remove(i);
            }
        }

        System.out.println("Po filtracji niepelnoletnich");

        for(Uczestnik uczestnik : over18Participants) {
            System.out.println(uczestnik.toString());
        }

//        Zad 2
        SomeClass[] arr = new SomeClass[3];
        arr[0] = new SomeClass();
        arr[1] = new SomeClass();
        arr[2] = new SomeClass();
        var SomeList = new ArrayList<>(Arrays.asList(arr[0], arr[1], arr[2]));

        for (SomeClass obj : SomeList) {
            System.out.println(obj);
        }

        SomeList.subList(0, 2).clear();

        System.out.println("Po usunieciu 1 i 2 elementu:");

        for (SomeClass obj : SomeList) {
            System.out.println(obj);
        }

//        Zad 3

        var list1 = List.of(1, 2, 3);
        var list2 = new ArrayList<>(Arrays.asList(4, 5, 6));

        ListIterator<Integer> i = list1.listIterator(list1.size());

        while (i.hasPrevious()) {
            list2.add(i.previous());
        }

        for (Integer a : list2) {
            System.out.println(a);
        }

    }
}