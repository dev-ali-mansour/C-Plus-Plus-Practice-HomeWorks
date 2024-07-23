#include <iostream>
#include <variant>
using namespace std;

// https://www.bfilipek.com/2020/04/variant-virtual-polymorphism.html

class Base {
public:
	void print() const {
		cout << "calling Bases!\n";
	}
};

class ExtraDerived {
public:
	void print() const {
		cout << "calling ExtraDerived!\n";
	}
};

int main() {
	variant<Base, ExtraDerived> var(ExtraDerived { });

	auto caller = [](const auto& obj) { obj.print(); };
	visit(caller, var);

	return 0;
}
