#include <iostream>

using namespace std;

class Person {
public:
    virtual void print() { cout << "Person\n"; }

    virtual ~Person() { cout << "~Person\n"; }
};

class Student : public Person {
public:
    void print() { cout << "Student\n"; }

    ~Student() { cout << "~Student\n"; }
};

int main() {
    Person *std_ptr3 = new Student();
    std_ptr3->print();
    std_ptr3->Person::print();  // Explicit
    delete std_ptr3;

    return 0;
}