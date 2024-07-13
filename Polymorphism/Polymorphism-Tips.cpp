#include <iostream>
#include <vector>

using namespace std;

class A {
public:
    virtual void f1(int x = 1) {
        cout << x << " in A\n";
    }

    virtual ~A() {
    }
};

class B : public A {
public:
    // f1 will be called with A::f1 default params!
    virtual void f1(int x = 2) override {
        cout << x << " in B\n";
    }
};

int main() {
    A *a = new B();
    a->f1();    // 1 in B

    delete a;
    a = nullptr;

    return 0;
}

// If overriding a method, Use override keyword. So the compiler verifies in base class
// virtual function==> Provide virtual destructor to avoid memory leak
// If a fuction is virtual from base class, always mark it as virtual derived.