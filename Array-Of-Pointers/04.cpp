#include <vector>
using namespace std;

int main() {

	// 1 Consecutive block of 15 integers
	int arr1[][5] {	// 3x5
			{1, 2, 3, 4, 1},
			{5, 6, 7, 8, 2},
			{9, 10, 11, 12, 3},
	};

	int *arr2[3] {};	// 3 null pointer

	for (int i = 0; i < 3; ++i)
		arr2[i] = new int[5] {};	// 5 zeros

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 5; ++j)
			arr2[i][j] = i * j;

	// Now arr2 is array of pointers
	// Total 1 + 3 = 4 consecutive blocks

	for (int i = 0; i < 3; ++i) {
		delete[] arr2[i];
		arr2[i] = nullptr;
	}



	return 0;
}
