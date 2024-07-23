#include <iostream>
#include <variant>
#include <cmath>
using namespace std;


// https://www.walletfox.com/course/patternmatchingcpp17.php

struct Employee {
	Employee(string name) {}
};
std::variant<monostate, Employee> good;
//std::variant<Employee> bad; CE






using var_roots = variant<monostate, double, pair<double,double>>;

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

void print(var_roots &res) {
	if (res.index() == 0)
		cout << "No real roots found.\n";
	else if (res.index() == 1)
		cout << "1 root found: " << get<1>(res) << '\n';
	else {
		pair<double, double> &arg = get<2>(res);
		cout << "2 roots found: " << arg.first << " " << arg.second << '\n';
	}
}
int main() {
	var_roots res = compute_roots(1, 0, -1);
	print(res);	// 2 roots found: 1 -1

	res = compute_roots(1, 6, 9);
	print(res);	// 1 root found: -3

	res = compute_roots(1, -3, 4);
	print(res);	// No real roots found.

	return 0;
}
