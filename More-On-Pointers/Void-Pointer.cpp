#include <iostream>
using namespace std;

void print(void *ptr) {
	// cast safely and use
}
int main() {
	// A void pointer can point to objects of any data type:
	void *ptr = nullptr;

	int x = 10;
	double y = 20.5;

	ptr = &x;
	// Cast back to an actual type to use
	int* iPtr = (int*)ptr;
	cout<<*iPtr<<"\n";

	ptr = &y;
	double* dPtr = static_cast<double*>(ptr) ;
	cout<<*dPtr<<"\n";

	return 0;
}
