#ifndef HOMEWORKS_EMPLOYEE_H
#define HOMEWORKS_EMPLOYEE_H

#include <iostream>

using namespace std;

struct Employee {
    string name;

    //Declare
    Employee(string name);

    void print();
};

extern Employee *emp_glob;

#endif //HOMEWORKS_EMPLOYEE_H
