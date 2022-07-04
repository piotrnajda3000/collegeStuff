#include <iostream>

using namespace std;

#include <stack>
#include <string>

/*
Napisz program wykorzystujący stos, który sprawdza czy w danym wyrażeniu nawiasy
są prawidłowo zagnieżdżone. Np. wyrażenie "(()()(()))" jest prawidłowe, a ")(" oraz "(()" są
nieprawidłow
*/

void correctNesting(string txt)
{
	stack<char> s; 
	for (int i = 0; i < txt.length(); i++) 
	{
		if (txt[i] == '(') 
		{
			s.push('('); 
		}
		else
		{
			if (!s.empty()) s.pop(); 
			else
			{
				cout << "Brak otwierajacego" << endl;
				return; 
			}
		}	
	}
	if (!s.empty())
	{
		cout << "Brak zamykajacego" << endl;
	}
	else {
		cout << "Prawidlowe" << endl;
	}
}


int main()
{
	correctNesting("(()()(()))"); 
	correctNesting(")(");
	correctNesting("(()"); 
}
