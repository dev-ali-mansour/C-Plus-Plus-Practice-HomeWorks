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

	optional<Employee> emp2{std::in_place, "Hani", 20};
	/*
		~Employee
		~Employee
	 */

	optional<vector<int>> opt{std::in_place, {4, 1, 20, 30}};

	return 0;
}

// template< class... Args >
// constexpr explicit optional( std::in_place_t, Args&&... args );

