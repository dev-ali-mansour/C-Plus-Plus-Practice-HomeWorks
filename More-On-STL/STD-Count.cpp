#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Employee {
    int salary;
    bool operator <(const Employee& emp) const {
        return salary == emp.salary;	// for set
    }
    bool operator == (const Employee& emp) const {
        return salary == emp.salary;	// for count
    }
};
int main() {
    Employee e1 { 10 };
    Employee e2 { 5 };
    Employee e3 { 25 };

    multiset<Employee> st {e1, e2, e2, e2, e3};

    cout<<std::count(st.begin(), st.end(), e2);	// 3

    // Observe: count needs == operator
    // set.count is FASTER than std::count
    // Whenever a data structure has its version, USE IT

    return 0;
}
