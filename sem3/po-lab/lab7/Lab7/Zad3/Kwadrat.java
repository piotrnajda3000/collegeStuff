package Lab7.Zad3;


public class Kwadrat extends Prostokat{
	public Kwadrat(int bok,String kolor){
		super(bok,bok,kolor);
	}

	@Override
	public String opis() {
		return "Kwadrat o boku: " + szer;
	}

}