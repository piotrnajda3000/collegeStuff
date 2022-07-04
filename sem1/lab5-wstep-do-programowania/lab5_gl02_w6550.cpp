#include <iostream>
#include <map> 

using namespace std;


void zad1() {
	cout << endl; 

	char zdanie[] = { "lot" };
	char zdanie2[] = { 'l', 'o', 't' }; 

	// "zdanie2" nie jest interpretowane jako ³añcuch znakowy, ale po prostu trzy oddzielne elementy tablicy
	// "zdanie2" jest o 1 mniejsze od "zdanie" i nie posiada znaku pustego na koncu
	// nie mozemy tez go wyswietlic jako 
	// cout << zdanie2; -- niepoprawne wyjscie! 
	// tak jak mozemy to zrobic z "zdanie"
	// cout << zdanie;

	cout << endl; 
}

void zad2() {
	cout << endl;

	int liczby[100];
	char znaki[100];

	int liczby2[1]; 

	cout << "Wprowadz znaki: ", cin >> znaki; 

	cout << znaki[0] << " " << znaki[1] << " " << znaki[2];

	// "cin >> liczby" nie dziala dla tablicy intow, dla tablicy charow tak;
	// jednak nie mozemy wciaz uzyc spacji w "cin >> znaki" -- tylko chary nastepujace bezposrednio po sobie 

	cout << endl << znaki;

	cout << endl;
}


void zad3() {
	cout << endl;

	char tab[] = "wiosna";
	cout << "liczba znakow: " << size(tab);

	// lub 
	cout << "\n liczba znakow: " << sizeof(tab) / sizeof(tab[0]); 

	cout << endl;
}

void zad4() {

	cout << endl;

	cout << "Wprowadz string: ";
	char str1[100];
	cin.get(); // usuniecie znaku pustego z ostatniej operacji cin 
	cin.get(str1, 100);
	cout << endl;

	// Kopiowanie 
	char str4[100];
	strcpy_s(str4, str1);
	cout << str4 << endl;

	cout << endl << "Liczba znakow w tablicy (bez null): " << strlen(str1) << endl;
	cout << "Rozmiar tablicy: " << size(str1) << endl; 

	// Laczenie
	char str2[200] = "Slowo sie rzeklo: ";
	strcat_s(str2, str1);
	cout << str2;

	cout << endl;
}

void zad5() {
	string pola[] = { 
	"Podaj nazwe ulicy na ktorej mieszkasz: ", "Podaj nr domu: ", 
	"Na ile oceniasz swoje umiejetnosci programowania w skali [2 - 5]: ", 
	"Twoj staz programistyczny: ", "Adres: ", "Ocena: ", "Staz: "
	};

	cout << endl; 

	char ulica[100], nrDomu[12];
	cin.get(); 
	cout << "Podaj swoja ulice: ", cin.getline(ulica, 100);
	cout << endl; 
	cout << "Podaj nr domu: ", cin.getline(nrDomu, 12); 
	string adres = "";
	adres.append(ulica); 
	adres.append(" "); 
	adres.append(nrDomu); 

	cout << endl; 

	int umiejetnosci; 
	cout << "Umiejetnosci programowania [2 - 5]: "; 
	do {
		cin >> umiejetnosci; 
	} while (umiejetnosci > 5 or umiejetnosci < 2); 

	cout << endl; 

	string staz = " dni";
	char stazDni[2]; 
	cout << "Staz w dniach: ", cin >> stazDni; 
	staz.insert(0, stazDni); 

	cout << endl; 

	int ocena; 
	cout << "Ocena: ", cin >> ocena; 
	ocena -= 1; 

	cout << pola[0] << ulica << endl; 
	cout << pola[1] << nrDomu << endl;
	cout << pola[2] << umiejetnosci << endl;
	cout << pola[3] << staz << endl;
	cout << pola[4] << adres << endl; 
	cout << pola[5] << ocena << endl; 
	cout << pola[6] << stazDni << endl;

	cout << endl; 

}

void zad6() {
	string spolgloski = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
	string samogloski = "aeiouAEIOU"; 

	char text[100]; 
	cin.get();
	cout << "Wprowadz tekst (bez polskich znakow, bo sie nie wyswietlaja w konsoli): ", cin.getline(text, 100);

	int spolgloskiIlosc = 0, samogloskiIlosc = 0;
	for (int i = 0; i < strlen(text); i++) {
		if (spolgloski.find(text[i]) != string::npos) {
			spolgloskiIlosc++; 
		} else if (samogloski.find(text[i]) != string::npos) {
			samogloskiIlosc++; 
		}
	}

	cout << "Liczba samoglosek: " << samogloskiIlosc << " a spolglosek: " << spolgloskiIlosc; 
}

int main()
{
	zad1();
	zad2();
	zad3();
	zad4();
	zad5();
	zad6();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
