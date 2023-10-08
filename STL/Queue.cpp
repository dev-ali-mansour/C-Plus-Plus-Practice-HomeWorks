#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Last element in Queue: " << q.back() << endl;

    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    queue<string> q_names;
    q_names.push("Ali");
    string name = q_names.front();
    cout << name << endl;

    return 0;
}