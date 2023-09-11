#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int numbers[N];
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    int min_idx = 0, max_idx = 0;
    for (int i = 0; i < N; ++i) {
        if (numbers[min_idx] > numbers[i]) min_idx = i;
        if (numbers[max_idx] < numbers[i]) max_idx = i;
    }

    int min = numbers[min_idx], max = numbers[max_idx];

    for (int i = 0; i < N; ++i) {
        if (numbers[i] == min)numbers[i] = max;
        else if (numbers[i] == max)numbers[i] = min;
    }

    for (int i = 0; i < N; ++i) {
        cout << numbers[i] << " ";

    }

    return 0;
}