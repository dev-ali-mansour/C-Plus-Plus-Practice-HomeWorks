#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<int> v1 { 5, 2, 7, 1, 2, 10, 50, 10, 17, 50 };
	vector<int> v2 { 7, 2, 30, 50, 40};

	// MUST sort data before next operations
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	vector<int> res;
	// back_inserter: constructs a std::back_insert_iterator
	// The container's push_back() member function is called whenever the iterator (whether dereferenced or not) is assigned to
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));
	// res: 2 7 50

	res.clear();
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));
	// res : 1 2 2 5 7 10 10 17 30 40 50 50

	res.clear();
	// copying elements present in the first range but not the second
	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));
	// 1 2 5 10 10 17 50

	res.clear();
	set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), back_inserter(res));
	// 30 40

	v1.resize(unique(v1.begin(), v1.end()) - v1.begin());
	v2.resize(unique(v2.begin(), v2.end()) - v2.begin());

	res.clear();
	// the elements that are found in either of the ranges, but not in both
	set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));
	// res: 1 5 10 17 30 40

	return 0;
}
