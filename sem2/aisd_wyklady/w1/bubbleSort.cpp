#include <iostream>
#include "../../helpers.cpp"

using namespace std; 

int* bubbleSort(int arr[], int n) {

  for (int i = 0; i < n - 1; i++) {

    for (int j = 0; j < n - 1 - i; j++) {

      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]); 
      }
      
    }
  }
  return arr; 
}

int main (){

  int arr[] = { 64, 25, 12, 22, 11 }; 

  printArr(bubbleSort(arr, size(arr)), size(arr)); 

}