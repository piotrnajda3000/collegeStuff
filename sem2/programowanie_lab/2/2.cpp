#include <iostream>
#include <vector> 
#include <iterator>
#include <algorithm> 

using namespace std;

void zad23() {

  // Zad 2 

  // Dodaj element na podany indeks 

  vector<int> tab; 

  for (int i = 1; i < 7; i++){
    tab.push_back(i); 
  }

  int x; 
  cin >> x; 

  int i; 
  cin >> i;

  for (int i = 0; i < tab.size(); i++) {
    cout << tab[i] << " "; 
  } 

  cout << endl; 

  // Wepchnij element x w indeks it  

  auto it = tab.begin();
  it += i;  
  tab.insert(it, x);

  // Wypisanie tablicy 

  for (int i = 0; i < 7; i++) {
    cout << tab[i] << " "; 
  } 

  // Zad 3 - Odwracanie ciagu, z stdlib "algorithm"

  reverse(tab.begin(), tab.end()); 

  // Zad 4 

  int a = 1, b = 2; 
  int *ptrA = &a, *ptrB = &b;

  // Zad 5 

  const char* arr; 
  arr = new char[20];
  arr = "A string";
  cout << endl << arr[0] << endl; 
  // A 

  // A string 
  cout << *arr << endl

  // string; 
  cout << *(arr + 3) << endl;
  arr++;
  arr++;

  // ring 
  cout << arr; 
}


 

int main() {

  zad23();




}