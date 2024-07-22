#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

struct Employee {
    int salary;

    // Must be provided for find variants
    bool operator==(const Employee &emp) const {
        return salary == emp.salary;
    }
};

bool IsOddSalary(const Employee &emp) {    // predicate
    return emp.salary % 2 != 0;
}

int main() {
    Employee e1{10};
    Employee e2{5};
    Employee e3{25};
    Employee e4{30};
    vector<Employee> v{e1, e2, e3};

    auto it = find(v.begin(), v.end(), e2);
    assert(it != v.end());
    assert(find(v.begin(), v.end(), e4) == v.end());

    it = find_if(v.begin(), v.end(), IsOddSalary);
    if (it != v.end())
        cout << it->salary;

    it = find_if_not(v.begin(), v.end(), IsOddSalary);    // 10
    it = find_if_not(v.begin(), v.end(), [](const Employee &emp) {
                         return emp.salary % 2 != 0;
                     }
    );

    return 0;
}
