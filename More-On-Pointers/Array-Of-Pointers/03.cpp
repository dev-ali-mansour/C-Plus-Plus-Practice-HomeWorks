#include <iostream>
using namespace std;

int main() {

	//char *str = "I am CONST char *";
	const char *str1 = "I am CONST char *";
	string str2 = "A copy will be made";

	// We don't need to specify the 1D array size
	const char *sports[] {
	                     "golf",
	                     "hockey",
	                     "football",
	                     "cricket",
	                     "shooting"
	                 };

	cout<<sizeof(sports)<<"\n";	// 40: 5 x 8 bytes
	sports[0] = "GOLFFF";



	return 0;
}
