#include <iostream>
#include <string>
#include "zad1.h"
#include "zad2.h"

using namespace std; 

string decToBinary(int n) {
	string binary; 
	while (n) {
		binary = (n % 2 == 0 ? "0" : "1") + binary;
		n /= 2; 
	}
	return binary; 
}

int dwusilnia(int n) {
	if (n > 30 or n < 0)
		return n; // nie mozna  

	int ds = 1; 

	for (; n > 1; n -= 2) {
		ds *= n;
	}
	return ds; 
}

int main()
{
	cout << decToBinary(6);
	cout << endl << isPrime(7) << endl << isPrime(8); 
	cout << endl << dwusilnia(6);

}
