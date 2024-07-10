#include <iostream>

using namespace std;

class Person {
public:
    void print() { cout << "Person\n"; }

    ~Person() { cout << "~Person\n"; }
};

class Student : public Person {
public:
    void print() { cout << "Student\n"; }

    ~Student() { cout << "~Student\n"; }
};

int main() {
    Person person;
    Student student;

    person.print();
    student.print();

    Person *per_ptr = &person;
    Student *std_ptr1 = &student;
    Person *std_ptr2 = &student;
    Person *std_ptr3 = new Student();

    per_ptr->print();
    std_ptr1->print();
    std_ptr2->print();  // Call Person not Student
    std_ptr3->print();  // Call Person not Student

    delete std_ptr3;    // Memory Leak

    return 0;
}