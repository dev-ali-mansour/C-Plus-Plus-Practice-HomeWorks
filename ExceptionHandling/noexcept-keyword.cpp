#include <iostream>

using namespace std;

//noexcept: I don't throw exceptions
int my_abs(int x) noexcept {
    if (x < 0)return -x;
    return x;
}

int my_abs_div(int x, int y) noexcept(true) {
    return my_abs(x) / my_abs(y);
}

int main() {
    cout << my_abs_div(6, 2) << endl;
    cout << "Bye\n";

    return 0;
}