#include <iostream>
#include <vector> 
#include<string> 

using namespace std; 


/* Cz 1 */ 

struct Params {
	int life = 3;
	int maxMove = 4;
	int position[2]{ 0, 0 };
};

class Enemy : protected Params {
	virtual void move() {};
	friend void killAI(Enemy); 
};

void killAI(Enemy temp) {
	temp.life = 0;
}

template <class TT>

TT upgradeAI(TT temp) {
	return temp; 
}

template <class TTT>
class Palladyn : public Enemy { 
	TTT stamina; 
	string weapon = "sword";
	int mana = 10; 
public:
	void move(int x, int y) {
		if (x > maxMove || y > maxMove) return; 
		position[0] = x; 
		position[1] = y; 
	}
};

/* Cw 3 */ 

class Kot {
private:
	int whiskers = 5; 
	char gender; 
	unsigned int* pawsFlufiness = new unsigned int[4]; 
public:
	~Kot() {
		cout << "Meow!" << endl;
	}
	Kot() {
		gender = 'n'; 
		cout << "The Cat is here" << endl;
		unsigned int* end = pawsFlufiness + 3; 
		for (unsigned int* p = pawsFlufiness; p != end; p++) {
			cout << *p; 
		}
	}
	Kot(int whiskers) {
		gender = 'n';
		this->whiskers = whiskers;
	}
	void removeWhisker(int howMany) {
		if (howMany <= whiskers) {
			for (int i = 0; i < howMany; i++)
				cout << "Yoink!" << endl;
			this->whiskers -= howMany;
		}
		else if (howMany > whiskers) {
			this->whiskers = 0; 
		}
		else {
			cout << "Impossible!" << endl; 
		}
	}
	void changeGender(bool areYouSure) {
		if (areYouSure) {
			if (this->gender == 'm') this->gender = 'f';
			else this->gender = 'm'; 
		}
	}
	void changeGender(char gender) {
		this->gender = gender; 
	}
	void changePawFluffiness(int whichPaw, int fluffiness) {
		if (fluffiness > 0) {
			this->pawsFlufiness[whichPaw] = fluffiness;
			cout << "Look at you, Mr. Fluffypaws!" << endl;
		}
	}
};

class Kociatko : public Kot {
public:
	~Kociatko() {
		cout << "Miau :(" << endl; 
	}
	Kociatko() {}; 
	void changeGender(bool areYouSure, char gender) {
		cout << "aha"; 
	}
};


int main()
{
	// Kot kot; 
	Kociatko kociatko; // konstruktor kot,  destruktor kociatko, destruktor kot, 


}

/* Cz 1 */ 

void cz1() {
	Enemy ogr;
	Palladyn<vector<int>> arkadiusz;
	arkadiusz.move(3, 3);
	killAI(arkadiusz);
	killAI(ogr);

	upgradeAI(arkadiusz);
	upgradeAI(ogr);
	upgradeAI("kupka");
}

/* Cw 3 */ 