#include <iostream> 

using namespace std;

int main() {

	enum Miesiace {
		Styczen = 1,
		Luty,
		Marzec,
		// ...  
	}; 

	Miesiace ktory;
	ktory = Marzec; // 3 

	////////////////////

	struct Osoba {
		string imie; 
		string nazwisko; 
		int wiek; 
	};

	struct Man : Osoba {
		char gender = 'M'; 
	};

	Osoba jan; 	
	Man adam; 

	enum Plec {
		man,
		woman,
	};

	struct DaneOsobowe {
		string imie; 
		string nazwisko;
		Plec plec; 
	};

	DaneOsobowe arr[10]; 

	arr[0].imie = "Adam"; 

	return 0; 
}