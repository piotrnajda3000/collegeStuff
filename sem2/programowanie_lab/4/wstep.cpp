
#include <iostream>

using namespace std; 

class Base {
    protected: 
        int x = 0, y = 1; 
};

class Derivative : public Base {
    public:
        void display() {
            cout << x << ", " << y << endl; 
        }
};

int main()
{
    Derivative obj; 
    obj.display(); 
    return 0; 
}

