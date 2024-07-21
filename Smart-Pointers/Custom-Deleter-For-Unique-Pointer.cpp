#include <iostream>
#include <functional>
#include <memory>

using namespace std;

int sq(int x) {
    return x * x;
}

void test1() {
    // Function that takes int and returns int
    function<int(int)> f = sq;
    cout << f(5) << endl;
}

void deleter(int *p) {
    cout << "Special delete\n";
    delete p;
}

void test2() {
    unique_ptr<int, function<void(int *)>> p2{new int{5}, deleter};

    // function<void(int*)>
    // Expect a function
    // Return type void
    // Parameter: int *
}

int main() {
    test1();
    test2();

    return 0;
}