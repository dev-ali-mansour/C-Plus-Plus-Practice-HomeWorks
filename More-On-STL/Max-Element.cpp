#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Employee {
    int salary;

    bool operator < (const Employee& emp) const {
        return salary < emp.salary;
    }
};

int main() {
    Employee e1 {10};
    Employee e2 {5};
    Employee e3 {25};

    vector<Employee> v {e1, e2, e3};

    auto it = max_element(v.begin(), v.end());

    cout<<( *max_element(v.begin(), v.end()) ).salary <<"\n";	// 25

    int pos = distance(v.begin(), it);	// 2

    return 0;
}
