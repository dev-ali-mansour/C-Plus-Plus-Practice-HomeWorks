#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Department;

struct Employee {
    weak_ptr<Department> department;

    void print();   // You can't define. Incomplete
};

struct Department {
    vector<shared_ptr<Employee>> employees;
};

void Employee::print() {
    if (department.expired())
        return;
    if (auto dep_orig = department.lock())
        cout << "Emp count " << dep_orig->employees.size() << endl;
}

int main() {
    shared_ptr<Employee> e = make_shared<Employee>();
    shared_ptr<Department> d = make_shared<Department>();
    d->employees.push_back(e);
    e->department = d;
    e->print();     // Emp count 1
    d.reset();
    e->print();

    return 0;
}