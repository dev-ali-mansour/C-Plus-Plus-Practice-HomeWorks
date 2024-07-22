#include <iostream>
#include <vector>
#include <optional>
using namespace std;

optional<double> divide2(double a, double b) {
	if (b != 0.f)
		return a / b;
	return {};
}

int main() {
	optional<double> ret = divide2(6, 3);

	if (ret)
		cout << *ret << "\n";

	ret = divide2(6, 0);

	if(!ret)
		cout<<"Not possible\n";

	return 0;
}
