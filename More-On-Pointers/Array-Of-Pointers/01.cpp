#include <iostream>
#include <vector>
using namespace std;

int main() {

	int *arrop[3];
	int a = 10, b = 20, c = 50;

	arrop[0] = &a;
	arrop[1] = &b;
	arrop[2] = &c;

	cout << &a << " " << &b << " " << &c << "\n";
	for (int i = 0; i < 3; ++i)
		cout << &arrop[i] << " " << arrop[i] << " " << *arrop[i] << "\n";

	/*
	 	0x2000 0x2010 0x2050
		0x18d0 0x2000 10
		0x18d8 0x2010 20
		0x18e0 0x2050 50

	 */

	return 0;
}
