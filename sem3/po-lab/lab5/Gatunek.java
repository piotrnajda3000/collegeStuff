public class Gatunek {
    private String rodzaj, gatunek;
    private int ch2N, chX;

    public Gatunek(String rodzaj, String gatunek, int ch2N, int chX) {
        this.rodzaj = rodzaj;
        this.gatunek = gatunek;
        this.ch2N = ch2N;
        this.chX = chX;
    }

    public int getChX() {
        return chX;
    }

    public String fullName() {
        return rodzaj + ", " + gatunek;
    }

    @Override
    public String toString() {
        return "Gatunek{" +
                "rodzaj='" + rodzaj + '\'' +
                ", gatunek='" + gatunek + '\'' +
                ", ch2N=" + ch2N +
                ", chX=" + chX +
                ", fullName=" + fullName() +
                '}';
    }

    @Override
    protected Gatunek clone() {
        Gatunek g = new Gatunek(rodzaj, gatunek, ch2N, chX);
        return g;
    }
}
