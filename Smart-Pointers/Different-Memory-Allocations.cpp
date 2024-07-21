#include <iostream>
#include <memory>
#include <functional>

using namespace std;

void deleter(int *p) {
    cout << "Special delete\n";
    delete p;
}

struct FunctorDeleter {
    void operator()(const int *p) { delete p; }
};

void test2() {
    auto l = [](int *p) { delete p; };
    cout << sizeof(unique_ptr<int>) << endl;    // default delete =  8
    cout << sizeof(unique_ptr<int, FunctorDeleter>) << endl;    // 8
    cout << sizeof(unique_ptr<int, decltype(&deleter)>) << endl;    // 16
    cout << sizeof(unique_ptr<int, decltype(l)>) << endl;    // 8
    cout << sizeof(unique_ptr<int, void (*)(int *)>) << endl;    // function pointer = 16
    cout << sizeof(unique_ptr<int, function<void(int *)>>) << endl;    // 40-64
}

int main() {
    test2();

    return 0;
}