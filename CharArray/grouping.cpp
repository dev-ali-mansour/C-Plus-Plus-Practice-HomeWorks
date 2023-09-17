#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;

    for (int i = 0; i < input.size(); ++i) {
        if (i > 0 && input[i] != input[i - 1]) // New group, split with a space
            cout << " ";
        cout << input[i];
    }

    return 0;
}