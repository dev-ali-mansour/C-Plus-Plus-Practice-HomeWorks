#include <iostream>

using namespace std;

int sum_array(int arr[], int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << sum_array(arr, 3) << endl;
    cout << sum_array(arr, 6) << endl;

    return 0;
}