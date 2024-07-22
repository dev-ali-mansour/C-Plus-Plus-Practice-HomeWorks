#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>

using namespace std;

bool isAlmostEqual(int a, int b) {
	return abs(a - b) < 2;
}

int main() {
	vector<int> v1 { 1, 3, 2, 6, 3 };

	//adjacent_difference: 1 2 -1 4 -3  [change array itselfwith v1.begin()]
	adjacent_difference(v1.begin(), v1.end(), v1.begin());


	v1 = vector<int>{ 1, 3, 2, 6, 3 };
	vector<int> res;
	// adjacent_sum: res: 1 4 5 8 9
	adjacent_difference(v1.begin(), v1.end(), back_inserter(res), plus<>());

	// find the first 2 adjacent elements who are EQUAL based on equal function
	auto it = adjacent_find(v1.begin(), v1.end(), isAlmostEqual);	// 3 2

	return 0;
}
