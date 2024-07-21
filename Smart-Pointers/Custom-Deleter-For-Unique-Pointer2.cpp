#include <iostream>
#include <functional>
#include <memory>

using namespace std;

void deleter(int *p) {
    cout << "Special delete\n";
    delete p;
}

void test2() {
    unique_ptr<int, decltype(&deleter)> p2{new int{5}, deleter};
}

int main() {
    test2();

    return 0;
}