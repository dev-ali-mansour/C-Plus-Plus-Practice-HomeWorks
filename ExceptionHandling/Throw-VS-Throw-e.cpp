#include <iostream>

using namespace std;


void f3() {
    throw runtime_error("A run time error");
}

void f2() {
    try {
        f3();
    } catch (runtime_error &e) {
        cout << &e << endl;
//        throw e;    // Create a copy
        throw;
    }
}

void f1() {
    try {
        f2();
    } catch (runtime_error &e) {
        cout << &e << endl;
//        throw e;    // Create a copy
        throw;
    }
}

int main() {
    try {
        f1();
    } catch (runtime_error &e) {
        cout << &e << endl;
    }
    return 0;
}