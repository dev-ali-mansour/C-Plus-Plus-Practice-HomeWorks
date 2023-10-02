#include <iostream>

using namespace std;

bool is_palindrome_v1(int arr[], int start, int end) {
    if (start >= end)
        return true;

    if (arr[start] != arr[end])
        return false;
    is_palindrome_v1(arr, start + 1, end - 1);
}

bool is_palindrome_v2(int arr[], int end) {
    if (end <= 0)
        return true;

    if (arr[0] != arr[end])
        return false;
    is_palindrome_v2(arr + 1, end - 2);
}

bool is_palindrome_v3(int arr[], int len, int start = 0) {
    if (start == len - 1)
        return true;

    if (arr[start] != arr[len - start - 1])
        return false;
    is_palindrome_v3(arr, len, start + 1);
}

int main() {
    int arr[] = {1, 2, 3, 3, 2, 1};

    cout << is_palindrome_v1(arr, 0, 5) << endl;
    cout << is_palindrome_v2(arr, 5) << endl;
    cout << is_palindrome_v3(arr, 6) << endl;

    return 0;
}