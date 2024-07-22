#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>	// accumulate & inner_product

using namespace std;

int main() {

	vector<int> v1 { 1, 2, 3, 4, 5 };
	vector<int> v2 { 2, 3, 1};

	// Sort from big to small: 3 2 1
	sort(v2.begin(), v2.end(), greater<int>());	// <int> old style: may cause problems
	sort(v2.begin(), v2.end(), greater<>());	// Modern - reduce error in types

	// Array sum = 120
	int vecSum = std::accumulate(v1.begin(), v1.end(), 0);
	// Array product = 24
	int vecMul = accumulate(v1.begin(), v1.end(), 1, multiplies<>());

	// inner product: V1[0] * V1[0] + V2[0]*v1[0]...
	int sumOfProducts1 = inner_product(v1.begin(), v1.end(), v1.begin(), 0);
	// same as above
	int sumOfProducts2 = inner_product(v1.begin(), v1.end(), v1.begin(), 0, plus<>(), multiplies<>());
	// 1 * (V1[0] + V1[0]) * (V2[0] + v1[0])
	int productsOfSum = inner_product(v1.begin(), v1.end(), v1.begin(), 1, multiplies<>(), plus<>());

	// 0, 1 are the initial value for computation

	vector<int> res;
	partial_sum(v1.begin(), v1.end() - 1, back_inserter(res));
	// partial accumulation 1 3 6 10

	res.clear();
	partial_sum(v1.begin(), v1.end(), back_inserter(res), minus<>());
	// partial accumulative subtraction: 1 -1 -4 -8 -13


	return 0;
}
