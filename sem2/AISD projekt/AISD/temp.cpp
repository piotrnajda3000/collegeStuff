//#include "main.h"
//
//using namespace std;
//
//class PunktWykresu {
//public:
//	string sortowanie, daneWejsciowe, rozmiar, opDominujace;
//	void ustawDominujace(unsigned int e) {
//		opDominujace = to_string(e);
//	}
//	PunktWykresu(string sortowanie, string daneWejsciowe, int rozmiar, unsigned int opDominujace = 0) {
//		this->sortowanie = sortowanie;
//		this->daneWejsciowe = daneWejsciowe;
//		this->rozmiar = to_string(rozmiar);
//		this->opDominujace = to_string(opDominujace);
//	}
//	string formatCSV() {
//		return sortowanie + "," + daneWejsciowe + "," + rozmiar + "," + opDominujace + "\n";
//	}
//};
//
//PunktWykresu sortowanieBabelkowe(int* tab, int n, string daneWejsciowe) {
//
//	PunktWykresu pkt("babelkowe", daneWejsciowe, n);
//
//	unsigned int opDominujace = 0;
//
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - 1 - i; j++) {
//			if (tab[j] > tab[j + 1]) {
//				opDominujace += 5;
//				int pomocnicza = tab[j];
//				tab[j] = tab[j + 1];
//				tab[j + 1] = pomocnicza;
//			}
//		}
//	}
//
//	pkt.ustawDominujace(opDominujace);
//
//	return pkt;
//}
//
//int* sortowianiePrzezWstawianie(int tab[], int n = 7) {
//	for (int i = 1; i < n; i++) {
//		int klucz = tab[i];
//		j = i - 1;
//		while (j >= 0 && tab[j] > klucz) {
//			tab[j + 1] = tab[j];
//			j = j - 1;
//		}
//		tab[j + 1] = klucz;
//	}
//}
//
//
//int main() {
//
//	const int proby = 5;
//	int** tabs = new int* [proby];
//	for (int i = 0, n = 2; i < proby; i++, n *= 2) {
//		tabs[i] = new int[n];
//		for (int j = 0; j < n; j++) {
//			tabs[i][j] = (j + 1) + n;
//		}
//	}
//
//	int tab[] = { 1, 2 };
//	cout << sortowanieBabelkowe(tab, 2, "posortowane").formatCSV();
//
//	ofstream csv;
//	csv.open("wyniki.csv");
//
//	csv << "sortowanie,daneWejsciowe,rozmiar,opDominujace" << endl;
//
//	for (int i = 0, n = 2; i < proby; i++, n *= 2) {
//		PunktWykresu wynikproby = sortowanieBabelkowe(tabs[i], n, "posortowane");
//		csv << wynikproby.formatCSV();
//	}
//
//	csv.close();
//
//	return 0;
//}
//
