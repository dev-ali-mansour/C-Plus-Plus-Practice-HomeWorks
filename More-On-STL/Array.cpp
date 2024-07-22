#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main() {
	// wraps around FIXED size arrays
	// doesn’t loose the information of its length when decayed to a pointer.
	// array is a great replacement for built-in fixed arrays
		//  it doesn’t use any more memory

	array<int, 5> arr {3, 4, 5, 1, 2};	// list initialization
	arr.size();	// 5

	arr[0] = 9;
	//arr.at(20) = 10;	// out_of_range exception

	sort(arr.begin(), arr.end());	// 1 2 4 5 9

	arr = { 9, 8, 7 };	// 9 8 7 0 0
	//arr = { 0, 1, 2, 3, 4, 5 };	// CE 6 elements

	int *p = arr.data();

	// The type is deduced to std::array<double, 2>
	array myArray { 9.7, 7.31 };	// Since C++17

	for (auto &a : arr)
		cout << a << " ";
	cout << endl;

	return 0;
}
