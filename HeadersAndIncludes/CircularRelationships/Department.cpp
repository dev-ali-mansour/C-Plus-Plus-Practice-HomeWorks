#include "Department.h"

namespace OurSystem {
    Department::Department(std::string name_) {
        name = name_;
    }

    void Department::printDepartments() {
        cout << "Department name " << name
             << " has " << emp.size() << " Employees" << endl;
    }
}