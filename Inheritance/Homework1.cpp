#include <iostream>

using namespace std;

class Shape {
};

class TwoDimensionShape : public Shape {
};

class Circle : public TwoDimensionShape {
};

class Square : public TwoDimensionShape {
};

class Triangle : public TwoDimensionShape {
};

class ThreeDimensionalShape : public Shape {
};

class Sphere : public ThreeDimensionalShape {
};

class Cube : public ThreeDimensionalShape {
};

class Tetrahedron : public ThreeDimensionalShape {
};

int main() {
    Square square;

    return 0;
}