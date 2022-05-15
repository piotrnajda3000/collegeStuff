#include <iostream>

using namespace std;

class Student {
    int nr;
    string name;
    float mark1, mark2, mark3;

public:
    void input(int nr) {
        cout << "Podaj imiÄ: ";
        cin >> name;
        this->nr = nr;
        cout << "Podaj ocenÄ 1: ";
        cin >> mark1;
        cout << "Podaj ocenÄ 2: ";
        cin >> mark2;
        cout << "Podaj ocenÄ 3: ";
        cin >> mark3;
    }

    float calculateAvg() {
        return (mark1 + mark2 + mark3) / 3;
    }

    void display() {
        cout << "ImiÄ: " << this->name << " | ";
        cout << "Nr albumu: " << this->nr << " | ";
        cout << "Ocena 1: " << this->mark1 << " | ";
        cout << "Ocena 2: " << this->mark2 << " | ";
        cout << "Ocena 3: " << this->mark3 << " | ";
        cout << "Ĺrednia ocen: " << this->calculateAvg() << endl;
    }
};

int main() {
    int ileStudentow;
    cout << "Ile studentĂłw: ";
    cin >> ileStudentow;

    Student* studenci = new Student[ileStudentow];

    for(int i = 0; i < ileStudentow; i++) {
        studenci[i].input(i);
    }

    cout << endl << endl;

    for(int i = 0; i < ileStudentow; i++) {
        studenci[i].display();
    }

    int nr;
    cout << "Podaj nr albumu studenta: ";
    cin >> nr;
    studenci[nr].display();
}