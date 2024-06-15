#include <iostream>

using namespace std;

int main() {
    int arr[]{3, 5, 7, 9};

    int *ptr = arr;
    cout << *ptr << endl;   // 3

    ++ptr;
    cout << *ptr << endl;   // 5

    cout << *ptr++ << endl;   // 5
    cout << *ptr << endl;   // 7

    cout << *++ptr << endl;   // 9
    cout << *ptr << endl;   // 9

    cout << *--ptr << endl;   // 7
    cout << *ptr << endl;   // 7

    ptr -= 2;     // go back 2 positions
    cout << *ptr << endl;   // 3

    return 0;
}