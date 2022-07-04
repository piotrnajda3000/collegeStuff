#include <iostream>
#include "zad2.h" 

// liczba pierwsza jest wieksza od 1 i dzieli sie tylko przez sama siebie 
// czyli musze podzielic liczbe przez wszystkie liczby od 2 do n - 1 i sprawdzic czy sie dzieli  

bool isPrime(int n, int i) {

	// int i to to, przez co bedziemy dzielic

	if (n <= 1)
		return false;

	if (n == i)
		return true;

	if (n % i == 0)
		return false;

	return isPrime(n, ++i);

}
