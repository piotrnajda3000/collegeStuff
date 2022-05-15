#include <iostream>

using namespace std;

/* 

Zadanie A)
Stwórz zmienną LICZBA, zawierającą liczbę całkowitą(naturalną) 1234,
następnie stwórz
wskaźnik o
nazwie W, i przypisz do niego adres alokacji zmiennej LICZBA, 
Wypisz ją na ekranie konsoli
w zapisie
dziesiętnym.
A1) Zmodyfikuj powyższy kod tak żeby wskaźnik W wypisał liczbę którą przechowuje.

*/ 

int main() {

  int liczba = 1234;

  int* w = &liczba; 

  cout << "liczba: " << liczba << endl; 

  cout << "adres: " << &liczba << endl;

  cout << "wskaznik: " << w << endl; 

  cout << "liczba ze wskaznika: " << *w << endl;  

  cout << "adres w formie dziesietnej: " << (long) w << endl; 

  

}