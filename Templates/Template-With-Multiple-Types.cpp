#include <iostream>

using namespace std;

template<class Type1, class Type2>
Type1 sum(Type1 a, Type2 b) {
    Type1 r = a + b;
    return r;
}

int main() {
    cout << sum(1, 10) << endl; // 11
    cout << sum(1, 10.5) << endl; // 11
    cout << sum(1.2, 10.5) << endl; // 11.7
    cout << sum(1.2, 10) << endl; // 11.2
    cout << sum<int, int>(1.2, 10) << endl; // 11
    cout << sum('A', 1) << endl; // B
    cout << sum(1, 'A') << endl; // 66
//    cout << sum("I am ", "Ali") << endl; // CE: Char*
    cout << sum(string("I am "), string("Ali")) << endl; // I am Ali

    return 0;
}