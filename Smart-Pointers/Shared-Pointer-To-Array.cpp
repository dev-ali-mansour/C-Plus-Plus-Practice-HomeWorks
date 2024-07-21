#include <iostream>
#include <memory>

using namespace std;

void test() {
    unique_ptr<int> p1{new int[16]};    // OK

    // OK since C++ 17 but not C++ 14
    //shared_ptr<int> p2{new int[16]};

    // The workaround was customer deleter
    shared_ptr<int> p2{new int[16], [](int *i) {
        cout << "Let's force array deletion\n";
        delete[]i;
    }};
}