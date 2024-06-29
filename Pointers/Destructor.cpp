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
    Employee e;
    e.print();
    // 1 0x4582b0 0x7ffdeef0b568
    // Bye

    return 0;
}