#include <iostream>

using namespace std;

void print_nums(int a, int b);

int main() {
    print_nums(2, 5);

    return 0;
}

void print_nums(int a, int b) {
    cout << a << " " << b << endl;
}