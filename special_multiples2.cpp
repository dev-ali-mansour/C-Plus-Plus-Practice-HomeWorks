#include <iostream>

using namespace std;

int main() {
    int N, current_number = 0, count = 0;
    cin >> N;
    if (N > 0 && N <= 30) {
        while (count < N) {
            if (current_number % 3 == 0 && current_number % 4 != 0) {
                cout << current_number << " ";
                count++;
            }
            current_number++;
        }
    }

    return 0;
}