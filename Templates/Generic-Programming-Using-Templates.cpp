#include <iostream>

using namespace std;

template<typename Type>
Type myMax(Type a, Type b) {
    if (a > b)
        return a;
    return b;
}

struct Employee {
};

int main() {
    cout << myMax(2, 5) << endl; // 5: Guessed as int
    cout << myMax<int>(2, 5) << endl; // 5
    cout << myMax<double>(2.5, 5.4) << endl; // 5.4
    cout << myMax('A', 'X') << endl; // X

//    cout << myMax(2, 5.4) << endl; // CE: Can't guess
    cout << myMax<int>(2, 5.4) << endl; // 5
    cout << myMax<double>(2, 5.4) << endl; // 5.4

    Employee a,b;
//    cout << myMax(a,b) << endl; // CE: Can't compare

    return 0;
}