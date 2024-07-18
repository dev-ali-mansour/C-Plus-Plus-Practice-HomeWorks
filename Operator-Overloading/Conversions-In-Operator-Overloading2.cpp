#include <iostream>

using namespace std;

class MyPair {
private:
    int first, second;
public:
    MyPair(int x) : MyPair(x, x) {}

    MyPair(int first_, int second_) : first(first_), second(second_) {}

    MyPair(pair<int, int> p) :    // Use explicit
            first(p.first), second(p.second) {}

    void print() {
        cout << "(" << first << "," << second << ")\n";
    }

    int getFirst() const {
        return first;
    }

    void setFirst(int first) {
        MyPair::first = first;
    }

    int getSecond() const {
        return second;
    }

    void setSecond(int second) {
        MyPair::second = second;
    }

    operator int() {
        return first * second;
    }

    operator pair<int, int>() {
        return make_pair(first, second);
    }
};

int main() {
    MyPair x(2, 3);

    int r=x;                // 6
    pair<int,int>p=x;       // operator pair<int, int>()
    x=p;                    // // MyPair(pair<int, int> p)

    cout<<p.first<<" "<<p.second<<endl;

    return 0;
}