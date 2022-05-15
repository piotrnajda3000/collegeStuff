#include "GenerateArray.h"
#include "main.h"

int** GenerateArray::copy(int** arrToCopy) {
	int** arr = new int* [maxSize]; 
	for (int i = 0, size = 1; i < maxSize; i++, size++) {
		arr[i] = new int[size]; 
		for (int j = 0; j < size; j++) {
			arr[i][j] = arrToCopy[i][j]; 
		}
	}
	return arr; 
}

int** GenerateArray::sorted() {
	int** arraysSorted = new int* [maxSize];
	for (int i = 0, size = 1; i < maxSize; i++, size++) {
		arraysSorted[i] = new int[size];
		// fill up the array with ascending numbers 
		for (int j = 0; j < size; j++) {
			arraysSorted[i][j] = j;
		}
	}
	return arraysSorted;
}

int** GenerateArray::sortedInReverse() {
	int** arraysSortedInReverse = new int* [maxSize];
	for (int i = 0, size = 1; i < maxSize; i++, size++) {
		arraysSortedInReverse[i] = new int[size];
		// fill up the array with descending numbers 
		for (int j = 0; j < size; j++) {
			arraysSortedInReverse[i][j] = maxSize - j;
		}
	}
	return arraysSortedInReverse;
}

int** GenerateArray::randomOrder() {
	int** arraysRandomOrder = new int* [maxSize];
	for (int i = 0, size = 1; i < maxSize; i++, size++) {
		arraysRandomOrder[i] = new int[size];
		// fill up the array with descending numbers 
		for (int j = 0; j < size; j++) {
			arraysRandomOrder[i][j] = rand() % maxSize;
		}
	}
	return arraysRandomOrder;
}
