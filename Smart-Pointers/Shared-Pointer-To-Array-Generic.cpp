#include <iostream>
#include <memory>

using namespace std;

template<typename T>
void deleter(T *p) {
    cout << "Let's force array deletion 1\n";
    delete p;
}

template<typename T>
struct ArrayDeleter {
    void operator()(T const *p) {
        cout << "Let's force array deletion 2\n";
        delete[]p;
    }
};

void test() {
    shared_ptr<int> p1{new int[16], deleter<int>};

    shared_ptr<int> p2{new int[16], ArrayDeleter<int>()};
}

int main() {
    test();

    return 0;
}