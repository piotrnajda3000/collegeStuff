#include <iostream> 

using namespace std;

float zad2(int n, int m) {

    const int size1 = n + 1; 
    const int size2 = m + 1; 

    float** arr = new float*[size1]; 
    for (int i = 0; i < size1; i++) arr[i] = new float[size2]; 

    for (int i = 1; i < size1; i++) {
        arr[i][0] = 0;
    }

    for (int j = 1; j < size2; j++) {
        arr[0][j] = 1;
    }

    for (int i = 1; i < size1; i++) {
        for (int j = 1; j < size2; j++) {
            arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) / 2;
        }
    }

    return arr[n][m];
}

int main() {

    cout << zad2(1, 5);

}
