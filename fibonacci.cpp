#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0, b = 1;
    cout << a << " " << b<<" ";

    for (int cnt = 2; cnt < n; ++cnt) {
        int c = a + b;
        a = b;
        b = c;
        cout << c << " ";
    }
    return 0;
}