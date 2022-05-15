#include <iostream>
#include <iterator>
#include "../../helpers.cpp"

using namespace std; 

/* 

- What is the problem I'm trying to solve?
  - problem jest pojęciem pierwotnym 
- How will I solve it?
  - plan
- Divide and conquer my plan 
  - decompose and/or reduce problems in a plan 
  - wykonuj operacje elementarne (oczywiste w wykonaniu)  

- Input -> Output 
- Dane -> Wynik 

Algorytm - przepis na rozwiązanie problemu

Whiteboard. Paper. 

--- 

*/ 

int* selectionSort(int arr[], int size) {

  for (int step = 0; step < size - 1; step++) {

    int min_index = step; 

    for (int j = min_index + 1; j < size; j++) {

      if (arr[j] < arr[min_index]) {
        min_index = j; 
      }

    }

    swap(arr[min_index], arr[step]);

  }
  return arr; 
}

int main () {

  int arr[] = { 64, 25, 12, 22, 11 };  

  printArr(selectionSort(arr, size(arr)), size(arr)); 

}