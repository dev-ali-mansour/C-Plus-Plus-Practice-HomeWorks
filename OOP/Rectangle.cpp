#include <iostream>

using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle() {
        width = height = 0;
    }

    Rectangle(double width_, double height_) {
        width = width_, height = height_;
    }

    double computeArea() {
        return width * height;
    }

    double computePerimeter() {
        return 2 * (width + height);
    }

    // Setters & Getters
    double getWidth() {
        return width;
    }

    void setWidth(long width_) {
        width = width_;
    }

    double getHeight() {
        return height;
    }

    void setHeight(long height_) {
        height = height_;
    }
};

int main() {
    Rectangle r1;
    r1.setWidth(5);
    r1.setHeight(10);
    cout << r1.computeArea() << endl;   // 50

    Rectangle r2(10, 3);
    cout << r2.computeArea() << endl;   // 30
    r2.setWidth(0);
    cout << r2.computeArea() << endl;   // 0


    return 0;
}