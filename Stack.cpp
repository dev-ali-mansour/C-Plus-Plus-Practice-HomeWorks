#include <iostream>
#include <stack>

using namespace std;

void print(stack<string> &s) {
    cout << "Stack elements: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<string> s;
    s.push("Mohamed");
    s.push("Mansour");
    s.push("Ali");

    print(s);

    return 0;
}