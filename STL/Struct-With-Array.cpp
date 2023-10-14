#include <iostream>
#include <cassert>

using namespace std;

struct MyArray {
    int salaries[3];
};

int main() {
    int arr[]{1, 2, 3};
    // CE: invalid conversion from 'int*' to 'int'
    // int sal[4]{arr};

    auto salPtr{arr};   // this is a pointer

    MyArray myArr{3, 4, 5};
    auto [actual_aar] = myArr;    // Not a pointer
    assert(typeid(actual_aar) == typeid(myArr.salaries));

    return 0;
}