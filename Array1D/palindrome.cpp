#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int numbers[n];
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < n / 2; ++i) {
        if (numbers[i] != numbers[n - 1 - i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}