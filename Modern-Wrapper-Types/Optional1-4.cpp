#include <iostream>
#include <vector>
#include <optional>
#include <string>
using namespace std;

// https://www.bfilipek.com/2018/05/using-optional.html

optional<int> ParseInt(char*arg) {
	try {
		return stoi(string(arg));
	} catch (...) {
		cout << "cannot convert \'" << arg << "\' to int!\n";
	}
	return {};
}

int main(int argc, char* argv[]) {
	if (argc >= 3) {
		auto oFirst = ParseInt(argv[1]);
		auto oSecond = ParseInt(argv[2]);

		if (oFirst && oSecond) {
			cout << "sum of " << *oFirst << " and " << *oSecond;
			cout << " is " << *oFirst + *oSecond << "\n";
		}
	}
}
