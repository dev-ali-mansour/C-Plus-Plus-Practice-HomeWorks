#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int numbers[N];

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < N; ++i) {
        if (numbers[i] != numbers[i - 1])
            cout << numbers[i] << " ";
    }

    return 0;
}