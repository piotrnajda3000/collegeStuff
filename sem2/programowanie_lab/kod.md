# Kod

## Fibonacci dynamicznie

```c++
int n;

int *fib;

cout << "ile liczb fibonacciego mam wyznaczyć: ";

cin >> n;

fib = new int[n];

fib[0] = 1;
fib[1] = 1;

for (int i = 2; i < n; i++)
{
  fib[i] = fib[i - 1] + fib[i - 2];
}

for (int i = 0; i < n; i++) {
  cout << endl << "wyraz nr " << i + 2 << ": " << *fib;
  fib++;
}

for (int i = 0; i < n; i++) {
  cout << endl << "wyraz nr " << i + 2 << ": " << *(fib + i);
}

return 0;

```

## Techniki

- Nadpisanie funkcji w klasie dziedziczącej
- Struct dziedziczący po structcie

## Funkcje wirtualne

```c++
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
```

## Friend function in a class

```c++
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

// https://www.programiz.com/cpp-programming/friend-function-class
```
