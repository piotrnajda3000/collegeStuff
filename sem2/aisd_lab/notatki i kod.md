**Deadline: 8 czerwca 15:25**

Random seed 
```c++
#include <ctime>

srand(time(NULL));
```

## Lab 1 - sortowanie 

```c++
void bubbleSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) { 
		bool swap = false;
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int pomocnicza = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = pomocnicza;
				swap = true;
			}
		}
		if (!swap) break;
	}
}
```

```c++
void selectSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) min = j; 
        }
        swap(arr[i], arr[min]); 
    }
}
``` 

```c++
void insertSort(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		int klucz = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > klucz) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = klucz;
	}
}
```

## Lab 2 - rekurencja 

Stack jest LIFO. 

Rekurencja: base case, recursive case

Zmniejszanie rozmiaru problemu - `return` albo `void`. 

```c++
#include <iostream>

using namespace std; 

long int silnia(int n) {
    if (n == 0) return 1; 
    return n * silnia(n - 1); 
}

int main()
{
    cout << silnia(4);
    // silnia(4) = 
        // n * silnia(3)
            // n * silnia(2)
                // n * silnia(1)
                    // n * silnia(0) 
                        // silnia(0) = 1
                    // 1 * 1 
                // 2 * 1
            // 3 * 2 
       // 4 * 6 
}
```


```c++
void odwroc(int* arr, int n) {
    if (n == 0) {
        return;
    }
    swap(arr[0], arr[n - 1]);
    odwroc(arr + 1, n - 2);
}

int main()
{
    int arr[]{ 1,2,3,4 }; 
    odwroc(arr, 4);
    /*
    odwroc([1, 2, 3, 4], 4) -> [4, 2, 3, 1] 
    odwroc([2, 3], 2) -> [4, 3, 2, 1] 
    */
}
``` 

## Lab 3 

### Programowanie dynamiczne vs rekursywne 

```c++
#include <iostream>

using namespace std; 

int fibRecursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1; 
    return fibRecursive(n - 1) + fibRecursive(n - 2); 
}

// fibRecursive(4)
    // fibRecursive(3) + fibRecursive(2) 
        // fibRecursive(3) = fibRecursive(2) + fibRecursive(1)
            // fibRecursive(2) = fibRecursive(1) + fibRecursive(0) = 1 
            // fibRecursive(1) = 1 
        // 1 + 1 = 2 
        // fibRecursive(2) = fibRecursive(1) + fibRecursive(0)
            // fibRecursive(1) = 1 
            // fibRecursive(0) = 0
        // 1 + 0 = 1 
    // 2 + 1 = 3 
// 3 

int fibDynamic(int n) {

    int* arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1; 

    for (int i = 2; i < n + 1; i++) {
        arr[i] = arr[i - 1] + arr[i - 2]; 
    }
    
    int result = arr[n]; 

    delete[] arr; 
    
    return result; 
}

// fibDynamic(4)  
    // arr = [0, 1] 
    // arr[2] = 1, arr = [0, 1, 1] 
    // arr[3] = 1 + 1 = 2, arr = [0, 1, 1, 2] 

int main()
{
    cout << fibDynamic(4);
    cout << endl; 
    cout << fibRecursive(4); 
}
``` 

### Dziel i rządź 

```c++
#include <iostream>

using namespace std;

int partition(int* arr, int l, int r) {
	int key = arr[r]; 
	int p = l;  
	for (int i = l; i < r; i++) {
		if (arr[i] < key) {
			swap(arr[p], arr[i]); 
			p++; 
		}
	}
	swap(arr[p], arr[r]); 
	return p; 
}

void quickSort(int* arr, int l, int r) {
	if (l < r) {
		int p = partition(arr, l, r); 
		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, r); 
	}
}

int main()
{
	int arr[]{ 2,8,7,1,3,5,6,4 }; 
	quickSort(arr, 0, 7); 
}
``` 

```c++
void merge(int* arr, int l, int m, int r)
{
    int n1 = m - l + 1; 
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;

    int k = l;

    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

}

void mergeSort(int* arr, int l, int r) {
    if (l < r) { 
        int m = (l + r) / 2;
        mergeSort(arr, l, m, point); 
        mergeSort(arr, m + 1, r, point);
        merge(arr, l, m, r, point); 
    }
}

```

## Lab 4 - binary search

### Rekursywnie

```c++
int binarySearch(int arr[], int l, int r, int y)
{
    if (l <= r) {
        int m = (l + r) / 2; 
        if (arr[m] == y) return m;
        if (arr[m] > y) return binarySearch(arr, 0, m - 1, y);
        else return binarySearch(arr, m + 1, r, y); 
    }
    return -1; 
}

/*
arr = 1,2,3,4,5,6,7,8 
binarySearch(arr, 0, 7, 3), arr = 1,2,3,4,5,6,7,8
    m = 3, arr[m] = 4 
    arr[m] > y => binarySearch(arr, 0, 2, y)
        arr = 1, 2, 3
        m = 1, arr[m] = 2 
        arr[m] < y => binarySearch(arr, 2, 2, y)
            arr = 3 
            m = 2, arr[m] = 3
            arr[m] = y => return m 
*/

int main() {

    int arr[]{ 1, 2, 3, 4, 5, 6, 7, 8 }; 
    int n = 8; 
    cout << binarySearch(arr, 0, n - 1, 3);

    return 0;
}
```

### Iteracyjnie 

```c++
int BinarySearch(int arr[], int x, int n) {
    int l = 0, r = n - 1; 

    while (l <= r) {
        int m = (l + r) / 2; 

        if (arr[m] == x) return m; 
        if (Y < L[mid]) r = m - 1; 
        else l = m + 1; 
    }
    return -1; 
}
```

## Lab 6 - stos i kolejka 

Inicjalizacja pola `const` w klasie listą
```c++
deque::deque(int rozmiar) :
	size(rozmiar),
	deQ(new char[size])
{}
```

## Inne

**Listy** - pamiec na wskazniki, brak random access - warto gdy czesto nowe dane, a rzadko odczytywane 

### BFS 
- O(V^2) w przypadku reprezentacji macierzowej
- O(V + E) w przypadku reprezentacji listowej 


### Merge lists i createSortedList

```c++
void createSortedList(list<int>& lista, int* tab, int n) {
	for (int i = 0; i < n; i++) {
		list<int>::iterator it = lista.begin();
		// bool insert = false; 
		while (it != lista.end()) {
			if (tab[i] < *it) {
				lista.insert(it, tab[i]);
				// insert = true; 
				break;
			}
			it++;
		}
		if (it == lista.end()) lista.push_back(tab[i]);
		// if (!insert) lista.insert(it, tab[i]); // push back? 
	}
}

void mergeLists(list<int>& l1, list<int>& l2, list<int>& l3) {
	// Polacz obie listy ze soba 
	list<int> joined; 
	joined.insert(joined.end(), l1.begin(), l1.end());
	joined.insert(joined.end(), l2.begin(), l2.end());
	//  1, 2, 5, 12, 63, 534, 5, 16, 34, 141 

	int m = l1.size() + 1; // wskazuje na drugie "5" 

	list<int>::iterator mid = joined.begin();
	advance(mid, (m - 1));

	list<int>::iterator i = joined.begin(); 
	list<int>::iterator j = joined.begin();
	advance(j, (m - 1));

	while (i != mid && j != joined.end()) {
		if (*i < *j) {
			l3.push_back(*i); 
			i++; 
		}
		else {
			l3.push_back(*j); 
			j++; 
		}
	}
	while (i != mid) {
		l3.push_back(*i); 
		i++; 
	}
	while (j != joined.end()) {
		l3.push_back(*j);
		j++;
	}
};
```