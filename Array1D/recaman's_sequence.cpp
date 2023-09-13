#include <iostream>

using namespace std;

int main() {
    const int N = 201;
    int idx;
    cin >> idx;

    int sequence[200];
    sequence[0] = 0;
    int last_idx = 0;
    for (int i = 1; i <= idx; ++i) {
        int value = sequence[last_idx] - last_idx - 1;
        bool isInValid = false;
        for (int j = 0; j <= last_idx; ++j) {
            if (value < 0 || value == sequence[j]) isInValid = true;
        }
        if (!isInValid) {
            last_idx++;
            sequence[last_idx] = value;
        } else {
            value = sequence[last_idx] + last_idx + 1;
            last_idx++;
            sequence[last_idx] = value;
        }
    }

    cout << sequence[last_idx];

    return 0;
}