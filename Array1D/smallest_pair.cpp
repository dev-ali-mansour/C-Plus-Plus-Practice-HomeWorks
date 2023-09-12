#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int min_result = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int value = a[i] + a[j] + j - i;
            if (value < min_result)
                min_result = value;
        }
    }

    cout << min_result;

    return 0;
}