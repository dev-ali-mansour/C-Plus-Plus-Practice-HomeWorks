#include <iostream>

using namespace std;

int main() {
    int arr[]{3, 5, 7, 9};

    int *ptr = arr;
    // 0x6ee1bff960 0x6ee1bff960
    cout << ptr + 0 << " " << &arr[0] << endl;
    // 0x6ee1bff964 0x6ee1bff964
    cout << ptr + 1 << " " << &arr[1] << endl;
    // 0x6ee1bff968 0x6ee1bff968
    cout << ptr + 2 << " " << &arr[2] << endl;
    // 3 3
    cout << *(ptr + 0) << " " << arr[0] << endl;
    // 5 5
    cout << *(ptr + 1) << " " << arr[1] << endl;
    // 7 7
    cout << *(ptr + 2) << " " << arr[2] << endl;
    // 7 7
    cout << *(ptr + 2) << " " << *(arr + 2) << endl;

    // arr[index] = subscript notation
    // *(ptr+2) = offset notation

    // 9 6 BE CAREFUL
    // *ptr + 3 = 3 + 3 = 6 = get the value of current cell and increment 3
    // *(ptr + 3) = move to extra 3 cells then get value
    cout << *(ptr + 3) << " " << *ptr + 3 << endl;

    return 0;
}