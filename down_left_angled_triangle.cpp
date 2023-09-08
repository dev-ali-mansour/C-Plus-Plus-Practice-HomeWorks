#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        int i = 0;
        while (i < n) {
            cout << "* ";
            i++;
        }
        cout << endl;
        n--;
    }

    return 0;
}