#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test1() {
    vector<int> v1; //Array that can be expanded

    v1.push_back(30);
    v1.push_back(10);
    v1.push_back(20);
    // Now we have 3 elements only

    for (int i = 0; i < (int) v1.size(); ++i)
        cout << v1[i] << " ";   // 30 20 10
    cout << endl;

    vector<int> v2(5, 7);
    // Like an array with 5 numbers all initialized with 7

    v2.push_back(13); // Now we added extra num = 13

    for (auto &val: v2)
        cout << val << " ";
    cout << endl;

    // v2.at(1000); // Exception
    // Later: emplace_back
}

void test2() {
    vector<int> v{3, -4, 7, -2, -1, 3, -5, 10, 3};

    // Let's remove negative values
    for (auto it = v.begin(); it != v.end();) {
        if (*it < 0) {
            // You must use the returned iterators as erase invalidate it
            // Working in some cases != working all cases / data structures
            it = v.erase(it);
            // It points to the next element. Don't increment it
        } else
            ++it;   // Update ONLY if not removed
    }
    // 3 7 3 10 3
    for (auto &val: v)
        cout << val << " ";
    cout << endl;
}

void test3() {
    vector<int> v{3, -4, 7, -2, -1, 3, -5, 10, 3};
    // Find is an algorithm. See algorithms video

    auto it = find(v.begin(), v.end(), -2);

    if (it != v.end()) {
        vector<int> v2{8, 9, 10};
        v.insert(it, v2.begin(), v2.end());
    }

    // 3 -4 7 8 9 10 -2 -1 3 -5 10 3
    for (auto &val: v)
        cout << val << " ";
    cout << endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}