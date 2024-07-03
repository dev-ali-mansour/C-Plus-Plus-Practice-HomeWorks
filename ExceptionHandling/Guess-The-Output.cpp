#include <iostream>

using namespace std;

//noexcept: I don't throw exceptions
int my_abs(int x) {
    if (x < 0)return -x;
    return x;
}

int my_abs_div(int x, int y){
    return my_abs(x) / my_abs(y);
}

int main() {
    try {
        cout << my_abs_div(6, 0) << endl;
    } catch (...) {
        cout << "oooh\n";
    }

    cout << "Bye\n";

    return 0;
}

/*
 * You can't catch division by zero "low-level events, such as arithmetic
 * overflows and divide by zero, are assumed to be handled by a dedicated
 * lower-level mechanism rather than by exceptions"
 * */