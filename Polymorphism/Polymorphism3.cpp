#include <iostream>

using namespace std;

class Shape {
private:
    string name;
public:
    Shape(string &name) : name(name) {
    }

    virtual int area() {
        throw logic_error("Not implemented. Do override");
    }

    string getShapeName() {
        return name;
    }

    virtual ~Shape() {}
};

class Rectangle : public Shape {
    int width;
    int height;

public:
    Rectangle(string &name, int width, int height) :
            Shape(name), width(width), height(height) {
    }

    int area() {
        return width * height;
    }
};