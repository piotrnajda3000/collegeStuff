// Fibonacci programowanie dynamiczne 

// uwaga: n + 1 

#include <iostream> 

using namespace std; 

int fib(int n) {

  if (n < 2) 
    return n; 

  int *arr = new int[n + 1]; 
  arr[0] = 0; 
  arr[1] = 1; 

  for (int i = 2; i < n + 1; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  int result = arr[n]; 

  delete[] arr; 

  return result; 
}

int fib2(int n) {

  if (n < 2) 
    return n; 

  int *arr = new int[n + 1]; 
  arr[0] = 0; 
  arr[1] = 1; 

  for (int i = 2; i < n + 1; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  int result = arr[n]; 

  delete[] arr; 

  return result; 
}


int main () {

  int n; 
  cout << "w fib(n), podaj n: "; 

  do {
    cin >> n; 
  } while (n < 0); 

  cout << endl << fib(n); 
}


 