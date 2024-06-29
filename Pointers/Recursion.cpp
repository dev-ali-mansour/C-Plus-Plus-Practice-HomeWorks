#include <iostream>

using namespace std;

int frecursive1() {
    return frecursive1(); // Infinite recursion leads to stack overflow
}

int frecursive2(int n) {
    int arr[100]{1, 6, 7, 8};
    if (n < 0) return 1;
    return 1 + frecursive2(n - 1);
}

int main() {
    frecursive2(1000000);   // Add too many functions with their details to the stack! leads to stack overflow
    // Avoid recursion in practice :)
    return 0;
}