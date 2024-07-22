#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {

	vector<int> v { 5, 2, 7, 1, 2, 10, 50, 10, 17, 50 };

	// MUST sort data before next operations
	sort(v.begin(), v.end());

	// Search if exists
	bool ans = binary_search(v.begin(), v.end(), 17);
	cout << ans << "\n";

	//Finds the first element >= to a given value
	auto it = lower_bound(v.begin(), v.end(), 17);

	if (it != v.end())
		cout << *it << "\n";

	//Finds the first element > a given value
	it = upper_bound(v.begin(), v.end(), 17);
	if (it != v.end())
		cout << *it << "\n";

	it = unique(v.begin(), v.end());	// 1 2 5 7 10 17 50 	17 50 50
	int unique_size = it - v.begin();	// 7
	v.resize(unique_size);				// 1 2 5 7 10 17 50

	return 0;
}
