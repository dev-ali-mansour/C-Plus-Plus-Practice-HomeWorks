#include <iostream>
#include <variant>
#include <cmath>
using namespace std;



using var_roots = variant<pair<double,double>, double, monostate>;

var_roots compute_roots(double a, double b, double c) {
	auto d = b * b - 4 * a * c; // discriminant
	if (d > 0.0) {
		auto p = sqrt(d) / (2 * a);
		return make_pair(-b + p, -b - p);
	} else if (d == 0.0)
		return (-1 * b) / (2 * a);
	else
		return monostate();
}

struct MyVisitor {
	void operator()(double& arg) {
		cout << "1 root found: " << arg << '\n';
	}
	void operator()(pair<double, double> & arg) {
		cout << "2 roots found: " << arg.first << " " << arg.second << '\n';
	}
	void operator()(monostate & arg) {
		cout << "No real roots found.\n";
	}
};

int main() {

	MyVisitor print_visitor;

	var_roots res = compute_roots(1, 0, -1);	// 2 roots found: 1 -1
	std::visit(print_visitor, res);

	res = compute_roots(1, 6, 9);	// 1 root found: -3
	visit(print_visitor, res);

	res = compute_roots(1, -3, 4);	// No real roots found.
	visit(print_visitor, res);

	return 0;
}
