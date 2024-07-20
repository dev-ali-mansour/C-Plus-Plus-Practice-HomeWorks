#include <iostream>
#include <memory>

using namespace std;

struct Employee {
    unique_ptr<int> &id;
    string name;

    Employee(unique_ptr<int> &id_, string name_) : id(id_), name(name_) {}

    void print() {
        cout << "Employee id " << *id << endl;
    }
};

int main() {
    unique_ptr<int> p1{new int{20}};
    unique_ptr<int> p2 = make_unique<int>(20);
    auto p3 = make_unique<int>(20);

    unique_ptr<Employee> most{new Employee(p1, "Mostufa")};

    auto emp = make_unique<Employee>(p1, "Belal");

    emp->print();   // Employee id 20
    emp.get();      // Notice . not ->

    return 0;
}