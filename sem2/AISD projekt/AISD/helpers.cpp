#include <iostream>

using namespace std; 

void printArr(int* tab, int rozmiar) {
	cout << endl; 
	for (int i = 0; i < rozmiar; i++) {
		cout << i + 1 << ". " << tab[i] << endl;
	}
	cout << endl;
}

void print2dArr(int** tabs, int rozmiar1, int rozmiar2) {
	for (int i = 0; i < rozmiar1; i++) {
		for (int j = 0; j < rozmiar2; j++) {
			cout << '[' << rozmiar1 << ']' << '[' << rozmiar2 << ']' << " = " << tabs[i][j] << endl;
		}
	}
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}