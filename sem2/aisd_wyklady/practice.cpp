#include <iostream>
#include "../helpers.cpp"

using namespace std; 

int* insertSort(int arr[], int n=5){

  for (int key = 1; key < n; key++) {
    for (int j = key - 1; j > -1; j--) {
      if (arr[j] > arr[key]) {
        swap(&arr[j], &arr[key]); 
        key = j; 
      } else {
        break; 
      }
    }
  }

  return arr; 

} 

int main () {

  int arr[] = {  64, 25, 12, 22, 11 }; 

  printArr(insertSort(arr, size(arr)), size(arr)); 

}



