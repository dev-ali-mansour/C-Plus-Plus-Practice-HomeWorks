#include <iostream>

using namespace std;

class MyPair {
private:
    int first, second;
public:
    MyPair(int first_, int second_) : first(first_), second(second_) {}

    int operator[](int pos) const {
        if (pos == 0) return first;
        return second;
    }
};

int main() {
    MyPair x(10, 20);
    cout << x[0] << " " << x[1] << endl;    // 10 20

    // error: Lvalue required as left operand of assignment
    // x[0] = 7;
    // x[0]=> just a function that return temp var, e.g. g
    // So you are doing g=7 this has nothing with object x
    // We need g points in memory to first when [0]

    return 0;
}