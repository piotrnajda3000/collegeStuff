#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
	int dane[]{ 8, 3, 6, 1, 7, 10, 0, 2, 11, 4, 9 }; //{ 10,6,15,1,8,12,16,0,2,7,9 };
	BST drzewo(dane, size(dane));
	drzewo.print(drzewo.root);
	
	cout << endl;

	cout << drzewo.search(9)->data << endl; 
	cout << drzewo.minKey() << endl; 
	cout << drzewo.maxKey() << endl; 
	drzewo.inOrder(drzewo.root); 
	cout << endl; 
	drzewo.preOrder(drzewo.root); 
	cout << endl; 
	drzewo.postOrder(drzewo.root); 

	return 0;
}
