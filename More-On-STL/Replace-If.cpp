#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

struct Employee {
	int salary;
	// Must be provided for replace variants
	bool operator ==(const Employee& emp) const {
		return salary == emp.salary;
	}
};
bool IsOddSalary(const Employee& emp) {	// predicate
	return emp.salary % 2 != 0;
}
int main() {
	Employee e1 { 10 };
	Employee e2 { 5 };
	Employee e3 { 25 };

	vector<Employee> v { e1, e2, e2, e2, e3 };
	// 10 5 5 5 25

	std::replace(v.begin() + 2, v.end(), e2, e3);
	// 10 5 25 25 25

	std::replace_if(v.begin(), v.end(), IsOddSalary, e1);
	// 10 10 10 10 10

	for (const auto & item : v)
		cout << item.salary << " ";
	cout<<"\n";


	return 0;
}
