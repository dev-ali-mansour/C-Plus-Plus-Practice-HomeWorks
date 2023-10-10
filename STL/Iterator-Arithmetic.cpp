#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> q{1, 2, 3, 4, 5};
    auto it = q.begin() + 3; // Fourth element position
    cout << *it << endl; // 4

    cout << *(it--) << endl;    // 4 then move to the third position
    cout << *it << endl;        // 3

    cout << *(--it) << endl;    // 2
    cout << *it << endl;        // 2 now on 2nd

    cout << *(it + 3) << endl;  // 5th position
    it += 3;
    cout << *it << endl;        // 2 Now on 5th position

    // Reset all to 10
    for (auto it2 = q.begin(); it2 < q.end(); ++it2) {
        *it2 = 10;
    }

    auto itr = q.begin();
    while (itr != q.end()) {
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;

    return 0;
}