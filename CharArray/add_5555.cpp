#include <iostream>

using namespace std;

int main() {
    string num;
    cin >> num;

    int sz = num.size();

    int carry = 0;
    for (int i = 0; i < sz; ++i) {
        int digit = num[sz - 1 - i] - '0';

        if (i < 4) digit += 5;  // Add 5 to first 4 items
        digit += carry;         // Add any carry

        if (digit >= 10) {
            digit -= 10;
            carry = 1;
        } else carry = 0;

        num[sz - 1 - i] = digit + '0';
    }

    if (carry) cout << 1;
    cout << num;

    return 0;
}