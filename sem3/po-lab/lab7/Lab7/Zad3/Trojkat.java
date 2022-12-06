package Lab7.Zad3;

public class Trojkat extends Figura{
	double wys = 0;
	double podst = 0;
	public Trojkat(double wys, double podst, String kolor){
		
		this.wys = wys;
		this.podst = podst;
		super.kolor = kolor;
	}
	public String opis(){
		return "Trojkat o wymiarach: " + wys + "  " + podst;
	}

	@Override
	public void skaluj(float skala) {
		this.wys = wys * skala;
		this.podst = podst * skala;
	}

	@Override
	public float getPowierzchnia() {
		return (float) (podst * wys * 1/2);
	}

	@Override
	public boolean wPolu(Punkt p) {
			double area = getPowierzchnia();

			// Check if the point is inside the triangle by comparing the area of the triangle
			// with the sum of the areas of the four triangles formed by the point and the
			// vertices of the original triangle.
			return Math.abs(area - 0.5 * podst * wys) < 1e-6;
		}
}