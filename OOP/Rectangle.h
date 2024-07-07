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

    double getWidth() const;

    void setWidth(long width);

    double getHeight() const;

    void setHeight(long height);
};

#endif //HOMEWORKS_RECTANGLE_H
