#include <iostream> 

using namespace std;

class TestClass {
  private: 
    int x; 
  public: 
    float y; 
    TestClass(int x = 1, float y = 0.001) {
      this->x = x; 
      this->y = y; 
    }
    void display (string text = "...") {
      cout << text << endl; 
      cout << x << endl; 
      cout << y << endl; 
    }
}; 

int main () {

  TestClass classInstance; 
  
  classInstance.y = 4.0; 

  classInstance.display(); 

  TestClass secondInstance; 
  secondInstance.display("druga instancja: "); 

}