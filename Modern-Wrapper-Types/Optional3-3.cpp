#include <iostream>
#include <vector>
#include <optional>
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
	//CE: Can't copy!
	//optional<Employee> emp1{Employee{"Hani", 20}};

	optional<Employee> emp2{std::in_place, "Hani", 20};
	/*
		~Employee
		~Employee
	 */

	optional<vector<int>> opt{std::in_place, {4, 1, 20, 30}};

	return 0;
}
