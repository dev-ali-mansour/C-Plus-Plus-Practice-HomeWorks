#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Department;

struct Employee {
    weak_ptr<Department> department;
};

struct Department {
    // Logic: Department is the actual owner
    vector<shared_ptr<Employee>> employees;

    ~Department() { cout << "Destroy Department\n"; }
};


int main() {
    shared_ptr<Employee> e = make_shared<Employee>();

    // 1) Created shared.  2) Then assign/construct to a weak pointer
    shared_ptr<Department> d = make_shared<Department>();
    e->department = d;      // Assign shared to weak
    //e->department=weak_ptr<Department>(d);      // or

    d->employees.push_back(e);

    // Weak from weak
    weak_ptr<Department> d2 = weak_ptr<Department>(e->department);

    return 0;
}