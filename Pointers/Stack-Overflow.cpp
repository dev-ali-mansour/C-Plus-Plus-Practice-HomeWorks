#include <iostream>

using namespace std;

void fun1(int a) {
    int arr[10000 * 10000]; // That will lead to stack overflow
}

int main() {
    fun1(5);

    return 0;
}