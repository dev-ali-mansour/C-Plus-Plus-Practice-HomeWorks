#include <iostream>

using namespace std;

int main() {
    string input, str;
    cin >> input >> str;

    if (str.size() > input.size()) {
        cout << "NO\n";
        return 0;
    }

    int start = input.size() - str.size();
    for (int i = 0; i < (int) str.size(); ++i) {
        if (str[i] != input[i + start]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}