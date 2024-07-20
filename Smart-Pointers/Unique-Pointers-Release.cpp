#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void test() {
    auto p1 = make_unique<int>(20);

    // Return the pointer and set nullptr
    int *p = p1.release();

    if (p1 == nullptr)
        cout << "p1 gone\n";

    // The only case when you have to remove p
    cout << *p << endl;
    delete p;
    p = nullptr;

    // Don't use release unless a good reason
}

void warning() {
    int *p = new int{30};
    // You can assign the same pointer to more than unique_ptr :(
    // Dangling Pointer
    unique_ptr<int> p1{p};
    unique_ptr<int> p2{p};

    // RTE once we go out of scope
    // Tip: Don't assign raw pointers in this way
}

int main() {
    warning();
    cout << "bye\n";
    return 0;
}