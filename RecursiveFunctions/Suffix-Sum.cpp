#include <iostream>

using namespace std;

int suffix_sum(int arr[], int len, int cnt) {
    if (cnt == 0)
        return 0;

    return arr[len - 1] + suffix_sum(arr, len - 1, cnt - 1);
}

int main() {
    int arr[] = {1, 8, 2, 10, 3};

    cout << suffix_sum(arr, 5, 3) << endl;

    return 0;
}