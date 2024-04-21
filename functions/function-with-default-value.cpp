#include <iostream>

using namespace std;

int power(int n, int p = 3);

int main() {
    cout << power(2) << endl;
    cout << power(2, 3) << endl;
    cout << power(2, 4) << endl;

    return 0;
}

int power(int n, int p) {
    int result = 1;
    while (p--) {
        result *= n;
    }
    return result;
}
