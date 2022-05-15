
#include <iostream>

using namespace std;

class Mother {
public: 
    void display() {
        cout << "Mama!" << endl; 
    }
};

class Daughter : public Mother {
public:
    void display() {
        cout << "Corka!" << endl;
    }
};

int main()
{
    Daughter cassandra;
    cassandra.display();
    Mother dorothy; 
    dorothy.display();
    return 0;
}

