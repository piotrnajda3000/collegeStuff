```c++
#include <iostream>



using namespace std; 



int main()
{

    

}


```

```c++
    int arr[]{ -2, 0, 4, -3, 2, 7 }; 
    int arrN = 6; 
```

```c++
    for (int a : arr) {
        cout << a << " ";
    }
```

```c++
void swap(int& a, int& b) {
    int temp = a; 
    a = b;
    b = temp; 
}
``` 