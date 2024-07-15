#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyPair {
protected:
    int first, second;
public:
    MyPair(int first_, int second_) : first(first_), second(second_) {}

    bool operator<(MyPair &c2) {
        return tie(first, second) < tie(c2.first, c2.second);
    }

    virtual void print() {
        cout << "(" << first << "," << second << ")\n";
    }
};

class NamedPair : public MyPair {
private:
    string name;
public:
    NamedPair(string name_, int first_, int second_) : MyPair(first_, second_), name(name_) {
    }

    bool operator<(NamedPair &c2) {
        return tie(name, first, second) < tie(c2.name, c2.first, c2.second);
    }

    void print() override {
        cout << "(" << name << ": " << first << "," << second << ")\n";
    }
};

int main() {
    vector<NamedPair> vec;
    vec.push_back(NamedPair("A", 10, 20));
    vec.push_back(NamedPair("B", 10, 7));
    vec.push_back(NamedPair("B", 1, 200));

    sort(vec.begin(), vec.end());

    for (auto &pair: vec) {
        pair.print();   // (A: 10,20)   (B: 1,200)  (B: 10,7)
    }
}