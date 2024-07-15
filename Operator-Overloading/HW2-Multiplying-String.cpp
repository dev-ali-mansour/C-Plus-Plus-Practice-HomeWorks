#include <iostream>

using namespace std;

string operator*(const string &str, int count) {
    string res;
    for (int i = 0; i < count; ++i)
        res += str;
    return res;
}

int main() {
    string a = "bad";
    string b = "I am " + a * 3 + ", right?";

    cout << b;    // I am badbadbad, right?
}