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

int main() {
    MyPair x(1, 2);
    MyPair y(10, 20);

    MyPair z = x + y;
    z.print();  // (11,22)

    return 0;
}