#include <iostream>

using namespace std;

int main() {
    int n, x, occurrence[10] = {0};
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == 0)
            occurrence[0]++;
        while (x) {
            int digit = x % 10;
            occurrence[digit]++;
            x /= 10;
        }
    }

    for (int i = 0; i <= 9; ++i) {
        cout << i << " " << occurrence[i] << endl;
    }

    return 0;
}