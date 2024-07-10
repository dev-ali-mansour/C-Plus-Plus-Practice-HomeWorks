#include <iostream>

using namespace std;

class A {
public:
    int x;
protected:
    int y;
private:
    // Always invisible from outsiders
    int z;
};

class B : public A {
    // x is public and y is protected
};

class C : protected A {
    // Both x, and y are protected
};

class D : private A {
    // Now invisible from outsiders
    // Both x, and y are private
};

class E : public D {
public:
    void func() {
//    x=0;  // Invisible here
    }
};

int main(){
    A a;
    a.x=1;  // Can't access y or z

    B b;
    a.x=1;  // Can't access y or z

    C c;
    return 0;
}