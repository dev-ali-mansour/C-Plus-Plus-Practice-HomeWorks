#include <iostream>

using namespace std;

struct Employee {
    int *xptr = nullptr;

    Employee() {
        xptr = new int[5]{1, 2, 3, 4, 5};
    }

    void print() {
        cout << *xptr << " " << xptr << " " << &xptr << endl;
    }
};

int main() {
    int *x = new int{10};
    delete x;
    // I created and deleted

    // But this struct creates internally who deletes!
    Employee e;     // Memory Leak
    e.print();

    return 0;
}