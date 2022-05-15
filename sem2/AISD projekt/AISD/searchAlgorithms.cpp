#include "GraphPoint.h"

int linearSearch(int* arr, int n, int find, GraphPoint& point) {
	for (int i = 0; i < n; i++) {
		point.incrementDominantOps();
		if (arr[i] == find) return i;
	}
	return -1;
}

int binarySearch(int arr[], int l, int r, int x, GraphPoint& point)
{
	while (l <= r) {
		point.incrementDominantOps();
		int m = l + (r - l) / 2;
		if (arr[m] == x) return m;
		if (arr[m] < x) l = m + 1;
		else r = m - 1;
	}
	return -1;
}