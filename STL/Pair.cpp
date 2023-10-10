#include <iostream>
#include <stack>

using namespace std;

int main() {
    pair<int, string> p = make_pair(10, "Ali");
    cout << p.first << " " << p.second << endl;

    stack<pair<int, string>> s;
    s.push(p);
    s.push(p);

    pair<int, pair<int, string >> my_p = make_pair(10, make_pair(20, "Ahmed"));
    my_p = make_pair(15, p);
    cout << my_p.first << " " << my_p.second.first << " " << my_p.second.second << endl;

    return 0;
}