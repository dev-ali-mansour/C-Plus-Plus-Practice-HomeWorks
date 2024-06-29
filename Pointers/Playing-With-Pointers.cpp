#include <iostream>

using namespace std;

int main() {
    int val1 = 5, val2 = 15;
    // 0xc8b33ffe54 0xc8b33ffe50
    cout << &val1 << " " << &val2 << endl;
    int *p1 = &val1, *p2;
    p2 = &val2;

    // [Value pointed by p1 = val1] = 10
    *p1 = 10;

    // [Value pointed by p2 = val2] = [Value pointed by p1 + 6 = 16]
    *p2 = *p1 + 6;
    cout << val1 << " " << val2 << endl;    // 10 16

    p1 = p2;  // let p1 points where p2 points = &val2
    // 0xc8b33ffe50 0xc8b33ffe50
    cout << p1 << " " << p2 << endl;

    *p1 = 20; // Value pointed to by p1 = 20
    // 10 20
    cout << val1 << " " << val2 << endl;
    // 20 20
    cout << *p1 << " " << *p2 << endl;

    p1 = &val1;
    // 10 20
    cout << *p1 << " " << *p2 << endl;
    swap(p1, p2);
    // 20 10
    cout << *p1 << " " << *p2 << endl;

    double x = 10;
    // p1 = &x;    //CE: can not convert double* to int*

    return 0;
}