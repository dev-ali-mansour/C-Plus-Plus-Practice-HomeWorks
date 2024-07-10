#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void div(int x) {
    100000 / x;
}

void array_access(int pos) {
    vector<int> v(5);
    v.at(pos) = 1;    // out_of_range = logic_error
}

double mySqrt(double x) {
    if (x < 0)
        throw domain_error("Sqrt of negative number");
    else return sqrt(x);
}

double myExp(double x) {
    double result = exp(x);
    if (result == HUGE_VAL)
        throw out_of_range("exp too large");
    else return result;
}

void test(double x) {
    try {
        mySqrt(x);
        myExp(x);
        array_access(x);
    } catch (domain_error &e) {
        cout << "Caught DOMAIN exception " << e.what() << endl;   // Invoke correct what
    } catch (logic_error &e) {
        cout << "Caught logical error exception " << e.what() << endl;   // Invoke correct what
    } catch (...) {
        cout << "Catching a lot\n";
        // You can't catch division by zero
        // "low-level events, such as arithmetic overflows and divide by zero,
        // are assumed to be handled by a dedicated lower-level mechanism rather than by exception.
    }
}

int main() {
    test(10);
    test(-4);
    test(100000000);
    test(0);    // Program crash

    return 0;
}