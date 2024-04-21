#include <iostream>

using namespace std;

int absolute(int a) ;
int max_abs(int a, int b);

int main() {
    cout << max_abs(2, 5) << endl;
    cout << max_abs(2, -5) << endl;

    return 0;
}

int absolute(int a) {
    if (a >= 0)
        return a;
    return -a;
}

int max_abs(int a, int b) {
    a = absolute(a);
    b = absolute(b);

    if (a > b)
        return a;
    return b;
}