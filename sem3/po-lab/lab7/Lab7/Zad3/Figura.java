package Lab7.Zad3;

public abstract class Figura implements IFigura {
	Punkt punkt;
	String kolor = "bialy";

	public Figura(){
		punkt = new Punkt(0,0);
	}
	Figura(String kolor){
		this.kolor = kolor;
	}
	Figura(Punkt punkt){
		this.punkt = punkt;
	}
	String getKolor(){
		return kolor;
	}

	public abstract String opis();

	public abstract void skaluj(float skala);
}
