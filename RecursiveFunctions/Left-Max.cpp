#include <iostream>

using namespace std;

void left_max(int arr[], int len) {
    if (len == 1)
        return;

    left_max(arr, len - 1);

    arr[len - 1] = max(arr[len - 1], arr[len - 2]);
}

int main() {
    int arr[] = {1, 3, 5, 7, 4, 2};

    left_max(arr, 6);

    for (int i = 0; i < 6; ++i) {
        cout << arr[i] << " ";
    }

}