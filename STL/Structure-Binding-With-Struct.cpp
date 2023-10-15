#include <iostream>

using namespace std;

struct Employee {
    string name;
    int salary;
};

int main() {
    Employee emp{"Ali", 50};

    // bind by value
    auto [str1, sal1] = emp;

    // bind by reference
    auto &[str2, sal2] = emp;

    sal2 += 30;   // emp.salary now 80

    const auto &[str3, sal3] = emp;


    return 0;
}