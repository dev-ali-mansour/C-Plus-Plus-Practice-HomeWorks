#include <iostream>

using namespace std;

int main() {
    tuple<char, int, string> t1;
    t1 = make_tuple('c', 10, "Ali");

    // Get<position> c, 10
    cout << get<0>(t1) << " " << get<1>(t1) << endl;

    // Set<position>
    get<0>(t1) = 'd';

    cout << boolalpha; //print true as true
    cout << (t1 <= t1) << endl; // We can compare tuples

    char ch;
    int val;
    string name;

    // Tie unpack the tuple values into separate values
    tie(ch, val, name) = t1;
    cout << ch << " " << val << " " << name << endl;

    // Concatenate 2 tuples to return a new tuple
    auto t2 = tuple_cat(t1, make_tuple(10.6));

    // C++17 some nicer code. Don't try unless C++17 compilation
    auto [c, d] = make_tuple(4.5, 5);
    cout << c << " " << d << endl;

    return 0;
}