#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std; 

class WypelnianieMacierzy {
	static const int size = 10; 
	int tab[size][size];
public: 
	void wczytajDane() {
		srand(time(NULL));
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) {
					tab[i][j] = rand() % 10;
				}
				else {
					tab[i][j] = 0;
				}
			}
		}
	}
	int przetworzDane() {
		int suma = 0; 
		for (int i = 0; i < size; i++) {
			suma += tab[i][i]; 
		}
		return suma; 
	}
	void wyswietlWynik() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << tab[i][j] << " ";
			}
			cout << endl; 
		}
	}
};

int main()
{
	WypelnianieMacierzy macierz; 
	macierz.wczytajDane(); 
	macierz.wyswietlWynik(); 
	cout << macierz.przetworzDane(); 
}

