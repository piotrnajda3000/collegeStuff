#include <iostream>
#include <algorithm>
//#include <cstdlib>
//#include <ctime> 

using namespace std;

int BinarySearch(int [], int, int, int);

int main() {
    const int size = 10;
    int L[size];

    // wype�nianie tablicy
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++) 
        L[i] = rand() % 100 + 1;    
    
    // sortowanie
    sort(L, L + size);

    // wypisywanie
    for (int i = 0; i < size; i++)
        cout << L[i] << ' ';
    cout << endl;

    // dodaj kod implementacji algorytmu wyszukiwania binarnego
    
    int searchInt; 
    cout << "szukane: ", cin >> searchInt;
    int idx = BinarySearch(L, searchInt, 0, size - 1); 

    if (idx == -1) cout << "Nie znaleziono ";
    else cout << "Znaleziono na " << idx << endl; 

    return 0;
}

int BinarySearch(int L[], int Y, int start, int end) {

    if (start > end) return -1; 

    int mid = (start + end) / 2; 

    if (Y == L[mid]) return mid; 

    if (Y < L[mid]) return BinarySearch(L, Y, start, mid - 1); 

    return BinarySearch(L, Y, mid + 1, end); 

}