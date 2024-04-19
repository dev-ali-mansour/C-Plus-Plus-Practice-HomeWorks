#include <iostream>

using namespace std;

int absolute(int n);

int main() {
    cout << absolute(5) << endl;
    cout << absolute(-5) << endl;

    return 0;
}


int absolute(int n) {
    if (n >= 0)
        return n;
    return -n;
}