
#include <iostream>
using namespace std;

class Prostokat {
	int w, h; 
	friend Prostokat duplicate(Prostokat);
public:
	Prostokat() {
		w = 5;
		h = 10;
	}
	Prostokat(unsigned int w, unsigned int h) {
		this->w = w;
		this->h = h;
	}
	unsigned int area() {
		return w * h;
	}
};

Prostokat duplicate(Prostokat p) {
	p.w = p.w * 2; // has access to private (& protected) variables of Prostokat
	p.h = p.h * 2; 
	return p; 
}

int main()
{
	Prostokat p2(5, 7); 
	p2 = duplicate(p2); 
	cout << p2.area(); 
	return 0; 
}

// na plusa zad 6 i 7 

// https://www.programiz.com/cpp-programming/friend-function-class