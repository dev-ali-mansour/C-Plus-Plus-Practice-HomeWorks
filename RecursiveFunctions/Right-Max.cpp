#include <iostream>

using namespace std;

void right_max_v1(int arr[], int len, int start_position = 0) {
    if (start_position == len - 1)
        return;

    right_max_v1(arr, len, start_position + 1);

    arr[start_position] = max(arr[start_position], arr[start_position + 1]);
}

void right_max_v2(int arr[], int len) {
    if (len == 1)
        return;

    right_max_v2(arr + 1, len - 1); // arr+1 is the new shifted array. E.g. {1,8,2,10,3}=>{8,2,10,3}

    arr[0] = max(arr[0], arr[1]); // Then We need to think only about arr[0]
}

int main() {
    int arr[] = {1, 3, 5, 7, 4, 2};

    right_max_v1(arr, 6);

    for (int i = 0; i < 6; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}