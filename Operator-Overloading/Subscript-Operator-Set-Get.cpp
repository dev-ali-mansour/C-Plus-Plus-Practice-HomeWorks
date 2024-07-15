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

    int &operator[](int pos) {
        if (pos == 0) return first;
        return second;
    }
};

int main() {
    MyPair x(10, 20);
    cout << x[0] << " " << x[1] << endl;    // 10 20

    x[0] = 7;
    cout << x[0] << " " << x[1] << endl;    // 7 20

    return 0;
}