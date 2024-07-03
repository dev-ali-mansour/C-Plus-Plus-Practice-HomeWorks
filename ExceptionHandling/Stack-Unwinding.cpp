#include <iostream>

using namespace std;

struct Employee {
    int exp;

    Employee(int exp_) {
        exp = exp_;
    }
};

void f4() {
    cout << "Start f4\n";
    Employee *p = new Employee(4);
    throw 1;
    // Memory Leak
    delete p;   // Never execute
    cout << "End f4\n";
}

void f3() {
    cout << "Start f3\n";
    Employee p(3);
    f4();
    cout << "End f3\n";
}

void f2() {
    cout << "Start f2\n";
    try {
        f3();
    } catch (runtime_error &e) {
        // Won\t match - no effect
        cout << "runtime_error: " << e.what() << endl;
    }
    cout << "End f2\n";
}

void f1() {
    cout << "Start f1\n";
    try {
        f2();
    } catch (int &e) {  // match stop it here
        // Won\t match - no effect
        cout << "error_code: " << e << endl;
    }
    cout << "End f1\n";
}

int main() {
    f1();

    return 0;
}