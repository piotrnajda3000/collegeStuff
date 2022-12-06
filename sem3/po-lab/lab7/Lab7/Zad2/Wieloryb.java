package Lab7.Zad2;

public class Wieloryb extends Zwierze implements Plywanie, Latanie {
    @Override
    public void jedz() {
        System.out.println("Jestem wielorybem i jem");
    }

    @Override
    public void wydalaj() {
        System.out.println("Jestem wielorybem i wydalam");
    }

    @Override
    public void lec() {
        System.out.println("Jestem wielorybem i jestem w powietrzu");
    }

    @Override
    public void wyladuj() {
        System.out.println("Jestem wielorybem i laduje w wodzie");
    }

    @Override
    public void plyn() {
        System.out.println("Jestem wielorybem i plywam");
    }

    @Override
    public void wynurz() {
        System.out.println("Jestem wielorybem i sie wynurzam");
    }

    @Override
    public void zanurz() {
        System.out.println("Jestem wielorybem i sie zanurzam");
    }
}
