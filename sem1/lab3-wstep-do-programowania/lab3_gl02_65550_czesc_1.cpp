#include <iostream>
#include <time.h> 

using namespace std;

void zad1() {

	int i = 0;
	unsigned int n;

	cout << "Wpisz liczbe naturalna: ", cin >> n;

	for (i = 0; i < n; i++) {
		cout << i;
	}

	cout << endl;

	i = 0;
	while (i < n) {
		cout << i;
		i++;
	}

	cout << endl;

	i = 0;
	do {
		cout << i;
		i++;
	} while (i < n);

	cout << endl;

}

void zad2() {

	cout << endl; 

	double x;

	cout << "Program zatrzyma sie jak wpiszesz liczbe mniejsza od 0: ";

	do {
		cin >> x;
	} while (x >= 0);

	cout << "Wpisales liczbe mniejsza od 0" << endl; 


}

void zad3() {

	cout << endl; 

	int negativeCount = 0;
	double negativeSum = 0; 

	int positiveCount = 0;
	double positiveSum = 0; 

	for (int i = 1; i <= 10; i++) {
		double x; 
		cout << "Liczba " << i << ": ", cin >> x; 
		if (x > 0) {
			positiveCount += 1; 
			positiveSum += x; 
		}
		else if (x < 0) {
			negativeCount += 1; 
			negativeSum += x; 
		}
	}

	cout << endl; 

	cout << "Liczba liczb > 0: " << positiveCount << endl;
	cout << "Suma liczb > 0: " << positiveSum << endl;

	cout << endl; 

	cout << "Liczba liczb < 0: " << positiveSum << endl;
	cout << "Suma liczb < 0: " << negativeSum << endl;

}

void zad4() {

	cout << endl; 

	int n; 
	do {
		cout << "Wprowadz liczbe liczb w ciagu wieksza od 0: "; 
		cin >> n; 
	} while (n <= 0); 
	
	int sumaParzystych = 0;  
	for (int i = n; i >= 0; i--) {
		if (i % 2 == 0) {
			sumaParzystych += i; 
		}
	}

	cout << endl << "Suma liczb parzystych twojego ciagu: " << sumaParzystych << endl;
}

void zad5() {

	cout << endl; 

	cout << "Zad 5" << endl << endl; 

	// Przedzial (-10, 45)
	int przedzial[56]; 
	for (int i = 0, j = -10; i < 56; i++, j++) {
		przedzial[i] = j; 
	}

	// Losowa liczba z przedzialu (-10, 45)
	int losowaLiczba; 
	srand(time(NULL)); 
	for (int i = 0; i < 5; i++) {
		losowaLiczba = rand() % 56; 
		cout << i << " losowa liczba: " << przedzial[losowaLiczba] << endl; 
	}

	// Suma liczb parzystych w przedziale (-10, 45) 
	int sumaParzystych = 0; 
	for (int i = 0; i < 56; i++) {
		if (przedzial[i] % 2 == 0) {
			sumaParzystych += przedzial[i]; 
		}
	}
	cout << endl << "Suma parzystych liczb w przedziale (-10, 45): " << sumaParzystych;

	cout << endl; 
}

int main()
{
	zad1(); 
	zad2();
	zad3(); 
	zad4(); 
	zad5();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
