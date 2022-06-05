#include "deque.h"
#include <iostream>
using namespace std;

  deque::deque(int rozmiar) :
  	size(rozmiar),
  	deQ(new char[size])
  {}

bool deque::empty() {
	if (head == tail) {
		return true; 
	} 
	return false; 
}

bool deque::filled() {
  if (head == tail + 1 || (head == 0 && tail == size - 1))
    return true;
  return false; 
}

void deque::enqueue_head(char element) {
	if(filled()) {
    cout << "Kolejka pelna" << endl;
    return; 
  };  
  if (head == 0) {
    head = size - 1; 
  } else {
    head--;
  }
  deQ[head] = element; 
}

void deque::enqueue_tail(char element) {
  if(filled()) {
    cout << "Kolejka pelna" << endl;
    return; 
  };  
  deQ[tail] = element; 
  if (tail == size - 1) {
    tail = 0; 
  } else {
    tail++; 
  }
}

char deque::dequeue_head()
{
  if(empty()) {
    cout << "Blad niedomiaru"; 
    // dzieki temu mozemy uzywac strlen, strcp itp. 
    return '\0'; 
  }
  char temp = deQ[head]; 
  if (head == size - 1) {
    head = 0; 
  } else {
    head++; 
  }
  return temp; 
}

char deque::dequeue_tail() {	
  if(empty()) {
    cout << "Blad niedomiaru"; 
    return '\0'; 
  }
  if (tail == 0) {
    tail = size - 1;
  } else {
    tail--; 
  }
  return deQ[tail]; 
}

char deque::front() {
	return deQ[head];	
}

char deque::back() {
	if (tail == 0) return deQ[size - 1];
	return deQ[tail - 1];
}

void deque::print() {
	int i = head;
	if (head < tail)
		while (i < tail)
			cout << deQ[i++] << ' ';

	if (tail < head)
	{
		while (i < size)
			cout << deQ[i++] << ' ';
		i = 0;
		while (i < tail) cout << deQ[i++] << ' ';
	}
	cout << endl;
}