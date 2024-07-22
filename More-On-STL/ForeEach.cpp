#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Employee {
	int salary;
};

struct Sum {
	int sum { 0 };

	void operator()(const Employee& emp) {
		sum += emp.salary;
	}
};

int main() {
	Employee e1 { 10 };
	Employee e2 { 5 };
	Employee e3 { 25 };

	vector<Employee> v { e1, e2, e3 };

	for_each(v.begin(), v.end(), [](const Employee &emp) {
		cout<<emp.salary<<" ";	// 10 5 25
	});

	// Interesting usage
	Sum s = for_each(v.begin(), v.end(), Sum());
	cout << s.sum;	// 40

	return 0;
}
