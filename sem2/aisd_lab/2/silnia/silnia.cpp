/*

4! = 4 * 3 * 2 * 1 

4! = 4 * 3!  

3! = 3 * 2! 

2! = 2 * 1! 

1! = 1 


---

4! = 4 * 3! = 4 * 3 * 2! = 4 * 3 * 2 * 1! = 4 * 3 * 2 * 1 * 0! = 
4 * 3 * 2 * 1 = 24 

*/ 

#include <iostream>

using namespace std; 

int factorial(int n) {
  if (n == 0)
    return 1; 

  return n * factorial(n - 1); 
}

int main (){

  cout << factorial(4); 


}