#include <iostream>

using namespace std;

int main() {
    int n;
    char c;
    cin >> n >> c;
    while (n > 0) {
        cout << c;
        n--;
    }

    return 0;
}