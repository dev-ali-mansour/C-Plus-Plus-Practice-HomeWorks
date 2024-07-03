#include <iostream>     // cout
#include <cmath>        // sqrt
#include <vector>       // vector

using namespace std;

int sum_1_n(int n) {
    int sum = 0;

    for (int i = 0; i < n; ++i)
        sum += i;

    return sum;
}

int main() {
    cout << sqrt(25) << endl;
    vector<int> v;

    cout << sum_1_n(5) << endl;

    return 0;
}