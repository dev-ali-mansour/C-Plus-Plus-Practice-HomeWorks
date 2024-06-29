#include <iostream>

using namespace std;

int main() {
    int val1 = 20;
    int val2 = 30;

    // The data type is const int, So pointer must be const int*
    const int val3 = 40;

    // 1) Pointer to constant
    const int *ptr1 = &val1;
    //     *ptr1 = 20;    CAN'T change data it points to

    // But can change the pointer value itself.
    // Notice also val3 is const int.
    ptr1 = &val3;

    // 2) Constant pointers
    int *const ptr2 = &val2;
    *ptr2 = 50; // Can change data it points to
//    ptr2 = &val2;  CAN'T change pointer value itself

    // 3) Constant pointer to constant
    const int *const ptr4 = &val1;
    // *ptr4 = 10;    CAN'T change data it points to
    // ptr4 = &val3;  CAN'T change pointer value itself

    return 0;
}