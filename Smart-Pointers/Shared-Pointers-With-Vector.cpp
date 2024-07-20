#include <memory>
#include <iostream>
#include <vector>

using namespace std;

void test() {
    typedef shared_ptr<int> intPtr;

    intPtr p1{new int{20}};
    cout << p1.use_count() << endl;     // 1

    vector<intPtr> vec;
    vec.push_back(p1);
    vec.push_back(p1);
    vec.push_back(p1);
    cout << p1.use_count() << endl;         // 4
    vec.clear();
    cout << p1.use_count();               // 1
}

int main() {
    test();

    return 0;
}