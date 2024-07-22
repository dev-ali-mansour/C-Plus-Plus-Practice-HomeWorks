#include <iostream>
#include <optional>
#include <vector>
using namespace std;

// https://www.bfilipek.com/2018/07/in-place-cpp17.html

struct Employee {
	Employee(string name, int salary)  {
		cout<<"Employee\n";
	}
	~Employee() {
		cout<<"~Employee\n";
	}
	Employee(const Employee &e) = delete;
	Employee(Employee &&e) = delete;
};

int main() {
	optional<Employee> emp;
	emp.emplace("Hani", 20);
	/*
		Employee
		~Employee
	 */

	optional<vector<int>> v(in_place, {1, 2, 3});
	v = {3, 4, 5};
	v.emplace({3, 4, 5});	// Constructs the contained value in-place
	return 0;
}
