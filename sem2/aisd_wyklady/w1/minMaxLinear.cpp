#include <iostream>
#include <iterator>

using namespace std; 

/* 

Problem: find min and max in an array 
Algorytm: linear search 
https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
check out other methods later 
Dane: array 
Metoda: 

Wynik: wypisane elementy maksymalne i minmalne z tablicy 


*/

struct Pair {
  int min; 
  int max; 
}; 

Pair findMinMax(int arr[], int size) {

  struct Pair minmax; 

  if (size == 1) {
    minmax.max = arr[0]; 
    minmax.min = arr[0]; 
    return minmax; 
  }
 
  if (arr[0] > arr[1]) {
    minmax.max = arr[0]; 
    minmax.min = arr[1]; 
  } else {
    minmax.max = arr[1]; 
    minmax.min = arr[0]; 
  }

  for (int i = 2; i < size; i++) {
    if (arr[i] > minmax.max) {
      minmax.max = arr[i]; 
    }

    else if (arr[i] < minmax.min) {
      minmax.min = arr[i]; 
    }

  }
    return minmax; 
}


int main () {

  int arr[] = { 1, 1, 2 }; 

  Pair p = findMinMax(arr, size(arr)); 

  cout << p.max << " " << p.min; 

  cout << endl; 

}