#include <iostream>
#include <vector>
#include <algorithm>
#include <random>	// shuffle
using namespace std;

int main() {

	vector<int> v1 { 1, 3, 2, 6, 3 };

	//rotate Direction <--
	//v1: 3 2 6 3 1
	rotate(v1.begin(), v1.begin() + 1, v1.end());

	// randomly rearrange elements
	shuffle(begin(v1), end(v1), default_random_engine(0));
	// random_shuffle is deprecated in c++14
	// v1: 3 3 1 6 2

	//you must SORT input first
	v1 = vector<int>{ 3, 1, 2};
	sort(v1.begin(), v1.end());
	do {
		for (auto x : v1)
			cout << x << " ";
		cout << "\n";
	} while (next_permutation(v1.begin(), v1.end()));
	/*
	 	1 2 3
		1 3 2
		2 1 3
		2 3 1
		3 1 2
		3 2 1
	 */

	return 0;
}
