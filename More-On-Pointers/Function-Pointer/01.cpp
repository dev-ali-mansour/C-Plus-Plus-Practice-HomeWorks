#include <iostream>
using namespace std;

int Add(int x, int y) {
	return x + y;
}
void Print(string s) {
	cout << s << "\n";
}
int main() {
	// Pointer to function address
	// Observe the format
	int (*pAdd1)(int, int) = Add;
	int (*pAdd2)(int, int) = &Add;

	int res = pAdd1(2, 3);

	void (*MyPrint)(string) = Print;
	MyPrint("Mostafa");

	return 0;
}
