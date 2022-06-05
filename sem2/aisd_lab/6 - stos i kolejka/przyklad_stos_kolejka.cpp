#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void demo_stos();
void demo_kolejka();

int main() {
	
	// demo_stos();
	demo_kolejka();
	
	return 0;
}

void demo_stos() {
	stack<char> stos;	//stack<int> stos_int; stack<string> stos_string;
	cout << "****************  stos  ****************" << endl;
	cout << "Wypelnianie stosu" << endl;
	for (char p = 'a'; p <= 'z'; p++) {
		stos.push(p);
		cout << p << ' ';
	}
	cout << " <- wierzcholek stosu" << endl;
	cout << "size() -> " << stos.size() << endl << endl;
	cout << "Oproznianie stosu" << endl;
	while (!stos.empty())
	{
		cout << stos.top() << ' ';
		stos.pop();
	}
	cout << endl << endl;
}

void demo_kolejka() {
	cout << "****************  kolejka  ****************" << endl;
	cout << "Wstawianie do kolejki" << endl << "poczatek -> ";
	queue<int> kolejka;
	for (int i = 10; i <= 100; i = i + 10) {
		kolejka.push(i);
		cout << i << ' ';
	}
	cout << " <- koniec" << endl;
	cout << "back() -> " << kolejka.back() << endl;
	cout << "front() -> " << kolejka.front() << endl;
	cout << "size() -> " << kolejka.size() << endl;

	cout << endl << "Kolejnosc przetwarzania elementow w kolejce: " << endl;
	while (!kolejka.empty())
	{
		cout << kolejka.front() << ' ';
		kolejka.pop();
	}
	cout << endl;
}

