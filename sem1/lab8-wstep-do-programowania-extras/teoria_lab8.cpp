#include <iostream> 

using namespace std; 


void fun(int* ptr) {
  *ptr += 1; 
}

int main () { 

  // Store 'a' in some address in memory 
  int a = 5; 

  // Get address of 'a' with '&' 
  // Pointer variable points to the address of a 
  int *ptr = &a; 
  cout << "address of variable 'a' = " << ptr << endl; 
  
  // Dereferencing a pointer variable 
  cout << "'a' value = " << *ptr << endl;  

  // Preincrementing by dereferencing a pointer variable 
  // Note: this doesn't change the address, just the value 
  cout << ++(*ptr) << endl; 

  /* Arrays */ 

  // An array is a pointer to the first element of the array 
  int tab[10]; 

  // Displays the address of the first element of the array 
  cout << tab << endl; 

  // Displays the address of the fourth element of the array 
  cout << tab + 4 << endl; 

  /* Arrays > Dynamic allocation */ 

  // Dynamic memory allocation with pointers 
  int* ptr2; 
  int n; 
  cout << "array size: ", cin >> n;  
  ptr2 = new int[n]; 

  // We must free the memory up after using the array, to avoid memory leaks 
  delete ptr2; 

  /* Functions */ 

  int b = 3; 
  int* ptr3 = &b; 
  fun(ptr3); 
  cout << b << endl; 
  // or 
  fun(&b);
  cout << b << endl;  

}

