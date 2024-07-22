#include <iostream>
#include <algorithm>
#include <valarray>
using namespace std;

int main() {
	int val[] = { 1, -2, 3, -4, -5 };
	// to manipulate lots of basic math operations, but on group of numbers
	valarray<int> v1(val, 5);	// NOT (val, val+5)

	valarray<int> v2 = abs(v1);	// 1 2 3 4 5

	cout << v2.sum() << "\n";	// 15

	valarray<int> v3 = 2 * (v1 + v2);	// element-wise

	valarray<bool> v4 = (v1 == v2);	// 1 0 1 0 0
	cout << v4.min() << " " << v4.max() << "\n";

	valarray<double> v5 { 0, 1, 2, 3 };
	valarray<double> v6 = 2 * v5 + 1;	// 1 3 5 7

	cout << pow(2.0, v5).sum() << "\n";	// 2^0 + 2^1 + 2^2 + 2^3 = 15
	cout << pow(v5, 2.0).sum() << "\n";	// 0^2 + 1^2 + 2^2 + 3^2 = 14
	cout << pow(2 * v5, v6).sum() << "\n";	// 2220
	//cout<<pow(v5, 2.0 * v6).sum()<<"\n";	// compile error
	// The second param don't make it temporary. Take in an object

	// other interesting operations: slice_array

	return 0;
}
