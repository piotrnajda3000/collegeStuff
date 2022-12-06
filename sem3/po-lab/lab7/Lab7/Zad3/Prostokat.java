package Lab7.Zad3;

public class Prostokat extends Figura  {
	@Override
	public float getPowierzchnia() {
		return wys * szer;
	}

	@Override
	public boolean wPolu(Punkt p) {
		return (p.x > 0 && p.x < szer && p.y > 0 && p.y < wys);
	}

	float wys = 0;
	float szer = 0;

	public Prostokat(float wys, float szer, String kolor) {
		this.wys = wys;
		this.szer = szer;
		super.kolor = kolor;
	}

	public String opis() {
		return "Prostokat o wymiarach: " + szer + " x " + wys;
	}

	@Override
	public void skaluj(float skala) {
		this.wys = wys * skala;
		this.szer = szer * skala;
	}
}
