#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void demo_stos();
void demo_kolejka();

void zad1(); 

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

	zad1(); 
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

/*

()

1. (
2. (( 
Brak zamykajacego 

(()) 
1. ( 
2. (( 
3. ( 
4. 

*/

void zad1() {
	stack<char> st; 
	string parentheses;
	cout << "Wprowadz nawiasy: ", cin >> parentheses; 
	for (int i = 0; i < parentheses.length(); i++) {
		if (parentheses[i] == '(') {
			st.push('(');
		}
		else {
			if (!st.empty()) st.pop();
			else {
				cout << "Brak otwieraj¹cego" << endl;
				return; 
			}
		}
	}
	if (!st.empty()) cout << "Brak zamykaj¹cego" << endl;
	else cout << "Prawidlowe" << endl; 
}