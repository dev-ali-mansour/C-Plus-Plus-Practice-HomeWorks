#include <iostream>

using namespace std;

class Shape {
private:
    string name;

public:
    Shape(const string &name_) : name(name_) {
    }

    // Shape can't provide default implementation of calculateArea
    // Use virtual to means so
    // This is then incomplete class, aka abstract
    virtual int calculateArea() = 0;    // Pure virtual

    string getShapeName() {
        return name;
    }

    virtual ~Shape() {}
};