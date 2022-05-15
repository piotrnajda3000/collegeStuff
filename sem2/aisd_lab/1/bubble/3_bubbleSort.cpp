#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	// const int n = 20;
	// int T[n];

	// srand(time(NULL));
	// for (int i = 0; i < n; i++)
	// {
	// 	T[i] = rand() % 100 + 1;
	// 	cout << T[i] << ' ';
	// }
	// cout << endl;
	int T[] = {-2, 0, 4, -3, 2, 7, 1}; 
	int n = 7; 
;
	for (int i = n - 1; i >= 1; i--) {
		bool swap = false; 
	    for (int j = 0; j < i; j++) { 
					if (T[j] > T[j + 1]) {
						// Zamiana miejsc			
						int temp = T[j]; 
						T[j] = T[j + 1]; 
						T[j + 1] = temp; 			
						swap = true; 
			}
		}
		cout << i << " " << swap << endl;  
		if (swap == false) {
			break; 
		}
	}
	
	for (int i = 0; i < n; i++)
		cout << T[i] << ' ';

	cout << endl;
	return 0;
}