#include <iostream>

using namespace std;

int my_pow(int value, int power = 2) {
    if (power == 0)
        return 1;
    return value * my_pow(value, power - 1);
}

int main() {
    cout << my_pow(7) << endl;
    cout << my_pow(7, 0) << endl;
    cout << my_pow(7, 3) << endl;
    return 0;
}