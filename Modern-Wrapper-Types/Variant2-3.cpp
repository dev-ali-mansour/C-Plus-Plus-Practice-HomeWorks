#include <iostream>
#include <variant>
#include <vector>
#include <memory>	// smart pointers
using namespace std;

// https://www.bfilipek.com/2020/04/variant-virtual-polymorphism.html

class Base {
public:
	virtual ~Base() = default;

	virtual void PrintName() const {
		cout << "calling Bases!\n";
	}
};

class Derived: public Base {
public:
	void PrintName() const override {
		cout << "calling Derived!\n";
	}
};

class ExtraDerived: public Base {
public:
	void PrintName() const override {
		cout << "calling ExtraDerived!\n";
	}
};

int main() {
	unique_ptr<Base> ptr = make_unique<ExtraDerived>();
	ptr->PrintName();

	return 0;
}
