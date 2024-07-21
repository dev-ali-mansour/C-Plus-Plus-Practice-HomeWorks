#include <iostream>
#include <memory>

using namespace std;

void deleter(int *p) {
    cout << "Custom Deleter\n";
    delete p;
}

void test() {
    shared_ptr<int> p1{new int{5}, deleter};
}

int main() {
    test();

    return 0;
}