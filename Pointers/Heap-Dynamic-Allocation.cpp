#include <iostream>

using namespace std;

int *fun(int n) {
    int *ptr1 = new int[n]{1, 3, 5, 7, 9};
    int *ptr2 = new int[7]{1, 3, 5, 7, 9, 10, 11};

    // ptr1 and ptr2: local variables in the stack
    // consecutive in memory

    // allocated data where ptr1/ptr2 points in the HEAP
    // ptr1 and ptr2 may not have sequential addresses

    delete[]ptr2;
    // The memory is "returned" to the heap to REUSE

    return ptr1;    // Ok to return. not on stack. no destroying
}

int main() {
    int *p = fun(10);
    delete[]p;  // managed by yourself

    return 0;
}