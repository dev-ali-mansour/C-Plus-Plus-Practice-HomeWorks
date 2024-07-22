#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
using namespace std;

// https://cpluspluspedia.com/en/tutorial/2423/std--optional

template<class Range, class Pred>
auto find_if(Range&& range, Pred&& p) {
	auto b = begin(range), e = end(range);
	auto r = find_if(b, e, p);
	using iterator = decltype(r);
	if (r == e)
		return optional<iterator>();
	return optional<iterator>(r);
}

bool IsEven(int x) {
	return x % 2 == 0;
}

int main() {
	vector<int> v { 1, 2, 5 };

	if (find_if(v, IsEven))
		cout << "There is an even number\n";

	if (auto oit = find_if(v, IsEven)) {
		v.erase(*oit);
		cout<<v.size()<<"\n";
	}

	return 0;
}
