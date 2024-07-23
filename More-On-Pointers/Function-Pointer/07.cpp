#include <iostream>
using namespace std;

void ByeMsg() {
	cout << "Thanks for using our program\n";
}

int main() {
	// Register a function to be called when `exit' is called.
	atexit(ByeMsg);

	cout << "Hey hello\n";

	return 0;
}
