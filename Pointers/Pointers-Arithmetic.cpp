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

    --ptr;  // Now this is 1 step before array. BE CAREFUL
    //++arr;    CE

    ptr = arr + 3;
    cout << ptr - arr;          // 3 Cells

    ptr = arr;
    cout << ++*ptr << endl;     // get value then increment   4
    cout << ptr - arr << endl;  // 0 still in the same location

    return 0;
}