#include <iostream>
#include <algorithm>
#include <list>

using namespace std; 

void demo_lista();

list<char>::iterator listSearch(list<char>& lista, char znak);
void mergeLists(list<int>&, list<int>&, list<int>&);
bool deleteNode(list<char>& lista, int);
void createSortedList(list<int>&, int*, int);

int main() {

	list<int> lista0;
	int tab[]{ 5, 1, 63, 12, 534, 2 };
	createSortedList(lista0, tab, 6); // 1, 2, 5, 12, 63, 534 
	for (int a : lista0)
		cout << a << ' '; 
	

	/* Merge */ 
	list<int> lista1{ 5, 16, 34, 141 };
	list<int> lista2; 
	mergeLists(lista0, lista1, lista2);

	list<char> lista{ 'a','l','f','c' };
	
	deleteNode(lista, 1); 

	list<char>::iterator it = listSearch(lista, 'f'); 
	if (it == lista.end()) { // lista.end() bezposrednio za ostatnim elementem 
	cout << "Nie znaleziono";
	}
	else {
	cout << *it << endl; 
	}


	demo_lista();
}

void createSortedList(list<int>& lista, int* tab, int n) {
	for (int i = 0; i < n; i++) {
		list<int>::iterator it = lista.begin();
		// bool insert = false; 
		while (it != lista.end()) {
			if (tab[i] < *it) {
				lista.insert(it, tab[i]);
				// insert = true; 
				break;
			}
			it++;
		}
		if (it == lista.end()) lista.push_back(tab[i]);
		// if (!insert) lista.insert(it, tab[i]); // push back? 
	}
}

void mergeLists(list<int>& l1, list<int>& l2, list<int>& l3) {
	// Polacz obie listy ze soba 
	list<int> joined; 
	joined.insert(joined.end(), l1.begin(), l1.end());
	joined.insert(joined.end(), l2.begin(), l2.end());
	//  1, 2, 5, 12, 63, 534, 5, 16, 34, 141 

	int m = l1.size() + 1; // wskazuje na drugie "5" 

	list<int>::iterator mid = joined.begin();
	advance(mid, (m - 1));

	list<int>::iterator i = joined.begin(); 
	list<int>::iterator j = joined.begin();
	advance(j, (m - 1));

	while (i != mid && j != joined.end()) {
		if (*i < *j) {
			l3.push_back(*i); 
			i++; 
		}
		else {
			l3.push_back(*j); 
			j++; 
		}
	}
	while (i != mid) {
		l3.push_back(*i); 
		i++; 
	}
	while (j != joined.end()) {
		l3.push_back(*j);
		j++;
	}
};


bool deleteNode(list<char>& lista, int n) {
	if (n > lista.size() || n < 1) return false;
	list<char>::iterator it = lista.begin();
	while (n > 1) {
		it++;
		n--;
	}
	lista.erase(it);
	return true;
}

list<char>::iterator listSearch(list<char>& lista, char znak) {
	list<char>::iterator it = lista.begin(); 
	for (; it != lista.end(); it++) {
		if (*it == znak) return it; 
	}
	return it; 
}


void demo_lista() {
	list<char> lista{  'a','l','f','c' };

	/* Drukowanie demo */ 
    auto print_char = [](const char& n) { cout << n << ' '; };
    for_each(lista.begin(), lista.end(), print_char); cout << endl;
	for_each(lista.rbegin(), lista.rend(), print_char); cout << endl; // Drukuj od tylu - nie da sie .end() i .begin() 

	/* Niektore sposoby drukowania list */

	// Z funkcja for_each i funkcja lambda 
	for_each(lista.begin(), lista.end(), print_char); cout << endl;

	// Bez uzywania dodatkowych funkcji 
	list<char>::iterator it;
	for (it = lista.begin(); it != lista.end(); it++)
		cout << *it << ' ';
	cout << endl;

	// Najprostszy sposob 
	for (char a : lista)
		cout << a << ' ';
	cout << endl;

	/* Dodawanie znakow do calej listy */ 
    char znak;
    cout << "\nPodaj znaki (Enter, Ctrl-z): ";
    //while (cin >> znak)
    //    lista.push_back(znak); // lista.push_front(znak); 

	/* Zastepowanie znakow w liscie */ 
    for (it = lista.begin(); it != lista.end(); it++) { // nie it < lista.end() 
        lista.insert(it, 'x');
    }

	/* /Zastepowanie znakow w danej liscie/ 
    i 
	a l f c

		i 
	x a l f c 

			i 
	x a x l f c 

				i 
	x a x l x f c 
                             
	x a x l x f x c 
	
	*/

	// Usuniecie okreslonego elementu z listy bez uzycia funkcji 
    for (it = lista.begin(); it != lista.end(); ) {
        if (*it == 'x')
            it = lista.erase(it);
        else it++;
    }

	// Zamiana ostatniego znaku w liscie 
	char& a = lista.back();
	a = 'x';
}