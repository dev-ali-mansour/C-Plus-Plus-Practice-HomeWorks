#include <iostream>
#include <vector>

using namespace std;

class A {    // Must be virtual to cast
public:
    virtual ~A() {}
};

class B : public A {
};

class C : public A {
};

class D {
};

void dynamic_cast_test() {
    // Runtime conversion using RTTT
    A *a_from_b = new B();

    // No problem. valid conversion
    B *b = dynamic_cast<B *>(a_from_b);
    cout << b << endl;

    // wrong conversion, pointer = nullptr
    C *c = dynamic_cast<C *>(a_from_b);
    cout << c << endl;

    // Wrong conversion, pointer = nullptr
    D *d = dynamic_cast<D *>(a_from_b);
    cout << d << endl;

    delete a_from_b;
}

void static_cast_test() {
    // compile time check/cast
    A *a_from_b = new B();

    // No problem. valid conversion
    B *b = static_cast<B *>(a_from_b);
    cout << b << endl;

    // Wrong conversion, but u get pointer :(
    C *c = static_cast<C *>(a_from_b);
    cout << c << endl;

    // Compilation error can be caught for such clear case
    //D *d = static_cast<D *>(a_from_b);
}

int main() {
    dynamic_cast_test();
    static_cast_test();

    return 0;
}