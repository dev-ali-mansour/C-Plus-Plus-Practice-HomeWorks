#include <iostream>

using namespace std;

int main() {
    int R;
    cin >> R;
    int number = 0;
    while (R > 0) {
        int last_digits = R % 10;
        R /= 10;
        number = number * 10 + last_digits;
    }
    cout << number << " " << number * 3;

    return 0;
}