#include <iostream>

using namespace std;

int main() {
    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << (a + b + c + d + e) / 5.0<<endl;
    cout << (a + b + c) / (d + e)<<endl;
    cout << ((a + b + c) / 3.0) / ((d + e) / 2.0)<<endl;

    return 0;
}