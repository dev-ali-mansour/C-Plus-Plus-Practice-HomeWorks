#include <iostream>
#include <vector>

using namespace std;

void do_math(int &x) {
    // Guarantee this function
    // Never called with null
    x = x + 1;
    x = x * 2;     // multiply with 2
    x *= 2;        // multiply with 2
}

void do_math(int *x) {
    if (x == nullptr) return;

    *x = *x + 1;
    *x = *x * 2;      // multiply with 2
    *x *= 2;        // multiply with 2
}

void print(vector<int> *ptr) {
    for (auto v: *ptr)
        cout << v << " ";
}

int main() {

    int x1 = 4;

    do_math(x1);

    cout << x1 << endl;    // 20

    x1 = 4;
    do_math(&x1);

    cout << x1 << endl;     // 20

    vector<int> v{5, 7, 8};
    print(&v);

    return 0;
}