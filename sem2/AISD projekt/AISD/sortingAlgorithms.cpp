#include "GraphPoint.h"
#include "helpers.h"

void bubbleSort(int* arr, int n, GraphPoint& point) {
	for (int i = 0; i < n - 1; i++) {
		bool swap = false;
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int pomocnicza = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = pomocnicza;
				swap = true;
			}
			point.incrementDominantOps();
		}
		if (!swap) break;
	}
}

void insertSort(int* arr, int n, GraphPoint& point) {
	for (int i = 1; i < n; i++) {
		int klucz = arr[i];
		int j = i - 1;
		point.incrementDominantOps();
		while (j >= 0 && arr[j] > klucz) {
			point.incrementDominantOps();
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = klucz;
	}
}

/* Quicksort */

int partition(int arr[], int low, int high, GraphPoint& point) {
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high, GraphPoint& point)
{
	point.incrementDominantOps();
	if (low < high)
	{
		int pi = partition(arr, low, high, point);
		quickSort(arr, low, pi - 1, point);
		quickSort(arr, pi + 1, high, point);
	}
}