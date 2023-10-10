#include <iostream>
#include <deque>

using namespace std;

int main() {
    int arr[]{1, 2, 3};

    for (auto val: arr)
        cout << val << " "; // 1 2 3
    cout << endl;

    deque<int> q{1, 2, 3, 4, 5};
    for (const auto &val: q)
        cout << val << " "; // 1 2 3 4 5
    cout << endl;

    for (auto val: {1, 2, 3, 4, 5})
        cout << val << " "; // 1 2 3 4 5
    cout << endl;

    for (auto val: "hello")
        cout << val; // hello
    cout << endl;
    return 0;
}