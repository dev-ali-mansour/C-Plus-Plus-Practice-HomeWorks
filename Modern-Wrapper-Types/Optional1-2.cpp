#include <iostream>
#include <optional>
using namespace std;

int main() {
	optional<int> x1 { 5 };
	optional x2 { 5 };
	auto x3 = make_optional(5);
	optional<int> x4 { nullopt };	// No value
	optional<int> x5 { };			// No value

	if (x3.has_value())
		cout << x3.value() << "\n";	// 5
		//cout << *x3 << "\n";

	if (!x4)
		cout << "x4 is empty so far\n";	// printed

	//cout << x5.value() << "\n";		// Exception: bad optional access
	cout << x5.value_or(-1) << "\n";	// -1
	cout << *x5 << "\n";				// Undefined behavior if not exists

	x1.reset();		// make nullopt
	x2 = nullopt;	// make nullopt
	x2 = 20;	// set new value

	return 0;
}
