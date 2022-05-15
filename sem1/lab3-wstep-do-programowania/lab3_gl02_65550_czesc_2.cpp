#include <iostream>
#include <time.h>

using namespace std; 

void zad1() {
	/*
	Grupa laboratoryjna składa się z n studentów (wartość n podaje użytkownik). Wprowadzamy
	liczbę punktów dla każdego studenta. Napisz program, który obliczy średnią liczbę punktów w
	grupie z wykorzystaniem pętli while.
	*/

	cout << endl << "Zad 1" << endl;

	cout << endl;

	int n; 
	do {
		cout << "Wprowadz liczbe studentow: ", cin >> n; 
	} while (n <= 0);

	int* studenciPunkty = new int[n];

  // Wykorzystanie petli while jest pozniej w tym zadaniu i w pozniejszych zadaniach
	for (int i = 0; i < n; i++) {
		int pkt; 
		cout << "Wprowadz liczbe punktow dla studenta " << i << ": ", cin >> pkt;
		studenciPunkty[i] = pkt; 
	}

	double sredniaPunktow = 0; 
	int sumaPunktow = 0; 
	int i = 0; 
 
	while (i < n) {
		sredniaPunktow += studenciPunkty[i];
		sumaPunktow += studenciPunkty[i];
		i++;
	}
	sredniaPunktow = sredniaPunktow / n;

	cout << "Srednia z " << sumaPunktow << " pkt dla " << n << " studentow: " << sredniaPunktow;

	cout << endl; 
}

void zad2() {
	/*
	W poprzednim zadaniu użytkownik może wprowadzać wartości z dowolnego przedziału.
	Zmodyfikuj program tak, by można było wprowadzać wartości tylko z przedziału 0 – 100.
	*/

	cout << endl << "Zad 2" << endl;

	cout << endl;

	int n;
	do {
		cout << "Wprowadz liczbe studentow: ", cin >> n;
	} while (n <= 0);

	int* studenciPunkty = new int[n];

	for (int i = 0; i < n; i++) {
		int pkt;
		
		do {
			cout << "Wprowadz liczbe punktow dla studenta (przedzial 0-100) " << i << ": ";
			cin >> pkt;
		} while (pkt < 0 or pkt > 100); 
		
		studenciPunkty[i] = pkt;
	}

	double sredniaPunktow = 0;
	int sumaPunktow = 0;
	int i = 0;
	while (i < n) {
		sredniaPunktow += studenciPunkty[i];
		sumaPunktow += studenciPunkty[i];
		i++;
	}
	sredniaPunktow = sredniaPunktow / n;

	cout << "Srednia z " << sumaPunktow << " pkt dla " << n << " studentow: " << sredniaPunktow;

	cout << endl;
}

void zad3() {
	/*
	Zastosuj instrukcje continue w programie z Zadania 2 tak, aby po podaniu liczby punktów spoza
	przedziału 0 – 100 pomijać dalsze wykonywanie pętli. Sprawdź działanie programu. Następnie
	zmień pętlę na nieskończoną, czyli taką której warunek zawsze jest prawdziwy.
	*/

	cout << endl << "Zad 3" << endl;

	cout << endl;

	int n;
	do {
		cout << "Wprowadz liczbe studentow: ", cin >> n;
	} while (n <= 0);

	int* studenciPunkty = new int[n];

  int i = 0; 

	// Nieskonczona petla: while (true) { ... } - nie chce Pani komputera psuc:) 
  while (i < n) {

    int pkt;

		cout << "Wprowadz liczbe punktow dla studenta (przedzial 0-100) " << i << ": ", cin >> pkt; 

    if (pkt < 0 or pkt > 100) {
			cout << "Zly przedzial, sprobuj jeszcze raz!" << endl;
			continue; 
		}

		studenciPunkty[i] = pkt;
    i++; 
  }

	double sredniaPunktow = 0;
	int sumaPunktow = 0;
	int j = 0;
	while (j < n) {
		sredniaPunktow += studenciPunkty[j];
		sumaPunktow += studenciPunkty[j];
		j++;
	}
	sredniaPunktow = sredniaPunktow / n;

	cout << "Srednia z " << sumaPunktow << " pkt dla " << n << " studentow: " << sredniaPunktow;

	cout << endl;
}

void zad4() {
	/*
	Zmodyfikuj program z Zadania 3, zastępując pętlę while na do…while.
	*/

	cout << endl << "Zad 4" << endl;

	cout << endl;

	int n;
	do {
		cout << "Wprowadz liczbe studentow: ", cin >> n;
	} while (n <= 0);

	int* studenciPunkty = new int[n];


  for (int i = 0; i < n; i++) {
    int pkt;
    do {
        cout << "Wprowadz liczbe punktow dla studenta (przedzial 0-100) " << i << ": ", cin >> pkt; 
    } while (pkt < 0 or pkt > 100);
		studenciPunkty[i] = pkt;
  }

	double sredniaPunktow = 0;
	int sumaPunktow = 0;
	int i = 0;
	do {
		sredniaPunktow += studenciPunkty[i];
		sumaPunktow += studenciPunkty[i];
		i++;
	} while (i < n); 

	sredniaPunktow = sredniaPunktow / n;

	cout << "Srednia z " << sumaPunktow << " pkt dla " << n << " studentow: " << sredniaPunktow;

	cout << endl;
}

void zad5() {

	cout << endl << "Zad 5" << endl;

	cout << endl; 
	for (int i = 1; i <= 100; i++) {
		cout << " | "; 
		cout << i << " | "; 
	}
	cout << endl; 
	cout << endl;
	for (int i = 100; i >= 0; i--) {
		cout << " | ";
		cout << i << " | ";
	}
	cout << endl;
	cout << endl;
	for (int i = 7; i < 78; i++) {
		if (i % 7 == 0) {
		cout << " | ";
		cout << i << " | ";
		}
	}
	cout << endl;
	cout << endl;
	for (int i = 20; i >= 0; i--) {
		if (i % 2 == 0) {
			cout << " | ";
			cout << i << " | ";
		}
	}
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