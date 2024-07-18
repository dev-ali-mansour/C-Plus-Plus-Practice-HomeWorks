#include <iostream>
#include <map>

using namespace std;

class Double {
    double value;

public:
    Double(double val) : value(val) {}

    bool operator==(const Double& other) const {
        return std::abs(value - other.value) < 1e-9;  // Tolerance for floating-point comparison
    }

    bool operator<(const Double& other) const {
        return value < other.value;
    }
};


int main() {
    double d1 = 1 + 3.0 / 7.0 - 1;
    double d2 = 3.0 / 7.0;

    // 0.428571  0.428571    0
    // If gave true, play with similar examples
    cout << d1 << " " << d2 << " " << (d1 == d2) << endl;

    Double cd1(d1);
    Double cd2(d2);

    cout << (cd1 == cd2) << endl;    // true

    map<Double, string> map;
    map[cd1]=10;
    map[cd2] = 20;

    cout << map.size();   // 2

}