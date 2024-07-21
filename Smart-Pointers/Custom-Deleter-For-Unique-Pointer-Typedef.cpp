#include <iostream>
#include <functional>
#include <memory>

using namespace std;

// Define global not local
// Generalization of typedef, allowing templates
template<typename T>
using deleted_unique_ptr = unique_ptr<T, function<void(T *)>>;

template<typename T>
void deleter2(T *p) {
    cout << "Special Delete\n";
    delete p;
}

void deleter1(int *p) {
    cout << "Special delete\n";
    delete p;
}

typedef unique_ptr<int, function<void(int *)>> deleted_unique_ptr_int;

void test2() {
    unique_ptr<int, function<void(int *)>> p1{new int{5}, deleter1};

    deleted_unique_ptr_int p2{new int{5}, deleter1};

    deleted_unique_ptr<int> p3{new int{5}, deleter2<int>};

    deleted_unique_ptr<double> p4{new double{5}, deleter2<double>};
}

int main() {
    test2();

    return 0;
}