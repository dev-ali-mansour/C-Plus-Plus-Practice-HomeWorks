using namespace std;

int main() {

	char sports[5][15] = {
	                         "golf",
	                         "hockey",
	                         "football",
	                         "cricket",
	                         "shooting"
	                     };
	// sports[0] = "GOLFFF";
	// CE: incompatible types in assignment of
		// ‘const char [7]’ to ‘char [15]’
	// You have to copy by a loop

	return 0;
}
