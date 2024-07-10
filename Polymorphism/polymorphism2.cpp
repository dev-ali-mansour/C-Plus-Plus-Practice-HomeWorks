#include <iostream>

using namespace std;

class A {
public:
    virtual void f1() { cout << "A::f1\n"; }    // Virtual
    void f2() { cout << "A::f2\n"; }

    void f3() { cout << "A::f3\n"; }
};

class B : public A {
public:
    void f1() { cout << "B::f1\n"; }            // Virtual
    virtual void f2() { cout << "B::f2\n"; }    // Virtual
    void f3() { cout << "B::f3\n"; }
};

class C : public B {
public:
    void f1() { cout << "C::f1\n"; }            // Virtual
    void f2() { cout << "C::f2\n"; }            // Virtual
    virtual void f3() { cout << "C::f3\n"; }    // Virtual
};

class D : public C {
public:
    void f1() { cout << "D::f1\n"; }    // Virtual
    void f2() { cout << "D::f2\n"; }    // Virtual
    void f3() { cout << "D::f3\n"; }    // Virtual
};

int main() {
    B *d1 = new D();
    d1->f1();
    d1->f2();
    d1->f3();
    cout << endl;

    A *d2 = new D();
    d2->f1();
    d2->f2();
    d2->f3();

    delete d1;
    delete d2;

    return 0;
}