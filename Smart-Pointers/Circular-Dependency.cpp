#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Department;

struct Employee {
    shared_ptr<Department> department;
};

typedef shared_ptr<Employee> EmpPtr;
typedef vector<EmpPtr> EmpVec;

struct Department {
    EmpVec employees;
};


int main() {
    EmpPtr e = make_shared<Employee>();
    shared_ptr<Department> d = make_shared<Department>();
    e->department = d;
    d->employees.push_back(e);

    // We are about to go out of scope
    // e is waiting for d destruction to be released
    // d is waiting for e destruction to be released
    cout << e.use_count() << " " << d.use_count() << endl;      // 2 2
    return 0;
}