#include <iostream>

using namespace std;

int main() {
    string input, str;
    cin >> input >> str;

    if (str.size() > input.size()) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < str.size(); ++i) {
        if (input[i] != str[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}