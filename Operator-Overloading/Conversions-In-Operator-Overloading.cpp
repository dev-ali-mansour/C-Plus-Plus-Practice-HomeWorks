#include <iostream>

using namespace std;

class MyPair {
private:
    int first, second;
public:
    MyPair(int x) : MyPair(x, x) {}

    MyPair(int first_, int second_) : first(first_), second(second_) {}

    void print() {
        cout << "(" << first << "," << second << ")\n";
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

MyPair operator+(const MyPair &c1, const MyPair &c2) {
    return MyPair(c1.getFirst() + c2.getFirst(),
                  c1.getSecond() + c2.getSecond());
}

int main() {
    MyPair x(1, 2);
    MyPair y(3);
    MyPair w=5;     // Converting constructor MyPair(intx)

    MyPair z1= x+5.3;
    MyPair z2 = 3+x;
    MyPair z3 = 3+x+5;

    w.print();
    z1.print();
    z2.print();
    z3.print();

    return 0;
}