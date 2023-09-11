#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int numbers[N];
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    int min = 10000, max = -1;
    for (int i = 0; i < N; ++i) {
        if (min > numbers[i]) min = numbers[i];
        if (max < numbers[i]) max = numbers[i];
    }

    for (int i = 0; i < N; ++i) {
        if (numbers[i] == min)numbers[i] = max;
        else if (numbers[i] == max)numbers[i] = min;
    }

    for (int i = 0; i < N; ++i) {
        cout << numbers[i] << " ";

    }

    return 0;
}