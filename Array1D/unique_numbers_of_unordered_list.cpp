#include <iostream>
#include <cassert>

using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAX = 900 + 1;
    int existed[MAX] = {0};

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        assert(0 <= value && value <= 500);

        if (!existed[value]) {
            existed[value] = 1;
            cout << value << " ";
        }
    }

    return 0;
}