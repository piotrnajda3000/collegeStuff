#pragma once 

#include <iostream> 
#include <string> 

using namespace std; 

class Color { 
  private:
    int r;
    int g; 
    int b;
    string name;
  public:
    // Color (){ 
    //   r=255; 
    //   g=255;
    //   b=255;
    //   strcpy(name, "bialy");
    // }
    Color (int c_r = 255, int c_g = 255, int c_b = 255, string n = "bialy"){
      r=c_r; 
      g=c_g; 
      b=c_b; 
      this->name = n;
    }
    ~Color() { //definicja destruktora
        cout<< "Destruktor";
    }
    void setColor(int c_r, int c_g, int c_b){
      r=c_r; 
      g=c_g; 
      b=c_b;
    }
    string getName(){ 
      return name;
    }
}; 