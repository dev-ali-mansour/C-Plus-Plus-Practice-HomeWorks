#include <iostream>
#include <vector>
#include <optional>
using namespace std;

int main() {
	optional<vector<int> > v { vector<int> { 1, 2, 3, 4 } };
	optional<vector<int> > cpy = v;
	// *v, v->, v.value()

	v = nullopt;	// make nullopt
	cout << v.value_or(vector<int>{}).size() << "\n";	// 0

	cout << cpy->size()<<"\n";	// still 4

	if(v != cpy)
		;	// relational operators normally

	// More memory efficient
	optional<vector<int>> v2(in_place, {1, 2, 3});
	v2 = {3, 4, 5};
	v2.emplace({3, 4, 5});	// Constructs the contained value in-place

	return 0;
}
