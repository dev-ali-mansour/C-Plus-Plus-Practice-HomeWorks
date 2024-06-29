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

    // For now: Add these 2 lines when you have internal pointers
    // They will inform you about soon problems
    // Later in OOP: Full understanding and proper treatment
    Employee(const Employee &e) = delete;

    void operator=(const Employee &e) = delete;
};

int main() {
    Employee e1, e2;

    // Now CE = saves us from our mistakes
    e2 = e1;
    Employee e3 = e1;

    return 0;
}