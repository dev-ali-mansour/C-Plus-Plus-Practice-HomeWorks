#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int numbers[n];
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int small1 = INT32_MAX, small2 = INT32_MAX, small3 = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        if (numbers[i] < small1) {
            small3=small2;
            small2 = small1;
            small1 = numbers[i];
        } else if (numbers[i] < small2) {
            small3 = small2;
            small2 = numbers[i];
        } else if (numbers[i] < small3) {
            small3 = numbers[i];
        }
    }

    cout << small1 << " " << small2 << " " << small3;

    return 0;
}