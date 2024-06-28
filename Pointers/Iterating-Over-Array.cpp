#include <iostream>

using namespace std;

int main() {
    int arr[]{3, 5, 7, 9};

    int *ptr = arr;

    while (ptr != arr + 4)
        cout << *ptr++ << " ";  // 3 5 7 9
    cout << endl;

    ptr = arr;
    while (ptr != arr + 5)
        cout << *ptr++ << " ";  // 3 5 7 9 -1672933376
    cout << endl;

    return 0;
}