#include<iostream>
#include<math.h>
using namespace std;

// Zad 1 

void zad1() {
	float a, b, x;

	cout << "Zad. 1" << endl;

	cout << "Wprowadz wspolczynnik a ", cin >> a;
	cout << "Wprowadz wspolczynnik b ", cin >> b;

	if (a == 0) {
		if (b == 0) {
			cout << "Rownanie sprzezcne \n";
		}
		else {
			cout << "Rownanie tozsamosciowe \n";
		}
	}
	else {
		cout << "x = " << -b / a << endl;
	}
}

// Zad 2 

void zad2() {
	float a, b, c;

	cout << "Zad. 2" << endl; 

	cout << "Wprowadz wspolczynnik a ", cin >> a;
	cout << "Wprowadz wspolczynnik b ", cin >> b;
	cout << "Wprowadz wspolczynnik c ", cin >> c;

	if (a == 0) {
		cout << "Rownanie jest liniowe" << endl;
	}
	else {
		float delta = (b * b) - (4 * a * c);

		if (delta > 0) {
			cout << "Dwa pierwiastki" << endl;
		}
		else if (delta == 0) {
			cout << "Jeden pierwiastek" << endl;
		}
		else {
			cout << "Funkcja nie posiada miejsc zerowych \n";
		}
	}
}

// Zad 3 

void zad3() {
	float a, b, c;

	cout << "Zad. 3" << endl;

	cout << "Wprowadz wspolczynnik a ", cin >> a;
	cout << "Wprowadz wspolczynnik b ", cin >> b;
	cout << "Wprowadz wspolczynnik c ", cin >> c;

	if (a == 0) {
		cout << "Rownanie jest liniowe" << endl;
	}
	else {
		float delta = (b * b) - (4 * a * c);

		if (delta > 0) {
			float x1, x2;
			x1 = (-b - sqrt(delta)) / 2 * a;
			x2 = (-b + sqrt(delta)) / 2 * a;
			cout << "Miejsca zerowe: x1 = " << x1 << " x2 = " << x2 << endl;
		}
		else if (delta == 0) {
			float x0;
			x0 = (-b) / (2 * a);
			cout << "Miejsce zerowe: x0 = " << x0 << endl;
		}
		else {
			cout << "Funkcja nie posiada miejsc zerowych \n";
		}
	}
}

// Zad 4 

void zad4() {

	cout << "Zad. 4" << endl;

	float x; 
	cout << "Wprowadz X: ", cin >> x; 

	// a(x)
	if (x > 0) {
		cout << "a(x) = " << 2 * x << endl; 
	}
	else if (x == 0) {
		cout << "a(x) = 0" << endl; 
	}
	else if (x < 0) {
		cout << "a(x) = " << -3 * x << endl;
	}

	// b(x)
	if (x >= 1) {
		cout << "b(x) = " << x * x << endl;
	}
	else if (x <= 1) {
		cout << "b(x) = " << x << endl;
	}

	// c(x) 
	if (x > 2) {
		cout << "c(x) = " << 2 + x << endl;
	}
	else if (x == 2) {
		cout << "c(x) = 8" << endl; 
	}
	else if (x < 2) {
		cout << "c(x) = " << x - 4 << endl; 
	}
}

// Zad 5 

void zamiana(float *x, float *y) {
	float temp = *x;
	*x = *y;
	*y = temp;
}

void zad5() {

	cout << "Zad. 5" << endl;

	float x, y, z; 
	cout << "Wprowadz liczbe x ", cin >> x; 
	cout << "Wprowadz liczbe y ", cin >> y; 
	cout << "Wprowadz liczbe z ", cin >> z; 

	float liczby[] = { x, y, z }; 
	int iloscLiczb = 3; 

	// Sortowanie liczb 
	for (int i = 0; i < iloscLiczb - 1; i++) {
		for (int j = 0; j < iloscLiczb - i - 1; j++) {
			if (liczby[j] > liczby[j + 1]) {
				zamiana(&liczby[j], &liczby[j + 1]); 
			}
		}
	}

	// Drukowanie liczb
	cout << "Posortowane liczby: " << endl; 
	for (int k = 0; k < iloscLiczb; k++) {
		cout << liczby[k] << endl; 
	}
}

// Zad 6 

void zad6() {

	cout << "Zad. 6" << endl;

	int p, a; 
	
	cout << "Pada? 0 / 1 ", cin >> p; 
	cout << "Autobus przyjechal? 0 / 1 ", cin >> a; 

	if (p == 1 && a == 1) {
		cout << "Wez parasol. Dostaniesz sie na uczelnie." << endl; 
	}
	else if (p == 1 && a != 1) {
		cout << "Nie dostaniesz sie na uczelnie." << endl; 
	}
	else if (p != 1 && a == 1) {
		cout << "Dostaniesz sie na uczelnie. Milego dnia i pieknej pogody." << endl; 
	}
}


void zad7() {

	cout << "Zad. 7" << endl;

	int z, p; 

	cout << "Znizka? 0 / 1 ", cin >> z;
	cout << "Podwyzka? 0 / 1 ", cin >> p;
 
	if (z || p) {
		cout << "Mozesz kupic samochod!" << endl; 
		if (z != 1) {
			cout << "Znizki nie ma... :(" << endl; 
		}
	} 
	else { 
		cout << "Zakup samochodu trzeba odlozyc na pozniej..." << endl; 
		cout << "Znizki nie ma... :(" << endl; 
	}

}

void zad8() {

	cout << "Zad. 8" << endl;

	float a, b;
	int operacja; 

	cout << "Liczba A: ", cin >> a; 

	cout << "-----------------------------" << endl; 
	cout << "-> [1] <- Dodawanie" << endl; 
	cout << "-> [2] <- Odejmowanie" << endl; 
	cout << "-> [3] <- Mnozenie" << endl; 
	cout << "-> [4] <- Dzielenie" << endl; 
	cout << "-> [5] <- Reszta z dzielenia" << endl;
	cout << "Wybierz numerek operacji : ",  cin >> operacja; 
	cout << "-----------------------------" << endl;  

	cout << "Liczba B: ", cin >> b;
	 
	switch (operacja) {
		case 1: 
			cout << a + b << endl; 
			break; 
		case 2: 
			cout << a - b << endl; 
			break; 
		case 3: 
			cout << a * b << endl; 
			break; 
		case 4: 
			cout << a / b << endl; 
			break; 
		case 5: 
			cout << fmod(a, b) << endl; 
			break; 
	}
}


int main() 
{

	cout << "Pozdrawiam, w65550 Najda Piotr" << endl;

	zad1();
	zad2();
	zad3();
	zad4();
	zad5();
	zad6();
	zad7();
	zad8();

	return 0;
}