#include "Employee.h"

// Important to see the completer implementation later
#include "Department.h"

Department sd = Department("Software Development");
Department it = Department("IT");
vector<Department *> deps({&sd, &it});
Employee *emp_glob = new Employee("Ali", deps);

Employee::Employee(string name_, vector<Department *> deps_) {
    name = name_;
    deps = deps_;
}

void Employee::print() {
    cout << "I am " << name << endl;
    cout << "I work in the flollowing departments: \n";

    for (Department *d: deps)
        d->printDepartments();
}