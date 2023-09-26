#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    cout << abs(-2) << endl;        // 2
    cout << fabs(-2.5) << endl;     // 2.4
    cout << ceil(2.4) << endl;      // 3
    cout << floor(2.4) << endl;     // 2
    cout << round(2.4) << endl;     // 2
    cout << round(2.5) << endl;     // 3
    cout << round(2.6) << endl;     // 3
    cout << round(-2.6) << endl;    // -3
    cout << round(-2.4) << endl;    // -2
    cout << ceil(-2.4) << endl;     // -2   **TRICKY
    cout << floor(-2.4) << endl;    // -3   **TRICKY
    cout << sqrt(16) << endl;       // 4

    return 0;
}