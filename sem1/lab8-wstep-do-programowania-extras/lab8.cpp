#include <iostream>

using namespace std; 

void zad1() {

  int a, *ptr = &a; 

  // Adres 
  cout << ptr << endl; 

  // Pobierz i wyswietl wartosc 
  cout << "a: ", cin >> a;  
  cout << *ptr << endl; 


  // Roznica z uzyciem wskaznikow 
  int b, *ptr2 = &b; 
  cout << "b: ", cin >> b; 
  cout << *ptr << " - " << *ptr2 << " = " << *ptr - *ptr2 << endl; 

  // Srednia 
  int c = 1, *ptr3 = &c; 
  cout << "srednia: " << *ptr << ", " << *ptr2 << ", " << *ptr3; 
  cout << " = " << (double)((*ptr) + (*ptr2) + (*ptr3)) / 3 << endl;  

  delete ptr, ptr2, ptr3; 
}

void zad2() {
  int *ptr, n;

  cout << "wpisz przedzial: ", cin >> n;  

  ptr = new int[n]; 

  srand(time(0));

  for (int i = 0; i < n; i++) {
    ptr[i] = rand() % n; 
    // adresy elementow 
    cout << i << " " << &ptr[i] << endl;
   
  }

  cout << endl;

  // adres 1 elementu (indeks 0, element 1) 
  cout << "1 " << ptr << endl; 

  // adres 4 elementu (indeks 4, element 5)
  cout << "4 " << ptr + 4<< endl; 

  delete ptr; 
}

void zad3() {

  int *ptr, n; 

  cout << "Ile elementow tablicy do wprowadzenia?: ", cin >> n; 

  ptr = new int[n]; 

  int suma = 0; 

  for (int i = 0; i < n; i++) {
    cout << i << " element: ", cin >> ptr[i];  
    suma += ptr[i]; 
  }

  double srednia = (double)suma / n; 

  cout << "Srednia elementow: " << srednia << endl; 

  for (int i = 0; i < n; i++) 
    if (ptr[i] > srednia)
      cout << ptr[i] << " jest wiekszy od sredniej" << endl;   
  
}

void zad4(int *n) {
  (*n) = (*n) * (*n); 
}

int* zad5(int* n, int* pow) {
  int oryginalna_liczba = *n; 
  for (int i = 1; i < *pow; i++) {
    (*n) *= oryginalna_liczba; 
  }
  return n; 
}

void zad6(char *c, int *n) {
  for (int i = 0; i < *n; i++) {
    cout << *c; 
  }
  *n -= 1; 
}

int zad7_1 (int* a, int* b) {
  return *a < *b ? *a : *b; 
}

int* zad7_2 (int* a, int* b) {
  return *a < *b ? a : b; 
}

void zamiana(int *a, int *b) {
  int temp = *a; 
  *a = *b; 
  *b = temp; 
}

int main () {

  // zad1(); 
  // zad2(); 
  // zad3(); 

  /* Zad 4 */ 

  // int zad4var = 2; 
  // int* zad4ptr = &zad4var; 
  // zad4(zad4ptr);  
  // cout << zad4var << endl; 

  /* Zad 5 */ 

  // int zad5var = 2; 
  // int zad5pow = 8; 

  // cout << *zad5(&zad5var, &zad5pow) << endl; 
  // cout << zad5var << endl;  

  /* Zad 6 */ 

  // int zad6IleRazy = 5; 
  
  // char zad6Char = 'a'; 

  // char *zad6Ptr;  
  // zad6Ptr = &zad6Char; 
  
  // zad6(zad6Ptr, &zad6IleRazy);

  // cout << "\t" << zad6IleRazy << endl;  

  /* Zad 7 */ 

  // int a = 1; 
  // int b = 2; 

  // cout << zad7_1(&a, &b) << endl; 
  // cout << *zad7_2(&a, &b) << endl; 

  /* Zad 8 */ 

  // int c = 1; 
  // int d = 2; 

  // zamiana(&c, &d); 

  // cout << c << endl; 
  // cout << d << endl; 

}