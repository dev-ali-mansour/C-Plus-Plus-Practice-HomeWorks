#include <iostream>
#include "sum.h"

using namespace std;

// Initializing the extern variable
int total_calls = 0;

int sum_1_n(int n) {
    total_calls++;

    cout << "Total calls " << total_calls << endl;
    int sum = 0;

    for (int i = 0; i < n; ++i)
        sum += i;

    return sum;
}