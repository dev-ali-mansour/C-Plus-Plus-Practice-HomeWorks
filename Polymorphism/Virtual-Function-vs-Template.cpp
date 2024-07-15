#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(string name_) : name(name_) {}

    virtual double computeArea() const = 0;

    virtual ~Shape() {}

    const string &getName() const {
        return name;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(string &name_, int width_, int height_) :
            Shape(name_), width(width_), height(height_) {
    }

    virtual double computeArea() const override {
        return width * height;  //Just compute
    }
};

void process1(Shape *shape) {
    // This function knows nothing about children!

    // Compile time determined
    cout << "This shape name is: " << shape->getName() << ". ";

    // Runtime determined
    cout << "Its area: " << shape->computeArea() << endl;
}

template<typename Type>
Type process2(vector<Type> s) {
    Type sum = 0;

    for (Type t: s)
        sum += t;

    return sum;
}

int main() {
    string name = "Nice Rect";
    process1(new Rectangle(name, 4, 5));

    vector<int> v1 = {1, 2, 3, 4};
    vector<double> v2 = {0.4, 2.6, 3, 4};

    cout << process2(v1) << " " << process2(v2);  // 10 10
}

// If data type affect the behaviour use virtual function.
// Same code and different behaviour process(Rectangle) vs process(Circle)
// If it doesn't affect the behaviour use template
// Same code & behaviour stack<int> vs stack<string>