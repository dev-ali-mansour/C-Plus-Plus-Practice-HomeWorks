#include <iostream>

using namespace std;

int main() {
    string input, str;
    cin >> input >> str;

    if (str.size() > input.size()) {
        cout << "NO\n";
        return 0;
    }

    // Get the index of the first char of small string (str) in the large string (input)
    int first_index = -1;
    for (int i = 0; i < (int) input.size(); ++i) {
        if (input[i] == str[0]) {
            first_index = i;
            break;
        }
    }

    if (first_index == -1) {
        cout << "NO\n";
        return 0;
    }

    //Start from the first index with the size of the small string and check characters
    for (int i = 0; i < (int) str.size(); ++i) {
        if (str[i] != input[first_index + i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}