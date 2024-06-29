#include <iostream>

using namespace std;

int main() {
    int arr[]{3, 5, 7, 9};
    // value of arr is the address of the first element
    cout << arr << endl;    // 0xccbbff700

    int &val = arr[0];

    cout << val << " " << &val << endl; // 3 0xccbbff700
    cout << &arr[0] << endl;    // 0xccbbff700

    int *ptr = arr;
    // also the value of ptr is an address

    cout << *ptr << " " << ptr << " " << &ptr << endl;  // 3 0xccbbff700 0xccbbff6f0


    // Point to array: You can use it as same as array
    ptr[0] = 10, ptr[1] = 20;

    for (auto &item: arr) {
        cout << item << " ";
    }
    cout << endl; // 10 20 7 9


    return 0;
}