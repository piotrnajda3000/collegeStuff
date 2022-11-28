package Zad1;

public class Figura {
    Punkt punkt;
    String kolor = "bialy";
    public Figura(){
        punkt = new Punkt(0,0);
    }
    public Figura(String kolor){
        punkt = new Punkt(0,0);
        this.kolor=kolor;
    }
    Figura(Punkt punkt){
        this.punkt=punkt;
    }
    String getKolor(){
        return kolor;
    }

    public String opis(){
        return "Klasa Zad1.Figura. Kolor obiektu: "+kolor;
    }
}