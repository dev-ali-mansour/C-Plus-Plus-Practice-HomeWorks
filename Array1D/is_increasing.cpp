#include <iostream>

using namespace std;

int main() {
    int N, numbers[N];
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    bool is_increasing = true;
    for (int i = 1; i < N; ++i) {
        if (numbers[i] < numbers[i - 1]) {
            is_increasing = false;
            break;
        }
    }

    if (is_increasing) cout << "YES";
    else cout << "NO";

    return 0;
}