#include <iostream>
#include <vector>

using namespace std;

class Osoba {
  protected:
    string imie, nazwisko;
    int wiek;
  public:
    Osoba() {
      this->imie = "Jan";
      this->nazwisko = "Kowalski";
      this->wiek = 20;
    }
    Osoba(string i, string n, int w) {
      this->imie = i; 
      this->nazwisko = n; 
      this->wiek = w; 
    }
    ~Osoba() {
      cout << "Destruktor Osoba" << endl; 
    }
    void zapisz(string i, string n, int w) {
      this->imie = i; 
      this->nazwisko = n; 
      this->wiek = w; 
    }
    void wypisz() {
      cout << imie << ", " << nazwisko << ", lat " << wiek << endl;
    }
    void zapisz(int w) {
      this->wiek = w; 
    }
    void zapisz(string i, bool nazwisko=false) {
      if (nazwisko) this->nazwisko = i;
      else this->imie = i;  
    }
    static void globalClass() {
      cout << "Hej"; 
    }
    // Konstruktor kopiujący 
    Osoba(const Osoba &os) {
      this->imie = os.imie;
      this->nazwisko = os.nazwisko;
      this->wiek = os.wiek;
    } 
};


// Static by sie przydalo jakbysmy mieli naglowki, headery, pliki
// Pozwala nam sie odwołać do tej zmiennej z wszystkich częsci programu

static void global1(Osoba os) {
  cout << "Osoba: "; 
  os.wypisz(); 
}

static Osoba powiel(Osoba os) {

}

class Kobieta : public Osoba {
  public:
    const string plec = "Kobieta"; 
} Ewa; 

class Mezczyzna : public Osoba {
  public:
    const string plec = "Mezczyzna"; 
    void wypisz() {
      cout << imie << ", " << nazwisko << ", lat " << wiek << ", " << plec << endl;
    }
}; 

// https://pl.wikibooks.org/wiki/C%2B%2B/Funkcje_wirtualne

int main () {

  Osoba Janek; 
  Janek.zapisz("Jan", "Nowak",7);

  // Janek.wypisz();
  // Janek.zapisz("Marek");
  // Janek.wypisz();
  // Janek.zapisz("Nowe", true);
  // Janek.wypisz();  

  // global1(Janek); 

  // Osoba::globalClass(); 

  // Osoba JanekDwa(Janek);

  vector <Osoba> osoby; 
  osoby.push_back(Janek); 

  for (int i = 0; i < osoby.size(); i++) {
    osoby[i].wypisz(); 
  }

  Osoba Adam; 
  Osoba *wsk; 
  wsk = &Adam; 
  wsk->wypisz(); 

}