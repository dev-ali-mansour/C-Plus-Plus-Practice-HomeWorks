#include <iostream>
#include <vector>
#include <optional>
using namespace std;

// https://www.bfilipek.com/2018/07/in-place-cpp17.html

struct Employee {
	Employee(string name, int salary)  {
		cout<<"Employee\n";
	}
	Employee(Employee &&emp){
		cout<<"Employee &&\n";
	}
	~Employee() {
		cout<<"~Employee\n";
	}
};

int main() {
	optional<Employee> emp1{};	// Empty Optional

	optional<Employee> emp2{Employee{"Hani", 20}};
	/*
	 	Observe: unnecessary copy

		Employee
		Employee &&
		~Employee
		~Employee
	 */

	optional<vector<int>> opt{vector<int>{4, 1, 20, 30}};

	// Also notice: repeating the class name

	return 0;
}
