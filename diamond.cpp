#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int row = 1;
    while (row <= N) {
        int stars_count = 1;
        while ((stars_count <= N - row)) {
            cout << ' ';
            ++stars_count;
        }
        stars_count = 1;
        while (stars_count <= 2 * row-1) {
            cout << '*';
            ++stars_count;
        }
        cout << endl;
        ++row;
    }
    row = N;
    while (row >= 1) {
        int stars_count = 1;
        while (stars_count <= N - row) {
            cout << ' ';
            ++stars_count;
        }
        stars_count = 1;
        while (stars_count <= 2 * row - 1) {
            cout << '*';
            ++stars_count;
        }
        cout << endl;
        --row;
    }

    return 0;
}