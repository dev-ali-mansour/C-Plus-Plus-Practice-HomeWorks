#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    unordered_set<int> s1{20, 10, 20, 5, 30};

    s1.insert(7);
    s1.insert(0);

    for (auto v: s1)
        cout << v << " ";
    cout << endl;   // 0 30 5 10 7 20 : Removed duplicates

    // If container has a method, use it.
    // as it consider the internal representation
    auto it1 = s1.find(20); // Fast
    cout << *it1 << endl;
    //*it1=20;    // Can't change

    // Generic algorithms iterate in generic/same way.
    // No idea about internal representation.
    auto it2 = find(s1.begin(), s1.end(), 20); // Slow
    cout << *it2 << endl;

    cout << s1.size() << endl;    // 6
    s1.erase(s1.begin());
    cout << s1.size() << endl;    // 5

    set<int> sorteds(s1.begin(), s1.end());   // 5 7 10 20 30

    int arr[]{20, 10, 20, 5, 30, 7, 0};
    unordered_set<int> s2{arr, arr + 3};

    s1.swap(s2);    // Swapping operation: 0 7 30 5 10 20

    ////////////////////////////////////
    // No reverse iterator
    // unordered_multiset: same but allows duplicates
    // In general most operations are fast
    // Based on HashTable
    // In data structures course, You will learn how to use it efficiently
    ////////////////////////////////////

    return 0;
}