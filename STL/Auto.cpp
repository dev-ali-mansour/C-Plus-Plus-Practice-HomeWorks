#include <iostream>

void what_is_auto() {
    int x = 10;
    auto x2=10;                     // C++ deduces int
    auto x3=10.0;           // double
    auto x4= "Ali";     // string
    // There are more details. This is good for now.
    // Auto: No conversions / clean code
}