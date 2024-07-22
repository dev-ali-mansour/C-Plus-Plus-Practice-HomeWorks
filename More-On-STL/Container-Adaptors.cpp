#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <list>
using namespace std;

int main() {
	stack<int> s1;					// dequeue-based internally
	stack<int, vector<int>> s2;		// vector-based internally
	stack<int, queue<int>> s3;		// queue-based internally
	stack<int, list<int>> s4;		// list-based internally

	queue<int> q1;	// needs contain with push_back
	queue<int, vector<int>> q2;
	queue<int, list<int>> q3;

	// wrong. will compile if not used. Once used with push, will CE
	queue<int, stack<int>> q4;
	queue<int, set<int>> q5;

	// error: ‘class std::set<int>’ has no member named ‘push_back’
	//q5.push(10);

	return 0;
}
