#include <iostream>

using namespace std;

class MyPair {
private:
    int first, second;
public:
    MyPair(int first_, int second_) : first(first_), second(second_) {}

    MyPair operator!() {
        cout << "Here\n";
        MyPair &c1 = *this;
        return MyPair(-1 * first, -1 * second);
    }

    void print() {
        cout << "(" << first << "," << second << ")\n";
    }
};

int main() {
    MyPair x(1, 2);
    x = !x;
    x.print();  // (-1,-2)
}