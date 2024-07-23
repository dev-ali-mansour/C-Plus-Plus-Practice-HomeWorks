#include <iostream>
#include <any>
#include <string>
using namespace std;

// https://www.bfilipek.com/2018/07/in-place-cpp17.html


struct Employee {
	Employee(string name, int salary)  {
		cout<<"Employee\n";
	}
	~Employee() {
		cout<<"~Employee\n";
	}
	//Employee(const Employee &e) = delete;
	//Employee(Employee &&e) = delete;
};

int main() {
	// objects with any must be copyable
	// Memory efficient initialization styles
	any a1 = make_any<Employee>("Mostafa", 1000);

	a1.emplace<Employee>("Mostafa", 1000);

	any a2 {in_place_type<Employee>, "Mostafa", 1000};

	/*
	 Employee
	~Employee
	Employee
	Employee
	~Employee
	~Employee
	 */




	return 0;
}
