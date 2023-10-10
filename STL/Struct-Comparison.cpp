#include <iostream>

using namespace std;

struct employee {
    int num1, num2;
    string str;

    employee(int a, int b, string name) {
        num1 = a, num2 = b, str = name;
    }

    bool operator<(const employee &rhs) const {
        // Compare as we did before
        if (false) {
            if (num1 != rhs.num1)
                return num1 < rhs.num1;

            if (str != rhs.str)
                return str < rhs.str;

            return num2 < rhs.num2;
        }

        // Or use pair
        if (false) {
            return make_pair(num1, make_pair(str, num2))
                   < make_pair(rhs.num1, make_pair(rhs.str, rhs.num2));
        }

        // To use tie: must be variables
        return tie(num1, str, num2) < tie(rhs.num1, rhs.str, rhs.num2);
    }
};
