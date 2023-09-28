#include <iostream>

using namespace std;

void set_powers(int arr[], int len = 5, int m = 2) {
    for (int i = 0; i < len; ++i) {
        int value = 1;
        for (int j = 0; j < i; ++j) {
            value *= m;
        }
        arr[i] = value;
    }
}

int main() {
    int arr[100];
    int len, m;
    cin >> len >> m;

    set_powers(arr, len, m);

    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}