#pragma once
class BSTNode {
public:
    int data;
    BSTNode* left, * right;
    BSTNode(int data, BSTNode* left, BSTNode* right); 
};

class BST
{    
public:
    BSTNode* root;  // korzeñ drzewa

    BST();
    BST(int T[], int size);		//tworzy drzewo na podstawie tablicy
    ~BST() { remove(root); }; 			        //usuwa drzewo, zwalnia pamiêæ
    
    bool insert(BSTNode*& node, int wartosc);   //zwraca true - wezê³ dodany, false-wêze³ ju¿ jest
    void remove(BSTNode* x);                    //usuwa poddrzewa o korzeniu w x
    BSTNode* search(int key);                   //zwraca wsk. na wêze³ zawieraj¹cy klucz key lub
                                               //NULL, jeœli drzewo BST nie posiada takiego wêz³a.
    int     maxKey();
    int     minKey();

    BSTNode* search(BSTNode* node, int key);
    int     minKey(BSTNode*);
    void    inOrder(BSTNode* x);
    void    preOrder(BSTNode* x);
    void    postOrder(BSTNode* x);
    
    void print(BSTNode* );

};
