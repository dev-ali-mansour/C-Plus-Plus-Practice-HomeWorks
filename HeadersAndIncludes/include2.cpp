#include <iostream>     // cout
#include "sum.h"        // sum_1_n   NOT <

//#include "sum.h"      // sum_1_n
// error: redefinition of 'int sum_1_n(int n)'

using namespace std;

int main() {
    for (int i = 0; i < 3; ++i)
        sum_1_n(10);

    total_calls+=100;

    for (int i = 0; i < 3; ++i)
        sum_1_n(10);

    return 0;
}