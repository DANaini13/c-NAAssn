#ifndef _SHAPE_H_
#define _SHAPE_H_

class Shape {
public:
    Shape(const char baseChar);
    ~Shape();
    void displayComponents(int number);
private:
    char* components;
};

class LShape:Shape {
public:
    LShape();
    void display();
};

class LSShape:Shape {
public:
    LSShape();
    void display();
};

#endif
