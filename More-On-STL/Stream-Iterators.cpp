#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>	// partial_sum
#include <sstream>
#include <iterator>	// ostream_iterator
using namespace std;


int main() {
	vector<int> v1 { 1, 3, 2, 6, 3 };

	// print vector
	auto it = ostream_iterator<int>(cout, " ");
	copy(v1.begin(), v1.end(), it);
	cout<<"\n";

	// convert vector to string
	ostringstream oss;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(oss, " "));
	cout << oss.str() << "\n";	// 1 3 2 6 3

	istringstream str("0.1 0.2 0.3 0.4");
	partial_sum(istream_iterator<double>(str), istream_iterator<double>(), ostream_iterator<double>(cout, ","));
	// 0.1,0.3,0.6,1,

	partial_sum(istream_iterator<double>(cin), istream_iterator<double>(), ostream_iterator<int>(cout, "\n"));
	// based on what u feed to the console, but casts to integer
	return 0;
}
