#include <iostream>
#include<forward_list>
using namespace std;

int main() {
	// designed to be efficient inserting and removing elements
		// in any position, even in the middle of the sequence.
	forward_list<int> lst {8, 2, 1};

	lst.assign(4, 6);			// 6 6 6 6
	lst.assign({1, 2, 3});		// 1, 2, 3

	lst.push_front(30);			// 30 1 2 3
	lst.pop_front();				// => 1 2 3

	// 1 5 6 8 2 3
	auto it = lst.insert_after(lst.begin(), {5, 6, 8});
	it = lst.emplace_after(it, 20);	//1 5 6 8 20 2 3
	it = lst.emplace_after(it, 40);	//1 5 6 8 20 40 2 3
	//it--;		// CE can't go back
	it++;	// point to 2
	it = lst.erase_after(it);		//1 5 6 8 20 40 2 3
	it = lst.begin();
	++it;
	lst.erase_after(it, lst.end());	// 1 5

	//lst[2];	can't random access

	for (auto &a : lst)
		cout << a << " ";
	cout << endl;

	return 0;
}
