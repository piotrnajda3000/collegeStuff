#include <iostream> 

using namespace std; 

float zad2(int n, int m) { 
  
  float arr[50][50];

  for (int i = 1; i < n + 1; i++) {
    arr[i][0] = 0; 
  }

  for (int j = 1; j < m + 1; j++) {
    arr[0][j] = 1; 
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      arr[i][j] = (arr[i-1][j] + arr[i][j-1]) / 2; 
    }
  }
  return arr[n][m];

}

int main () {

  cout << zad2(4, 5); 

}


 