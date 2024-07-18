#include <iostream>
#include <vector>

using namespace std;

class Base {
public:
};

class B : public Base {
private:
    int *val;

public:
    ~B() {
        delete val;
        val = nullptr;
    }

    B(int x) : val(new int) {
        *val = x;
    }

    B(const B &another) : val(new int) {
        *val = *another.val;      // Copy constructor
    }

    B &operator=(const B &another) {
        if (this == &another)
            return *this;   // Handle self assignment

        Base::operator=(another);   // Assign @ parent

        // Do ramin of your assignment
        *val = *another.val;
        return *this;
    }

    // Force no assignment operator
//    B &operator=(const B &another)=delete;
};

int main() {
    B b1(10);
    B b2 = b1;        // Copy
    b2 = b1;          // Assign

    return 0;
}

