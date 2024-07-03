#ifndef HOMEWORKS_DEPARTMENT_H
#define HOMEWORKS_DEPARTMENT_H

#include "Employee.h"

struct Department {
    string name;
    vector<Employee> emp;

    Department(string name_);
    void printDepartments();
};

#endif //HOMEWORKS_DEPARTMENT_H
