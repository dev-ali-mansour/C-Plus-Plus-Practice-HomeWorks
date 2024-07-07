#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle() {
    width = height = 0;
}

Rectangle::Rectangle(double width_, double height_) {
    width = width_, height = height_;
}

double Rectangle::computeArea() {
    return width * height;
}

double Rectangle::computePerimeter() {
    return 2 * (width + height);
}

//Setters & Getters
double Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(long width) {
    this->width = width;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(long height) {
    this->height = height;
}