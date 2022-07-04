
using namespace std; 

#include <iostream>

/* 5a szablony pdf */ 

/* 5a szablony pdf -> zad 4 */ 
#include <iomanip> 

class FunkcjaKwadratowa {
    float a, b, c;
public:
    FunkcjaKwadratowa(float a, float b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    friend void rownanie(FunkcjaKwadratowa*);
};

void rownanie(FunkcjaKwadratowa* funkcja) {

    float a = funkcja->a; 
    float b = funkcja->b; 
    float c = funkcja->c; 

    float delta = (b * b) - (4 * a * c);

    float x1, x2;

    if (delta > 0) {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        cout << "x1: " << setprecision(2) << fixed << x1 << endl;
        cout << "x2: " << setprecision(2) << fixed << x2 << endl;
    }
    else if (delta == 0) {
        x1 = (-b / (2 * a));
        cout << "x1: " << setprecision(2) << fixed << x1 << endl;
    }
    else {
        cout << "Pierwiastki funkcji nie istnieja, bo delta < 0." << endl;
    }
}
/* 5a szablony pdf -> zad 5 */ 
#include <fstream>
#include <string> 
void zad5(); 
class File {
    string nazwa;
public:
    File(string);
    void zapiszDane(string, string);
    void wypiszDane();
};

/* 5a szablony pdf -> zad 6 */

class Tablica {
    static const int N = 10; 
    int a[N][N];
    int b[N][N] = { 0 };
public: 
    void wczytaj_dane() {
        int h = 0; 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                a[i][j] = h;
                cout << a[i][j] << "\t"; 
                h++; 
            }
            cout << endl; 
        }
        cout << endl;
    }
    void przetworz_dane() {
        cout << "\nTablica odwrocona:\n"; 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                swap(b[i][j], a[j][i]);
                cout << b[i][j] << "\t"; 
            }
            cout << endl;
        }
        cout << endl; 
    }
    void zapisz_dane_do_pliku() {
        fstream plik("tablicaOdwrocona.txt");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                plik << b[i][j] << "\t"; 
            }
            plik << '\n';
        }
        plik.close(); 
    }
    void czytaj_dane_z_pliku(string nazwa) {
        cout << "Dane z pliku:\n"; 
        string linijka;
        fstream plik;
        plik.open(nazwa);
        if (plik.is_open()) {
            while (getline(plik, linijka)) {
                cout << linijka << '\n';
            }
        }
        plik.close();
    }
};
void zad6();

int main()
{
    zad6();
}

/* 5a szablony pdf -> zad 4 */

void zad4() {
    FunkcjaKwadratowa funkcja(2, 61, 25);
    rownanie(&funkcja);
}

/* 5a szablony pdf -> zad 5 */

void zad5() {
    File plik("dane.txt");
    plik.zapiszDane("Piotr", "Najda");
    plik.wypiszDane();
}

File::File(string nazwa) {
    this->nazwa = nazwa; 
}

void File::zapiszDane(string imie, string nazwisko) {
    ofstream plik; 
    plik.open(nazwa);
    plik << "Imie: " << imie << "\n" << "Nazwisko: " << nazwisko << "\n";
    plik.close(); 
}

void File::wypiszDane() {
    string linijka;
    ifstream plik;
    plik.open("dane.txt");
    if (plik.is_open()) {
        while (getline(plik, linijka)) {
            cout << linijka << '\n';
        }
    }
    plik.close();
}

/* 5a szablony pdf -> cw 6 */ 

void zad6() {
    Tablica tablica; 
    tablica.wczytaj_dane(); 
    tablica.przetworz_dane();
    tablica.zapisz_dane_do_pliku();
    tablica.czytaj_dane_z_pliku("tablicaOdwrocona.txt");
}