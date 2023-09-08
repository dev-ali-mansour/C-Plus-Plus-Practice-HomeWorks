#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T > 0) {
        int n, min = INT32_MAX;
        cin >> n;
        while (n > 0) {
            int num;
            cin >> num;
            if (num < min) min = num;
            n--;
        }
        cout << min << endl;
        T--;
    }
    return 0;
}