/* 

Zadanie B)
B1) Napisz funkcję liczącą ciąg fibonacci.
B2) Skopiuj funkcję liczącą ciąg fibonacciego do osobnej funkcji i zmodyfikuj ją, 
tak aby
wpisywała każdy element do tablicy. Obie funkcje umieść w funkcji main().
B3) Zmodyfikuj funkcję z podpunktu B2), tak żeby rezerwowała przestrzeń tablicy 
na tyle
elementów ile ma mieć ciąg.

*/ 

#include <iostream>

using namespace std;

int zadanie2B() { 

  int n;

  int *fib; 

  cout << "ile liczb fibonacciego mam wyznaczyć: "; 

  cin >> n; 

  fib = new int[n]; 

  fib[0] = 1;
  fib[1] = 1; 

  for (int i = 2; i < n; i++) 
  { 
    fib[i] = fib[i - 1] + fib[i - 2]; 
  } 

  for (int i = 0; i < n; i++) { 
    cout << endl << "wyraz nr " << i + 2 << ": " << *fib;
    fib++;   
  } 

  for (int i = 0; i < n; i++) { 
    cout << endl << "wyraz nr " << i + 2 << ": " << *(fib + i);  
  } 
      
  return 0; 
      
  }

int main() {

  zadanie2B(); 

}