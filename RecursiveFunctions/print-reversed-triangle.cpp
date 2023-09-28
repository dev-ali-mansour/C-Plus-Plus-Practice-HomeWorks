#include <iostream>

using namespace std;

void print_triangle(int levels) {
    if (levels == 0)
        return;

    // Here The trick is swiping calling recursive function with its logic
    print_triangle(levels - 1);

    for (int i = 0; i < levels; ++i)
        cout << "*";
    cout << endl;
}

int main() {
    print_triangle(5);
    return 0;
}