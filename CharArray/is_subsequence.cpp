#include <iostream>

using namespace std;

int main() {
    string input, str;
    cin >> input >> str;

    if (str.size() > input.size()) {
        cout << "NO\n";
        return 0;
    }

    // Keep matching letters in order from the big string in the small one
    int next_to_match = 0;
    for (int i = 0; i < (int) input.size(); ++i) {
        if (input[i] == str[next_to_match]) {
            ++next_to_match;
            if (next_to_match == str.size()) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}