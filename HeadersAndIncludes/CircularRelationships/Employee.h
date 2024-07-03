#ifndef HOMEWORKS_EMPLOYEE_H
#define HOMEWORKS_EMPLOYEE_H

#include <iostream>
#include <vector>
//#include "Department.h"   Don't

using namespace std;

namespace OurSystem {
    struct Department;

    struct Employee {
        string name;
        vector<Department *> deps;

        //
        // Declare
        Employee(string name_, vector<Department *> deps_);

        void print();
    };

    extern Employee *emp_glob;
}
#endif //HOMEWORKS_EMPLOYEE_H
