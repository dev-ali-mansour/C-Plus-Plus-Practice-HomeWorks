#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double x, double y) : x(x), y(y) {}

    double getX() const {
        return x;
    }

    void setX(double x) {
        this->x = x;
    }

    double getY() const {
        return y;
    }

    void setY(double y) {
        this->y = y;
    }

    string toString() const {
        ostringstream oss;
        oss << "(" << x << ", " << y << ")";
        return oss.str();
    }
};

class Shape {
protected:
    int color;

public:
    Shape(int color) : color(color) {}

    virtual int computeArea() const {
        throw logic_error("Not implemented. Do override");
    }

    virtual void draw() const {
        // Not implemented now
        cout << "Drawing shape of area " << computeArea() << endl;
    }

    virtual Shape *clone() const {
        throw logic_error("Not implemented. Do override");
    }

    virtual ~Shape() {}

    int getColor() const {
        return color;
    }

    void setColor(int color) {
        this->color = color;
    }
};

class Rectangle : public Shape {
private:
    Point topLeft;
    Point bottomRight;

public:
    Rectangle(int color, Point &topLeft, Point &bottomRight) :
            Shape(color), topLeft(topLeft), bottomRight(bottomRight) {
    }

    virtual int computeArea() const override {
        return 10;  //Just compute
    }

    virtual void draw() const override {
        Shape::draw();
        cout << "Drawing Rectangle TL" << topLeft.toString()
             << " - BR" << bottomRight.toString() << endl;
    }

    virtual Shape *clone() const override {
        return new Rectangle(*this);
    };
};

class Circle : public Shape {
private:
    Point center;
    double radius;

public:
    Circle(int color, Point &center, double radius) :
            Shape(color), center(center), radius(radius) {
    }

    virtual int computeArea() const override {
        return 20;  //Just compute
    }

    virtual void draw() const override {
        Shape::draw();
        cout << "Drawing circle center" << center.toString()
             << " - radius " << radius << endl;
    }

    virtual Shape *clone() const override {
        return new Circle(*this);
    }
};

class ImageEditor {
protected:
    vector<Shape *> shapes;

public:
    void addShape(const Shape &shape) {
        shapes.push_back(shape.clone());
    }

    virtual void draw() const {
        cout << "ImageEditor::draw\n";
        for (auto shapePtr: shapes) {
            shapePtr->draw();
        }
    }

    virtual ~ImageEditor() {
        for (auto shapePtr: shapes) {
            delete shapePtr;
            shapePtr = nullptr;
        }
        shapes.clear();
    }
};

class AdobeImageEditor : public ImageEditor {
public:
    void enlargeShapes(double percent) {
        for (auto shapePtr: shapes) {
            // enlarge shape
        }
    }

};

void initialize(AdobeImageEditor *editor) {
    Point topLeft = Point(3, 4);
    Point bottomRight = Point(5, 6);
    Rectangle r1(10, topLeft, bottomRight);
    Point center = Point(8, 9);
    Circle c1(20, center, 3.5);

    editor->addShape(r1);
    editor->addShape(c1);
}

int main() {
    auto *editor = new AdobeImageEditor();

    initialize(editor);
    editor->draw();
    editor->enlargeShapes(0.5);

    delete editor;
    editor = nullptr;
    cout << "Bye\n";

    return 0;
}