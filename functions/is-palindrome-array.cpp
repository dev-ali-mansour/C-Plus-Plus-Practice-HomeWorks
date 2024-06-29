#include <iostream>

using namespace std;

int read_array(int arr[]);
bool is_palindrome(int n, const int arr[]);

int main() {
    int arr[100];
    int len = read_array(arr);

    if (is_palindrome(len, arr))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

int read_array(int arr[]) {
    int len;
    cin >> len;

    for (int i = 0; i < len; ++i)
        cin >> arr[i];

    return len;
}

bool is_palindrome(int n, const int arr[]) {
    for (int i = 0; i < n / 2; ++i) {
        if (arr[i] != arr[n - 1 - i]) {
            return false;
        }
    }

    return true;
}