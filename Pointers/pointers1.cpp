#include <iostream>

using namespace std;

int main() {
    int val = 15;
    int &ref = val;

    //  15 0x297e1ff9b4
    cout << val << " " << &val << endl;
    //  15 0x297e1ff9b4
    cout << ref << " " << &ref << endl;

    int *ptr = &val;
    //  15 0x297e1ff9b4 0x297e1ff9a8
    cout << *ptr << " " << ptr << " " << &ptr << endl;

    *ptr = 20;
    //  20 20 20
    cout << val << " " << ref << " " << *ptr << endl;

    int another = 30;
    //  30 0x27c3bff8e4
    cout << another << " " << &another << endl;

    ptr = &another;
    //  30 0x27c3bff8e4 0x27c3bff8e8
    cout << *ptr << " " << ptr << " " << &ptr << endl;

    *ptr = 50;
    //  20 50 50
    cout << val << " " << another << " " << *ptr << endl;

    ptr= nullptr;

    if (!ptr)cout<<"NULL\n"; // NULL

    //Pointer Initialization
    double x=10;
    double *ptr1=&x;
    //double *ptr2=NULL;  // C-Style - OK
    //C++11
    double *ptr2=nullptr;   //Petter (Preferred)
    double *ptr3=0;         //Ok also nullptr
    //double *ptre=1;       //CE: 0 or address

    double *ptr4;           // Garbage - Don't

    return 0;
}