#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;
    if (number <= 1) cout << "NO";
    else {
        bool is_prime = true;

        for (int i = 2; i <= number / 2; ++i) {
            if ((number % i) == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            cout << "YES";
        else cout << "NO";
    }
    return 0;
}