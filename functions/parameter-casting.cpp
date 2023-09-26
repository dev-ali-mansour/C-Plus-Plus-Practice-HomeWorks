#include <iostream>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

int main() {
    cout << sum(2, 3) << endl;
    cout << sum(2, 3.5) << endl;

    return 0;
}