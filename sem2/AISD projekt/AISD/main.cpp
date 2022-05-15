#include "main.h"

using namespace std; 

/* Constants */

const int initialSize = 1; // initial size = n = 1 
const int maxSize = 100;

int main() {
	/* Headers for the .csv table used to generate graphs */

	ofstream csv;
	csv.open("results.csv");
	csv << "algorithm,arrType,n,dominantOps" << endl;

	/* Counting dominant operations driver code */

	GenerateArray arrayGenerator; 

	int** arraysSorted = arrayGenerator.sorted();
	int** arraysSortedInReverse = arrayGenerator.sortedInReverse();
	int** arraysRandomOrder = arrayGenerator.randomOrder();

	// After bubble sort, we want the same array for insert sort. 

	int** arraysSortedInReverse2 = arrayGenerator.copy(arraysSortedInReverse);
	int** arraysSortedInReverse3 = arrayGenerator.copy(arraysSortedInReverse);

	// After insert sort, we want the same array for quicksort. 

	int** arraysRandomOrder2 = arrayGenerator.copy(arraysRandomOrder);
	int** arraysRandomOrder3 = arrayGenerator.copy(arraysRandomOrder);


	for (int i = 0, n = initialSize, nReverse = maxSize; i < maxSize; i++, n++, nReverse--) {
		//Sleep(100); // Necessary for random seed to refresh in a for loop 
		//srand(time(NULL)); 

		int numberToLookFor = rand() % n; // random number in range [0, n] 

		GraphPoint point; 

		/* Linear search */

		point = GraphPoint("linearSearch", "sorted", n); 
		linearSearch(arraysSorted[i], n, numberToLookFor, point);
		csv << point.formatCSV(); 

		point = GraphPoint("linearSearch", "sortedInReverse", n);
		linearSearch(arraysSortedInReverse[i], n, numberToLookFor, point);
		csv << point.formatCSV();

		point = GraphPoint("linearSearch", "randomOrder", n);
		linearSearch(arraysRandomOrder[i], n, numberToLookFor, point);
		csv << point.formatCSV();

		/* Binary search */

		point = GraphPoint("binarySearch", "sorted", n);
		binarySearch(arraysSorted[i], 0, n - 1, numberToLookFor, point);
		csv << point.formatCSV();

		/* Bubble sort */
		
		point = GraphPoint("bubbleSort", "sorted", n);
		bubbleSort(arraysSorted[i], n, point); 
		csv << point.formatCSV();

		point = GraphPoint("bubbleSort", "sortedInReverse", n);
		bubbleSort(arraysSortedInReverse[i], n, point);
		csv << point.formatCSV();

		point = GraphPoint("bubbleSort", "randomOrder", n);
		bubbleSort(arraysRandomOrder[i], n, point);
		csv << point.formatCSV();

		/* Insert sort */

		point = GraphPoint("insertSort", "sorted", n);
		insertSort(arraysSorted[i], n, point);
		csv << point.formatCSV();

		point = GraphPoint("insertSort", "sortedInReverse", n);
		insertSort(arraysSortedInReverse2[i], n, point);
		csv << point.formatCSV();
		
		point = GraphPoint("insertSort", "randomOrder", n);
		insertSort(arraysRandomOrder2[i], n, point);
		csv << point.formatCSV();

		/* Quicksort */

		arraysSortedInReverse = arrayGenerator.sortedInReverse();
		arraysRandomOrder = arrayGenerator.randomOrder();

		point = GraphPoint("quickSort", "sorted", n);
		quickSort(arraysSorted[i], 0, n - 1, point);
		csv << point.formatCSV(); 

		point = GraphPoint("quickSort", "sortedInReverse", n);
		quickSort(arraysSortedInReverse3[i], 0, n - 1, point);
		csv << point.formatCSV();
		
		point = GraphPoint("quickSort", "randomOrder", n);
		quickSort(arraysRandomOrder3[i], 0, n - 1, point);
		csv << point.formatCSV();
	}	

	csv.close(); 

	/* Testing area */

	int arr[] = { 5, 14, 64, 2, 324, 2342, 222, 12, 3, 1, 2, 5161, 7, 8, 56, 4 }; 
	int arrSize = sizeof(arr) / sizeof(arr[0]); 

	int sortedArr[] = { 1, 2, 3, 4, 10, 15, 16, 20 };
	int sortedArrSize = sizeof(sortedArr) / sizeof(sortedArr[0]); 

	return 0; 
}	

