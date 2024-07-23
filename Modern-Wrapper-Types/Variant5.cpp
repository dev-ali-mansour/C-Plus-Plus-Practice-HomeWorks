#include <iostream>
#include <variant>
#include <vector>
using namespace std;

int main() {
	variant<int, double> var1 { 10.5 };	// works!

	// CE: now the double can be converted to both int or float?!
	//variant<int, float> var2 { 10.5 };

	variant<int, float> var2 { in_place_index<0>, 10.5 };
	variant<int, float> var3 { in_place_type<int>, 10.5 };

	// For efficient memory: // initializer list passed into vector
	variant<vector<int>, string> var4 {in_place_index<0>, { 0, 1, 2, 3 } };

	variant<float, int, double> var5 = 0;	// ok
	//variant<float, long, double> var6 = 0;	// maybe not ok
	variant<float, long, double> var6 = 0L;

	return 0;
}
