// w65550_lab_4_gl02_iid

#include <iostream>
#include <time.h>

using namespace std; 

void zad1() {

	int arr[10]; 

	int x = 3; 

	for (int i = 0; i < 10; i++, x += 3) {
		arr[i] = x; 
		cout << arr[i] << "\t"; 
	}

	cout << "\n"; 

}

void zad2() {

	cout << "\n";

	int arr[10];

	int x = 3;

	for (int i = 0; i < 10; i += 2, x += 6) {
		arr[i] = x;
		cout << arr[i] << "\t";
	}

	cout << "\n";

}

void zad3() {

	cout << "\n";

	int a; 
	cout << "Podaj a: ", cin >> a; 

	int arr[10]; 

	int x = 0; 

	for (int i = 9; i > -1; i--, x += 5) {
		arr[i] = a - x; 
		cout << arr[i] << "\t"; 
	}

	cout << "\n"; 

}

void zad4() {

	cout << "\n";

	int random; 
	srand(time(NULL)); 

	int randomArr[10];
	cout << "Tablica A: "; 
	for (int i = 0; i < 10; i++) {
		int randomNumber = rand() % 74 - 23; // z przedzialu [-23, 50] 
		randomArr[i] = randomNumber; 
		cout << randomArr[i] << "\t"; 
	}

	cout << "\n"; 

	int min = randomArr[0]; 

	for (int i = 0; i < 10; i++) {
		if (randomArr[i] < min) {
			min = randomArr[i]; 
		}
	}

	cout << "Najmniejsza liczba w tablicy A: " << min; 

	cout << "\n";
}

void zad5() {

	cout << "\n";

	int arr[5]; 

	for (int i = 0; i < 2; i++) {
		cout << "Podaj " << i + 1 << " wartosc tablicy: ", cin >> arr[i]; 
	}

	int suma; 

	for (int i = 0; i < 3; i++) {
		suma = arr[i] + arr[i + 1]; 
		arr[i + 2] = suma;
	}

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << "\t"; 
	}

	cout << "\n";
}

void zad6() {

	cout << "\n";

	int arr[20]; 

	for (int i = 0; i < 10; i++) {
		arr[i] = 65550; 
	}

	// Kopiowanie pierwszej polowy
	for (int i = 10; i < 20; i++) {
		arr[i] = arr[i - 10]; 
	}

	// Sprawdzenie 
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << "\n"; 
	}

	cout << "\n";
}

void zad7() {

	cout << "\n";

	int arr1[3][3] = { 
		1, 0, 0,
		0, 2, 0,
		0, 0, 3 
	}; 


	int suma = 0; 
	
	for (int i = 0, j = 0; i < 3; i++, j++) {
		suma += arr1[i][j]; 
	}

	cout << "Suma: " << suma; 

	cout << "\n";
}

void zad8() {

	cout << "\n";

	int arr1[3][3] = {
		1, 0, 0,
		0, 2, 0,
		0, 0, 3
	};

	int arr2[3][3] = {
		1, 0, 0,
		0, 2, 0,
		0, 0, 3,
	};

	int arrSum = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arrSum += arr1[i][j] + arr2[i][j]; 
		}
	}

	cout << "Suma macierzy: " << arrSum;

	cout << "\n";
}


int main()
{
	cout << "\n Zad 1";
	zad1();
	cout << "\n Zad 2";
	zad2();
	cout << "\n Zad 3";
	zad3();
	cout << "\n Zad 4";
	zad4();
	cout << "\n Zad 5";
	zad5();
	cout << "\n Zad 6";
	zad6();
	cout << "\n Zad 7";
	zad7();
	cout << "\n Zad 8";
	zad8();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie	