#include <iostream>
#include <vector>

using namespace std;

int my_abs(int x) {
    throw 2;
    if (x < 0)return -x;
    return x;
}

// We can pass an expression (ends as true/false)
int my_abs_div(int x, int y) noexcept(noexcept(my_abs(y))) {
    return my_abs(x) / my_abs(y);
}

template<typename T>
T MakeCopy(T const &src) noexcept(noexcept(T(src))) {
    return src;
}

int main() {
    cout << noexcept(my_abs(0)) << endl;       // 0
    cout << noexcept(my_abs_div(0, 0)) << endl;    // 0
    cout << noexcept(MakeCopy(vector<int>())) << endl;  // 0
    try {
        cout << my_abs_div(6, 2) << endl;
    } catch (...) {}
    cout << "Bye\n";

    return 0;
}