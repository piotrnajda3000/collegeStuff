#include <iostream>
#include "deque.h"
using namespace std;

int main()
{
	deque kolejka(5);
  
	cout << "enqueue_head('a') enqueue_tail('b') enqueue_head('c'): ";
	kolejka.enqueue_head('a');
	kolejka.enqueue_tail('b');
	kolejka.enqueue_head('c');
	kolejka.print();
	cout << "front -> " << kolejka.front() << " back -> " <<       
  kolejka.back() << endl;

	for (char p = 'a'; p <= 'c'; p++)
		kolejka.enqueue_head(p);
	kolejka.print();

	while (!kolejka.empty()) {
		cout <<"dequeue_tail() -> " << kolejka.dequeue_tail() << endl;
		kolejka.print();
	}

	if (kolejka.empty()) cout << "pusta kolejka" << endl;
	cout << "dequeue_head() -> ";
	kolejka.dequeue_head();

	return 0;
}

