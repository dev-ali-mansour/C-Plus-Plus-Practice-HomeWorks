#include <iostream>

using namespace std;

template<class T>
T add(T a, T b) {
    return a + b;
}

template<class T>
T multiply(T a, int factor) {
    return a * factor;
}

template<>
string multiply(string str, int factor) {
    // We can't multiply strings
    string res;
    while (factor--) {
        res += str;
    }
    return res;
}

int main() {
    string s = "Magic";
    cout << add(10, 4) << endl;  // 14
    cout << add(s, s) << endl;  // MagicMagic

    cout << multiply(10, 4) << endl;  // 40
    cout << multiply(s, 4) << endl;  // MagicMagicMagicMagic

    return 0;
}