#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	if (a > b)
		return true;
	return false;
}
void MySort(vector<int>& v, bool (*CMP)(int x, int y)) {
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

	//sort(v.begin(), v.end(), cmp);
	MySort(v, cmp);	// 9 8 3 2 1 0




	return 0;
}
