#include <iostream>

using namespace std;

int sum1_to_n(int n);

int main() {
    int n;
    cin >> n;

    int result = sum1_to_n(n);
    cout << result << endl;
    return 0;
}

int sum1_to_n(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}