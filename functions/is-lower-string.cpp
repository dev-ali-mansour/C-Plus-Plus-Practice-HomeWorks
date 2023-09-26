#include <iostream>

using namespace std;

bool is_lower(const string &str) {
    for (int i = 0; i < (int) str.size(); ++i) {
        if (!islower(str[i]))
            return false;
    }
    return true;
}

int main() {
    cout << is_lower("abc") << endl;
    cout << is_lower("aBc") << endl;

    return 0;
}