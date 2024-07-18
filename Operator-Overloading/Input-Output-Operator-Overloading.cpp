#include <iostream>

using namespace std;

class MyPair {
private:
    int first, second;
public:
    MyPair() :    // Empty constructor to allow using default
            first(-1), second(-1) {
    }

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

    int getFirst() const {
        return first;
    }

    void setFirst(int first) {
        MyPair::first = first;
    }

    int getSecond() const {
        return second;
    }

    void setSecond(int second) {
        MyPair::second = second;
    }
};

void operator>>(istream &input, MyPair &pair) {
    int a, b;
    input >> a >> b;
    pair.setFirst(a);
    pair.setSecond(b);
}

int main() {
    MyPair x, y;
    cin >> x;
    x.print();

    // But we can't read several objects
    // Recall cin>>x is function that return void
    // What if it returns cin object again!
    //cin >> x >> y;

    return 0;
}