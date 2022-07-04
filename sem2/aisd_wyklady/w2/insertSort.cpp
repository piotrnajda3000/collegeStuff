// uzasadnij ze jest stabilne 

#include <iostream>
#include "../../helpers.cpp"

using namespace std; 

int* insertSort(int tab[], int n=5){

  for (int key = 1; key < n; key++) {
    for (int j = key - 1; j > -1; j--) {
      if (tab[j] > tab[key]) {
        swap(&tab[j], &tab[key]); 
        key = j; 
      } else {
        break; 
      }
    }
  }

  return tab; 

} 

int main () {

  int tab[] = {  64, 25, 12, 22, 11 }; 

  printArr(insertSort(tab, size(tab)), size(tab)); 

}



