#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
using namespace std;

// https://cpluspluspedia.com/en/tutorial/2423/std--optional

template<class Pred>
optional<vector<int>::iterator> find_if(vector<int> &range, Pred p) {
	vector<int>::iterator r = find_if(range.begin(), range.end(), p);

	if (r == range.end())
		return {};
	return r;
}

bool IsEven(int x) {
	return x % 2 == 0;
}

int main() {
	vector<int> v { 1, 2, 5 };

	if (find_if(v, IsEven))
		cout << "There is an even number\n";

	return 0;
}
