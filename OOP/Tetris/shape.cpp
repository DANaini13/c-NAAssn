#include "shape.h"
#include <iostream>
using namespace std;

Shape::Shape(const char baseChar) {
    this -> components = new char[4];
    for(int i=0; i<4; ++i) {
        components[i] = baseChar;
    }
}

Shape::~Shape() {
    delete [] components;
    components = 0;
}

void Shape::displayComponents(int number) {
    cout<<components[number];
}

LShape::LShape():Shape('*') {}

void LShape::display() {
    for(int i=0; i<4; ++i) {
        this -> displayComponents(i);
        cout<<endl;
    }
}

LSShape::LSShape():Shape('*') {}

void LSShape::display() {
    this -> displayComponents(0);
    cout<<endl;
    this -> displayComponents(1);
    this -> displayComponents(2);
    cout<<endl;
    cout<<' ';
    this -> displayComponents(3);
}