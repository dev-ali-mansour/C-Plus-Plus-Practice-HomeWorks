#include <iostream>

using namespace std;

void hello(int &x) {
    cout << "hello " << x << endl;
}

int main() {
    int x = 1;
    int *p = &x;
    int &y1 = x;

    // int& needs a variable on the right side
    int &y2 = *p;

    hello(x);
    hello(y2);
    hello(*p);

    return 0;
}