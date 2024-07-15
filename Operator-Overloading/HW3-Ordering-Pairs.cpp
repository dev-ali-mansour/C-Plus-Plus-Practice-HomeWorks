#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyPair {
private:
    int first, second;
public:
    MyPair(int first_, int second_) : first(first_), second(second_) {}

    bool operator<(MyPair &c2) {
        return tie(first, second) < tie(c2.first, c2.second);
    }

    void print() {
        cout << "(" << first << "," << second << ")\n";
    }

    int getFirst() const {
        return first;
    }

    void setFirst(int first_) {
        MyPair::first = first_;
    }

    int getSecond() const {
        return second;
    }

    void setSecond(int second_) {
        MyPair::second = second_;
    }
};

int main() {
    vector<MyPair> vec;
    vec.push_back(MyPair(10, 20));
    vec.push_back(MyPair(10, 7));
    vec.push_back(MyPair(1, 200));

    sort(vec.begin(), vec.end());

    for (auto &pair: vec) {
        pair.print();   // (1,200)  (10,7)  (10,20)
    }
}