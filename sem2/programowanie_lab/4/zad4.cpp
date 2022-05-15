
#include <iostream>
using namespace std;

class Baza {
public:
    virtual void wypisz() {
        cout << "Baza "; 
    }
};

class Pochodna : public Baza {
public:
    void wypisz() {
        cout << "Pochodna" << endl; 
    }
};

int main()
{
    Baza baza; 
    Pochodna pochodna; 

    Baza* wsk = &pochodna; 
    wsk->wypisz(); // <=> (*wsk).wypisz() -> "Pochodna" 
}

// https://www.geeksforgeeks.org/virtual-function-cpp/