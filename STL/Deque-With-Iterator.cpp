#include <iostream>
#include <queue>

using namespace std;

void print_back(deque<int> q) {
    cout << "Queue elements (back): ";
    while (!q.empty()) {
        cout << q.back() << " ";
        q.pop_back();
    }
    cout << endl;
}

void print_back1(deque<int> &q) {
    cout << "Queue elements (back): ";
    // Reverse iterator
//    deque<int>::reverse_iterator it=q.rbegin();
    auto it = q.rbegin();
    while (it != q.rend()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void print_back2(deque<int> &q) {
    cout << "Queue elements (back): ";
    for (auto it = q.rbegin(); it != q.rend(); ++it)
        cout << *it << " ";
    cout << endl;
}

void print_front(deque<int> &q) {
    cout << "Queue elements (front): ";

//    deque<int>::iterator it = q.begin();
    auto it = q.begin();

    while (it != q.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void print_front_const(deque<int> &q) {
    cout << "Queue elements (front): ";

//    deque<int>::const_iterator it = q.cbegin();
    auto it = q.cbegin();

    while (it != q.end()) {
        cout << *it << " ";
        // *it = 10; // Can't - Constant
        ++it;
    }
    cout << endl;
}

int main() {
    deque<int> q;
    q.push_back(20); // 20
    q.push_back(30); // 20 30
    q.push_back(40); // 20 30 40
    q.push_front(10); //10 20 30 40 50
    q.push_back(50); // 10 20 30 40 50
    q.push_front(0); // 0 10 20 30 40 50

    deque<int> copy = q;
    print_back(q); // 50 40 30 20 10 0
    print_back1(q); // 50 40 30 20 10 0
    print_back2(q); // 50 40 30 20 10 0
    print_front(q); // 0 10 20 30 40 50

    cout << copy.size() << endl;        // 6
    cout << copy[1] << endl;            //10
    cout << copy.at(1) << endl;      //10
//    cout << copy.at(1000) << endl;   // throws std:: out_of_range exception

    copy.clear();
    cout << copy.size() << endl; // 0
    return 0;
}