#include <iostream>
#include <queue>

using namespace std;

struct OurStack {
    queue<int> q;

    void push(int val) {
        int s = q.size();
        q.push(val);

        while (s--)
            q.push(q.front()), q.pop();
    }

    void pop() {
        if (!q.empty())
            q.pop();
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    OurStack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty())
        cout << s.top() << " ", s.pop();

    return 0;
}