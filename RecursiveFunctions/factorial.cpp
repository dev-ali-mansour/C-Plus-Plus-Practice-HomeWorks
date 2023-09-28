#include <iostream>

using namespace std;

int factorial(int n) {
    cout << "Function Call: factorial: n=" << n << endl;
    if (n == 1)
        return 1;
    return factorial(n - 1) * n;
}

int main() {
    cout << factorial(6) << endl;
    return 0;
}