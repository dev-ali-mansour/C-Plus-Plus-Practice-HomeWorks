#include <iostream>

using namespace std;

class MyPair {
private:
    int first, second;
public:
    MyPair(int first_, int second_) : first(first_), second(second_) {}


    void print() {
        cout << "(" << first << "," << second << ")\n";
    }

    int operator[](int pos) const {
        if (pos == 0) return first;
        return second;
    }

    int &operator[](int pos) {
        if (pos == 0) return first;
        return second;
    }

    // ++x prefix increment operator
    MyPair &operator++() {
        ++first, ++second;   // Increment first
        return *this;       // Then return reference
    }

    // x++ postfix increment operator
    // DON'T return MyPair&: this is local variable
    MyPair operator++(int) {
        MyPair cpy = *this;   //Copy first
        ++first, ++second;
        return cpy;
    }
};

int main() {
    MyPair x1(1, 2);
    (++x1).print(); // (2,3)

    MyPair x2(1, 2);
    x2++.print();   //(1,2)
    x2.print();     //(2,3)

    return 0;
}