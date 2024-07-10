#include <iostream>

using namespace std;

class A {
public:
    int getValue() {
        return 10;
    }

    string getString() {
        return "Hello";
    }
};

class B : public A {
public:
    int getValue() {
        return 20;
    }
};

int main() {
    B b1;
    cout << b1.getValue() << " " << b1.getString() << endl;     // 20 Hello

    B *b2 = new B();
    cout << b2->getValue() << " " << b2->getString() << endl;   // 20 Hello

    delete b2;

    return 0;
}