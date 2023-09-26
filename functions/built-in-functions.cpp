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

    cout << isalpha('A') << endl;               // 1024 = true
    cout << isalpha('#') << endl;               // 0
    cout << isdigit('3') << endl;               // 1 = true
    cout << isdigit('A') << endl;               // 0
    cout << isupper('A') << endl;               // 256 = true
    cout << isupper('a') << endl;               // 0
    cout << (char) tolower('X') << endl;      // x
    cout << (char) toupper('x') << endl;      // X

    cout << max(5, 9) << endl;                       // 9
    cout << pow(2, 4) << endl;                  // 16
    cout << pow(2, 4.1) << endl;                // 17.1484
    cout << log2(16) << endl;                    // 4
    cout << log10(1000) << endl;                 // 3

    cout << (double) rand() / RAND_MAX << endl;     //0.840188


    return 0;
}