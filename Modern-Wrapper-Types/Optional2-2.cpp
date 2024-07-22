#include <iostream>
#include <vector>
#include <optional>
using namespace std;

// https://devblogs.microsoft.com/cppblog/stdoptional-how-when-and-why/

struct MyClass {
	MyClass(const vector<int> &v, int x, string name) {

	}
	// no default constructor - shouldn't
};

struct AnotherClass {
	//MyClass obj;	// CE no default constructor
	optional<MyClass> obj;	// perfect NO initialization

	AnotherClass(int n) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			v[i] = i * i;

		// emplace uses varidic template
		obj.emplace(v, n, "Mostafa");
	}
};

// Optional solves the delayed initialization problem

int main() {

}
