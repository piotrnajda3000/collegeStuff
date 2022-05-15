#include <iostream>
#include <chrono> 
#include <iterator> 

using namespace std;

/*

Stwórz funkcję liczącą średnią arytmetyczną w tablicy.

Zmodyfikuj tą funkcję tak żeby stosowała wskaźniki.

Porównaj czas obliczenia obu funkcji.

*/ 

float c1(int arr[], int n) {
  
  float total = 0; 

  for (int i = 0; i < n; i++) {
    total += arr[i]; 
  }

  return total / n; 
}

float c2(int* arr, int n) {

  float total = 0; 

  for (int i = 0; i < n; i++) {
    total += *(arr + i);
  }

  return total / n; 
}

int main() {

  using chrono::high_resolution_clock; 
  using chrono::duration_cast; 
  using chrono::duration; 
  using chrono::milliseconds; 

  const int n = 5; 

  // c1 - no pointers
  int c1Arr[] = {1, 2, 3, 4, 5}; 

  // c1 timer 
  auto c1start = high_resolution_clock::now(); 
  c1(c1Arr, n);   
  auto c1end = high_resolution_clock::now(); 

  // c2 - with pointers
  int *c2Arr = new int[5]; 
  for (int i = 0; i < n; i++) {
    c2Arr[i] = i + 1; 
  }

  // c2 timer 
  auto c2start = high_resolution_clock::now(); 
  c2(c2Arr, n); 
  auto c2end = high_resolution_clock::now(); 

  // calculate rutimes  

  duration<double, milli> ms_c1 = c1end - c1start;
  duration<double, milli> ms_c2 = c2end - c2start;
  
  duration<double, milli> diff = ms_c1 - ms_c2; 

  // display runtimes 

  cout << "Czas bez wskaznikow: " << ms_c1.count(); 
  cout << endl; 
  cout << "Czas ze wskaznikami: " << ms_c2.count(); 
  cout << endl; 

  cout << "Roznica miedzy bez wskaznikow a ze wskaznikami wynosi:  " << endl << diff.count() << " ms." << endl;   

  // test funkcji 

  cout << c1(c1Arr, n) << endl; 
  cout << c2(c2Arr, n) << endl; 

  delete[] c2Arr; 
}