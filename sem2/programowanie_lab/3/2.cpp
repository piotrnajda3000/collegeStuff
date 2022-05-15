/*

Napisz program, który zawiera klasę 
mającą dwie zmienne prywatne i jedną 
funkcję składową, która zwróci 
obszar prostokąta

*/ 


#include <iostream> 

using namespace std;

class Rectangle {
  // private tu mozna pominac 
  int a, b; 
  public: 
    Rectangle(int a, int b) {
      this->a = a; 
      this->b = b; 
    }
    int getArea() {
      return a * b; 
    }
}; 

int main () {
  Rectangle instance(3, 5); 
  cout << instance.getArea(); 
}