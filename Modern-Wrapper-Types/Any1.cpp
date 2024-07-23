#include <iostream>
#include <any>
#include <string>
using namespace std;


int main() {

	// any: store ANY type at runtime
	// narrow use cases, but good to know

	any nothing1;		// has no value
	auto nothing2 = any{};

	any a(12.5);	// not a template
	a = string("Hello!");
	a = 16;
	any b = a;	// copy

	cout << any_cast<int>(a) << '\n';
	// bad_any_cast
	// cout << any_cast<string>(a) << '\n';

	string* p1 = std::any_cast<string>(&a);	// nullptr
	any_cast<int&>(a) = 11;	// assign by reference

	a.reset();
	a.has_value();	// false;




	return 0;
}
