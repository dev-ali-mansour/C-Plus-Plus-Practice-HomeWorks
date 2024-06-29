#include <iostream>

using namespace std;

bool starts_with(const string &input, const string &pattern, int pos);
string replace_str(const string &input, const string &pattern, const string &to);

int main() {
    cout << starts_with("aabcabaaad", "aa", 0) << endl;
    cout << starts_with("aabcabaaad", "aa", 1) << endl;
    cout << starts_with("aabcabaaad", "aabcabaaad", 0) << endl;
    cout << starts_with("aabcabaaad", "baaad", 5) << endl;
    cout << starts_with("aabcabaaad", "baaad", 4) << endl;

    cout << replace_str("aabcabaaad", "aa", "x") << endl;
    cout << replace_str("aabcabaaad", "aa", "aaaa") << endl;
    cout << replace_str("aabcabaaad", "aa", "") << endl;
    return 0;
}

bool starts_with(const string &input, const string &pattern, int pos) {
    if (pos + pattern.size() > input.size())
        return false;

    for (int i = 0; i < (int) pattern.size(); ++i) {
        if (pattern[i] != input[i + pos])
            return false;
    }
    return true;
}

string replace_str(const string &input, const string &pattern, const string &to) {
    string res;
    for (int pos = 0; pos < (int) input.size(); ++pos) {
        if (starts_with(input, pattern, pos)) {
            res += to;
            pos += (int) pattern.size() - 1; // Move to the next right position
        } else
            res += input[pos];
    }
    return res;
}