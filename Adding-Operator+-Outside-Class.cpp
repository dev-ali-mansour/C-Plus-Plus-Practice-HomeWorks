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

    int getFirst() const {
        return first;
    }

    void setFirst(int first_) {
        MyPair::first = first_;
    }

    int getSecond() const {
        return second;
    }

    void setSecond(int second_) {
        MyPair::second = second_;
    }
};

MyPair operator+(const MyPair &c1, const MyPair &c2) {
    return MyPair(c1.getFirst() + c2.getFirst(),
                  c1.getSecond() + c2.getSecond());
}

MyPair operator+(const MyPair &c1, int x) {
    return MyPair(c1.getFirst() + x,
                  c1.getSecond() + x);
}

MyPair operator+(int x, const MyPair &c1) {
    return c1 + x;  // don't rewrite code
}

MyPair operator*(int x, const MyPair &c1) {
    return MyPair(c1.getFirst() * x,
                  c1.getSecond() * x);
}

MyPair operator-(const MyPair &c1, pair<int, int> p) {
    return MyPair(c1.getFirst() - p.first,
                  c1.getSecond() - p.second);
}

int main() {
    pair<int, int> p = make_pair(1, 3);
    MyPair x(1, 2);
    MyPair y(10, 20);

    MyPair z = x + y;
    MyPair z1 = x + 5;  // CE: 5 + x
    MyPair z2 = 3 * x;  // CE: x * 3
    MyPair z3 = x - p;  // CE: p - x
    z.print();  // (11,22)
    z1.print(); // (6,7)
    z2.print(); // (3,6)
    z3.print(); // (0,-1)

    MyPair z4 = 3 * x + 5 + x;
    z4.print(); // (9,13)

    return 0;
}