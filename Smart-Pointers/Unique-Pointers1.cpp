#include <memory>   // Smart Pointers
#include <iostream>

using namespace std;

void test() {
    unique_ptr<int> p1{new int{20}};    // Direct initialization

    // CE: Conversion from int* to unique_ptr
    // Internally explicit constructor
    // unique_ptr<int> p1 = new int{20};

    cout << *p1 << endl;
    *p1 = 50;

    // CE: Using of deleted operator
    // p1 = new int{30};    Similarly can't just assign
    p1.reset(new int{30});  // Delete the old one and create a new one
    cout << *p1 << endl;

    // Once we go out of scope
    // p1 internals are destroyed

}

int main() {

}