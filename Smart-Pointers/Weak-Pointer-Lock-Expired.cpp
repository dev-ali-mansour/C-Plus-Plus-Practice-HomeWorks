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
    //department->employees;    //CE: '->' has non-pointer type

    // Make sure the original is not removed
    if (!department.expired()) {
        shared_ptr<Department> dep_orig = department.lock();
        cout << "Emp count " << dep_orig->employees.size() << endl;
    } else cout << "Expired!";
}

int main() {
    shared_ptr<Employee> e = make_shared<Employee>();
    shared_ptr<Department> d = make_shared<Department>();
    d->employees.push_back(e);
    e->department = d;
    e->print();     // Emp count 1
    d.reset();
    e->print();     // Expired

    return 0;
}