#include <iostream>

using namespace std;

int main() {
    int target;
    cin >> target;
    bool is_first = true;
    for (int number = 2; number <= target; ++number) {
        bool is_prime = true;
        for (int j = 2; j < number; ++j) {
            if ((number % j) == 0) is_prime = false;
        }
        if (is_prime) {
            if (!is_first)cout << ",";
            cout << number;
            is_first = false;
        }
    }
}