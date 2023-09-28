#include <iostream>

using namespace std;

string revers_string(const string &str) {
    string reversed;
    for (int i = (int) str.size() - 1; i >= 0; --i) {
        reversed += str[i];
    }
    return reversed;
}

int main() {
    cout << revers_string("") << endl;
    cout << revers_string("abcd") << endl;
    cout << revers_string("abcde") << endl;

    return 0;
}
