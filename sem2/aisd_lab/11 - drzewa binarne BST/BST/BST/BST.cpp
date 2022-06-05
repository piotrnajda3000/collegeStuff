#include <iostream>
#include "BST.h"
using namespace std;

BST::BST():root(NULL) {}

BST::BST(int tab[], int size) {
	for (int i = 0; i < size; i++)
		insert(root, tab[i]);
}

BSTNode::BSTNode(int data, BSTNode* left, BSTNode* right) {
	this->data = data; 
	this->left = left;
	this->right = right; 
}

bool BST::insert(BSTNode*& node, int wartosc) {
	if (node == NULL) { // tworzymy i dołączamy węzeł          
		node = new BSTNode(wartosc, NULL, NULL);
		return true;
	}
	// uwaga: liczby powtarzające się nie są dodawane do drzewa		
	if (wartosc < node->data) return insert(node->left, wartosc);              
	if (wartosc > node->data) return insert(node->right, wartosc);           
	return false;
}

BSTNode* BST::search(int key) {
	return search(root, key); 
}

BSTNode* BST::search(BSTNode* node, int key) {
	BSTNode* curr = node;
	while (curr != NULL) {
		if (curr->data == key) return curr;
		if (curr->data > key) curr = curr->left;
		else curr = curr->right;
	}
	return NULL;
}
	
int BST::minKey() {
	return minKey(root); 
}

int BST::minKey(BSTNode* node) {
	while (node->left != NULL) {
		node = node->left; 
	}
	return node->data; 
}

int BST::maxKey() {
	BSTNode* tmp = root; 
	while (tmp->right != NULL) {
		tmp = tmp->right; 
	}
	return tmp->data;
}

void BST::inOrder(BSTNode* x) {
	if (x->left != NULL) inOrder(x->left); 
	cout << x->data << " "; 
	if (x->right != NULL) inOrder(x->right); 
}

void BST::preOrder(BSTNode* x) {
	cout << x->data << " "; 
	if (x->left != NULL) preOrder(x->left); 
	if (x->right != NULL) preOrder(x->right);
}

void BST::postOrder(BSTNode* x) {
	if (x->left != NULL) postOrder(x->left);
	if (x->right != NULL) postOrder(x->right);
	cout << x->data << " ";
}

//void BST::postOrder(BSTNode* x) {}

void BST::print(BSTNode* x){
	if (!x->left && !x->right) return;

	cout <<  x->data  << " : lewy-> ";
	if (x->left) cout << x->left->data;
	else         cout << "NULL";
	
	cout               << ", prawy-> ";
	if (x->right) cout << x->right->data;
	else          cout << "NULL";
	              cout << endl;
	
	if (x->left)  print(x->left);
	if (x->right) print(x->right);
}

void BST::remove(BSTNode* x) {
	if (!x) return;
	remove(x->left);
	remove(x->right);
	cout << "usuwam " << x->data << endl;
	delete x;
}