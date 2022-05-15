#pragma once
class deque
{
private:
    const int size;  
    int head = 0;       // indeks poczatku kolejki
    int tail = 0;       // indeks konca kolejki
    char* deQ;         // tablica dynamiczna
public:
    deque(int); // konstruktor
    ~deque() { delete[] deQ; }

    bool empty();
    bool filled();

    void enqueue_head(char element);    
    void enqueue_tail(char element);   
    char dequeue_head();             
    char dequeue_tail();             

    char front();
    char back(); 

    void print();
};

