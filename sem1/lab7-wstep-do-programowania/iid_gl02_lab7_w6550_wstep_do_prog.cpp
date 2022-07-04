// 11_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std; 

string decToBin(int i) {
	
	if (i == 1) return "1"; 
	
	return decToBin(i / 2) + to_string(i % 2);

	// 6 -> 110 
	// 6 : 2 = 3, r = 0 
	// 3 : 2 = 1, r = 1 
	// 1 : 2 = 0, r = 1 

	// decToBin(6)
		// decToBin(3) + "0"
			// decToBin(1) + "1"
				// decToBin(1) = "1"
			// "1" + "1"
		// "1" + "1" + "0"
	// 110 

}

int nwd(int a, int b) {
	if (a == 0) return b; 
	if (b == 0) return a;  
	return nwd(b, a % b); 
}

int fib(int n) {
	if (n == 0) return 0; 
	if (n == 1) return 1; 
	return fib(n - 2) + fib(n - 1); 
}

int silnia(int n) {

	if (n == 1) return 1; 

	return silnia(n - 1) * n; 

	// 5! = 5 * 4 * 3 * 2 * 1  
	
	// silnia(5) 
		// silnia (4) * 5 
			// silnia (3) * 4
				// silnia(2) * 3
					// silnia(1) * 2
						// silnia(1) = 1 
					// 1 * 2 
				// 2 * 3 
			// 6 * 4 
		// 24 * 5  
	// 120 
}

float ntyWyraz(int n) {
	if (n == 1) return 0; 
	if (n == 2) return 0.5;
	return -ntyWyraz(n - 1) * ntyWyraz(n - 2);
}

int main()
{
	cout << decToBin(6) << endl;
	cout << nwd(10, 5) << endl; 
	cout << fib(10) << endl; 
	cout << silnia(5) << endl; 
	cout << ntyWyraz(3) << endl; 
}

