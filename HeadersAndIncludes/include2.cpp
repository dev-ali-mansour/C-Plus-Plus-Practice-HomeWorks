#include <iostream>     // cout
#include "sum.h"        // sum_1_n   NOT <

//#include "sum.h"      // sum_1_n
// error: redefinition of 'int sum_1_n(int n)'

using namespace std;

int main() {
    cout << sum_1_n(5) << endl; // 10

    return 0;
}