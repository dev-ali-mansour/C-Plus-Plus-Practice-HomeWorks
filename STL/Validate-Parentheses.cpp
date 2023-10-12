#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

bool is_valid(string str) {
    map<char, char> mp; // mp the close of each
    mp[')'] = '(';
    mp[']'] = '[';
    mp['}'] = '{';

    stack<char> parentheses;

    for (auto ch: str) {
        if (mp.count(ch)) {
            // A close one. It must match open one
            if (parentheses.empty())
                return false;

            char open = mp[ch];
            char cur_open = parentheses.top();

            if (open != cur_open)
                return false;
            parentheses.pop();
        } else
            parentheses.push(ch);   // This is open parentheses
    }
    return parentheses.empty();
}


int main() {
    cout << boolalpha;
    string arr[]{"()", "()()", "(()())", "{}{}", "(((())))", "([])",
                 "()[]{}", "{[]}", "(]", "())", "(][)", "(]", "([)]"};
    for (auto &str: arr) {
        cout << str << "->" << is_valid(str) << endl;
    }
}