#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Employee {
	int salary;

	// Must be provided for search_n
	bool operator ==(const Employee& emp) const {
		return salary == emp.salary;
	}
};

int main() {
	Employee e1 { 10 };
	Employee e2 { 5 };
	Employee e3 { 25 };

	vector<Employee> v { e1, e2, e2, e2, e3 };

	// find position of 3 consecutive e2 objects
	auto it = search_n(v.begin(), v.end(), 3, e2);

	cout<<distance(v.begin(), it)<<"\n";	// 1

	vector<Employee> v2 = v;

	if (v2 == v)	// < > !=
		cout<<"Yes\n";

	v2.erase(v2.begin());
	// search for a sub-vector in a vector
	it = search(v.begin(), v.end(), v2.begin(), v2.end()-1);
	cout<<distance(v.begin(), it)<<"\n";	// 1



	return 0;
}
