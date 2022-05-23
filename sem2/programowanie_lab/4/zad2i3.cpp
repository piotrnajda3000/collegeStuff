
#include <iostream>
#include "zad2i3.h" 

using namespace std;



int main()
{
    Triangle triangle;
    Rectangle rectangle; 
    triangle.setData(1, 5);
    triangle.area();
    rectangle.setData(2, 5);
    rectangle.area();

    Zebra zebra;
    Delfin delfin; 
    zebra.setValue("Zebranek", 20); 
    zebra.wypisz();
    delfin.setValue("Delfinio", 30); 
    delfin.wypisz();
}

