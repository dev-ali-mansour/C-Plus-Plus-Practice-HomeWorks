#include <iostream>

using namespace std;

void fun1(int &x) {}

void fun2(const int &x) {}

void fun3(int *x) {}

int main() {
    int x = 10;
    int *ptr = &x;

    fun1(x);
    //fun1(ptr);
    fun1(*ptr);
    //fun1(10);

    fun2(x);
    //fun2(ptr);
    fun2(*ptr);
    fun2(10);

    //fun3(x);
    fun3(&x);
    fun3(ptr);
    //fun3(10);

    return 0;
}