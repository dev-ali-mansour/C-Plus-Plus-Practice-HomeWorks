#include <iostream>

using namespace std;

int main() {
    const int N = 201;
    int idx, sequence[N];
    int occurrence[N * 10] = {0};

    cin >> idx;

    sequence[0] = 0;
    occurrence[0] = 1;

    for (int i = 1; i <= idx; ++i) {
        int value = sequence[i - 1] - (i - 1) - 1;
        if (value < 0 || occurrence[value])
            value = sequence[i - 1] + (i - 1) + 1;

        sequence[i] = value;
        occurrence[value] = 1;
    }

    cout << sequence[idx];

    return 0;
}