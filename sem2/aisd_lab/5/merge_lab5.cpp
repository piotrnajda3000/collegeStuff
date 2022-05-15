#include <iostream> 

using namespace std; 

void Merge(int, int, int, int A[], int B[]); 

int main(int argc, char** argv) { 

    //dwie poLowy tablicy - [0..4]; [5..9] - powinny by posortowane rosnca  
    
    int A[]{ 1,35,42,65,68,25,55,59,70,79 }; 
    
    int B[size(A)]; 
    
    Merge(0, 5, 9, A, B); 
    
    for (int b : B) 
        cout << b << ' '; 
    
    return 0; 

} 

void Merge(int l, int m, int r, int A[], int B[]) { 

    int i, j, k; 
    i = k = l; 
    j = m; 
    
    while (i < m && j <= r) { 
    
        if (A[i] < A[j]) { 
        
            B[k] = A[i];  
            
            i++;    
        } 
        else { 
            B[k] = A[j]; 
            j++;  
        } 
        
        k++;  
    } 
    
    while (i < m) { 
    
        B[k] = A[i];      
        i++; 
        k++;  
    
    } 
    
    while (j <= r) { 
        
        B[k] = A[j]; 
        j++;  
        k++;  
    
    } 
  
} 
