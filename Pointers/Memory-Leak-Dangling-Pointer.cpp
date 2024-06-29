#include <iostream>

using namespace std;

struct Employee {
    int *xptr = nullptr;

    Employee() {
        xptr = new int[5]{1, 2, 3, 4, 5};
    }

    ~Employee() {   // Destructor
        cout << "Bye\n";
        delete[]xptr;
        xptr = nullptr;
    }

    void print() {
        cout << *xptr << " " << xptr << " " << &xptr << endl;
    }
};

int main() {
    Employee e1, e2;
    e1.xptr[0] = 20;

    // 20 0x19192b0 0x7ffd4d1590e8
    e1.print();
    // 1 0x19192d0 0x7ffd4d1590e0
    e2.print();

    e2 = e1;

    //20 0x19192b0 0x7ffd4d1590e0
    e2.print();
    // Crash!
    // e2 lost its xptr value of the created memory
    // the value of e1 copied

    // problem 1): memory leak as we lost e2 created memory
    // problem 2): e1 ptr will be deleted twice = dangling = crash

    Employee e3 = e1;   // same issue but more implicit

    return 0;
}