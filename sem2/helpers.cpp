#include <iostream> 

using namespace std; 

void swap (int* x, int* y) {
  int temp = *x; 
  *x = *y; 
  *y = temp; 
}

void printArr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " "; 
  }
}