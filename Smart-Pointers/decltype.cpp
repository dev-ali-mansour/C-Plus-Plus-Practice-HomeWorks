#include <functional>

using namespace std;

double f() {
    auto b = 1.5; //dDouble
    return b;
}

void test1() {
    double i = 10.2;
    double j1 = i * 2;  //20.4
    decltype(i) j2 = i * 2; // j2 is double

    // decltype(f()) = double
    decltype(f()) j3;
    j3 = 3;

    function<double()> f1 = f;
    decltype(&f) f2 = f;
    double t = f2();
}