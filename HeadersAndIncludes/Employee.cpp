#include "Employee.h"

using namespace std;

Employee *emp_glob = new Employee("Ali");

Employee::Employee(string name_) {
    name = name_;
}

// Define
void Employee::print() {
    cout << "I am " << name << endl;
}

// but we did not include cout and string?
// visible from the .h file
