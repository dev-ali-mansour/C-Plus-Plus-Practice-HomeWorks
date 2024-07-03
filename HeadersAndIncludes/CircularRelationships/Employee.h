#ifndef HOMEWORKS_EMPLOYEE_H
#define HOMEWORKS_EMPLOYEE_H

#include <iostream>
#include <vector>
#include "Department.h"

using namespace std;

struct Employee{
    string name;
    vector<Department*>deps;

    //
    // Declare
    Employee(string name_);
    void print();
};
#endif //HOMEWORKS_EMPLOYEE_H
