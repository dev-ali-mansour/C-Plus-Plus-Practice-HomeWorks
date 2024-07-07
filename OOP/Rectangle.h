#ifndef HOMEWORKS_RECTANGLE_H
#define HOMEWORKS_RECTANGLE_H

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle();

    Rectangle(double width_, double height_);

    double computeArea();

    double computePerimeter();

    double getWidth();

    void setWidth(long width_);

    double getHeight();

    void setHeight(long height);
};

#endif //HOMEWORKS_RECTANGLE_H
