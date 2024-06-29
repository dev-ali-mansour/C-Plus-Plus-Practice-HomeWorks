#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int *p0 = &x;
    int *p1{nullptr};

    int *p2 = new int;    // Dynamic Allocation
    *p2 = 20;             // Set value

    //  20 0x47d2b0 0x7fff429066c8
    cout << *p2 << " " << p2 << " " << &p2 << endl;

    int *p3 = new int{30}; // C++11 brace initialization syntax
    //int  *p3 = new int(30); // initializer

    // p0 points to x. never delete
    // p1 nullptr. never delete

    cout << *p2 << " " << *p3 << endl;

    // We created these 2 dynamically. Delete them
    delete p2;
    delete p3;
    p2 = p3 = nullptr;

    return 0;
}