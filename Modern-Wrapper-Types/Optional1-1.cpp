#include <iostream>
using namespace std;

pair<bool, double> divide1(double a, double b) {
	if (b != 0.0)
		return {true, a / b};
	return {false, 0};
}

int process(int val = -1, int *p = nullptr) {
	if (val == -1 && p == nullptr)
		return -1;	// flag for can't process
	// or return <int, bool> to indicate
	int ret = 0;

	if (val != -1)
		ret += 2 * val + 1;
	if (p != nullptr)
		ret += 3 + *p;
	return ret;
}

int main() {


	return 0;
}
