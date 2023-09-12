#include <iostream>

using namespace std;

int main() {
    /*int N;
    cin >> N;
    int numbers[N];

    for (int i = 0; i < N; ++i) {
        int value;
        cin >> numbers[i];

    }

    for (int i = 0; i < N; ++i) {
        if (numbers[i] != numbers[i - 1])
            cout << numbers[i] << " ";
    }*/

    int N;
    cin >> N;

    int last_value = INT32_MIN;

    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        if (value != last_value) {
            cout << value << " ";
            last_value = value;
        }
    }

    return 0;
}