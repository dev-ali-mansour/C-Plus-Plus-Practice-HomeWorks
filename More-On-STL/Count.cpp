#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

struct Employee {
    int salary;

    bool operator <(const Employee& emp) const {	// must const
        return salary < emp.salary;
    }
};
bool IsOddSalary(const Employee& emp) {	// predicate
    return emp.salary % 2 != 0;
}
int main() {
    Employee e1 { 10 };
    Employee e2 { 5 };
    Employee e3 { 25 };
    Employee e4 { 30 };

    multiset<Employee> st {e1, e2, e2, e2, e3};
    cout << st.count(e2) << "\n";
    cout << st.count(e4) << "\n";

    auto it = st.begin();
    //*it = e1;		// CE: can't change item. Const
    // Internals of set/map is a tree based data structure
    // You can't just change value as built in a special way

    // Observe:
    // We did not provide == operator
    // It can internally use < to know equal
    // if a < b false and b < a false, then a == b

    // You must provide the 2 const here
    // bool operator <(const Employee& emp) const
    // Otherwise the function can change the variables
    // which is AGAINST the internal design

    return 0;
}
