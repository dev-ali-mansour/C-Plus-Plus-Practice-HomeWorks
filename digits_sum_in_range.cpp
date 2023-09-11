#include <iostream>

using namespace std;

int main() {
    int n, a, b, total = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        int tmp = i, digits_sum = 0;
        while (tmp) {
            digits_sum += tmp % 10;
            tmp /= 10;
        }
        if (digits_sum >= a && digits_sum <= b)total += i;
    }

    cout << total << "\n";

    return 0;
}