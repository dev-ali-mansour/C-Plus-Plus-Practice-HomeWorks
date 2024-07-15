#include <iostream>

using namespace std;

class MyPair {
private:
    int first, second;
public:
    MyPair(int first_, int second_) : first(first_), second(second_) {}

    MyPair Add(const MyPair &c2) {
        MyPair &c1 = *this;
        return MyPair(c1.first + c2.first, c1.second + c2.second);
    }

    MyPair operator+(const MyPair &c2) {
        MyPair &c1 = *this;
        return MyPair(c1.first + c2.first, c1.second + c2.second);
    }

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

int main() {
    MyPair x(1, 2);
    MyPair y(10, 20);

    MyPair z = x.Add(y);
    z.print();  // (11,22)
    MyPair s = x + y;
    s.print();  // (11,22)

    return 0;
}