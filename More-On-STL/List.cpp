#include <iostream>
#include<list>
using namespace std;

int main() {
	// designed to be efficient inserting and removing elements
		// in any position, even in the middle of the sequence.
		// You will study linked lists in data structures course
	list<int> lst {8, 2, 1};

	lst.assign(4, 6);			// 6 6 6 6
	lst.assign({1, 2, 3});		// 1, 2, 3

	lst.push_front(30);			// 30 1 2 3
	lst.pop_front();			// => 1 2 3
	lst.push_back(20);			// 1 2 3 20

	//lst[2];	can't random access

	// 5 6 8 1 2 3 20
	auto it = lst.insert(lst.begin(), {5, 6, 8});	// it to 5
	//it += 2;	// CE
	it++;
	++it;
	--it;	// can go backward - points to 6
	it = lst.erase(it);		//5 8 1 2 3 20

	for (auto &a : lst)
		cout << a << " ";
	cout << endl;

	return 0;
}
