#include <iostream>

using namespace std; 

int main()
{
	// Zadanie 1 
	int nrAlbumu = 65550; 
	cout << "w" << nrAlbumu; 
	cout << "\n=====\n";

	// Zadanie 2 
	int x;
	cout << "Wpisz liczbe calkowita, zeby sprawdzic czy jest parzysta ", cin >> x;
	cout << "Liczba " << x << " jest " << (x % 2 == 0 ? "parzysta" : "nieparzysta");
	cout << "\n=====\n";

	// Zadanie 3 
	double a, b;
	cout << "Sprawdź która liczba jest większa" << endl;  
	cout << "Wprowadz liczbe a: ", cin >> a; 
	cout << "Wprowadz liczbe b: ", cin >> b;
	if (a > b) {
		cout << "Liczba " << a << " jest wieksza";
	}
	else if (a < b) {
		cout << "Liczba " << b << " jest wieksza";
	}
	else {
		cout << "Liczby są równe"; 
	}
	cout << "\n=====\n";

	// Zadanie 4 
	cout << "Wprowadz cztery liczby zmiennoprzecinkowe, zeby policzyc ich srednia" << endl; 
	double c, d, e, f; 
	cout << "A: ", cin >> c, 
	cout << "B: ", cin >> d, 
	cout << "C: ", cin >> e, 
	cout << "D: ", cin >> f; 
	double srednia = (c + d + e + f) / 4; 
	cout << "Ich srednia wynosi " << srednia;
	cout << "\n=====\n";

	// Zadanie 5
	double g, h; 
	int operacja; 
	cout << "Enter number A into calculator ", cin >> g; 
	cout << "Enter number B into calculator ", cin >> h;
	cout << "Wpisz numerek operacji: + [1] | - [2] | / [3] | * [4] ", cin >> operacja;

	cout << "Wynik: "; 
	switch (operacja) {
		case 1: 
			cout << g + h;
			break;
		case 2:
			cout << g - h; 
			break; 
		case 3:
			cout << g / h; 
			break; 
		case 4:
			cout << g * h; 
			break; 
		default: 
			cout << "Zly operator"; 
			break; 
	}

	cout << endl; 

	return 0; 

}