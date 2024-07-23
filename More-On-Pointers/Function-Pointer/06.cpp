#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


using Comparator = std::function< bool(int, int) >;

void MySort(vector<int>& v, Comparator CMP) {
	int n = v.size();	// Selection Sort
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i, j = -1;
		for (j = i + 1; j < n; j++)
			if (CMP(v[j], v[min_idx]))
				min_idx = j;
		swap(v[min_idx], v[i]);
	}
}

int main() {
	vector<int> v { 1, 8, 2, 9, 3, 0 };
	int counter = 0;
	auto cmp = [&counter](int a, int b) {
		++counter;
		if (a > b)
			return true;
		return false;
	};

	MySort(v, cmp);	// 9 8 3 2 1 0
	cout<<counter<<"\n";	// 15

	for (auto val : v)
		cout << val << " ";

	return 0;
}
