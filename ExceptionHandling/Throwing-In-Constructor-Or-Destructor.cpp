#include <iostream>

using namespace std;

struct Name {
    string first;

    Name() {}

    Name(string first_) { first = first_; }

    ~Name() { cout << "Name Destructor " << first << endl; }
};

struct Employee {
    Name *full_name1{};
    Name full_name2;

    Employee() {
        full_name1 = new Name("Ali");
        throw 0;    // Memory Leak
        full_name2.first = "Yamen";
    }

    ~Employee() {   // never called
        delete full_name1;
        cout << "Destroy Employee \n";
    }
};

int main() {
    try {
        Employee();
    } catch (...) {}

    return 0;
}