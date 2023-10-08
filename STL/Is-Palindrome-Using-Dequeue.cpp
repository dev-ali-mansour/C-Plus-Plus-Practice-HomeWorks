#include <iostream>
#include <queue>

using namespace std;

bool is_palindrome(string str = "abba") {
    deque<char> dq;
    for (char c: str) { // Add chars
        dq.push_back(c);
    }

    while (dq.size() > 1) {
        char f = dq.front();
        dq.pop_front();
        char b = dq.back();
        dq.pop_back();

        if (f != b)
            return false;
    }
    return true;
}

int main() {
    cout << boolalpha; //print true as true
    cout << is_palindrome("abba") << endl;  // true
    cout << is_palindrome("abcba") << endl; // true
    cout << is_palindrome("xyy") << endl;   // false

    return 0;
}