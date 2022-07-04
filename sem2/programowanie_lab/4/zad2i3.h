#pragma once

using namespace std; 

class Shape {
protected:
    int w, h;
public:
    void setData(int w, int h) {
        this->w = w;
        this->h = h;
    }
};

class Triangle : public Shape {
public:
    void area() {
        cout << "Pole trojkata: " << (float)w * (float)h / 2 << endl;
    }
};


class Rectangle : public Shape {
public:
    void area() {
        cout << "Pole trojkata: " << w * h << endl;
    }
};

class Animal {
protected:
    string nazwa;
    int wiek; 
public: 
    void setValue(string nazwa, int wiek) {
        this->nazwa = nazwa; 
        this->wiek = wiek; 
    }
};

class Zebra : public Animal {
public: 
    void wypisz() {
        cout << nazwa << ", " << wiek << ", zeberka" << endl; 
    }
};

class Delfin : public Animal {
public:
    void wypisz() {
        cout << nazwa << ", " << wiek << ", delfinek" << endl;
    }
};