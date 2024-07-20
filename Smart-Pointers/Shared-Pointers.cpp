#include <iostream>
#include <memory>

using namespace std;

void test() {
    shared_ptr<int> p1{new int{20}};

    //shared_ptr<int> p1 = new int{20};   // CE
    //p1 = new int{30};     // CE

    shared_ptr<int> p2{p1};  // Copy constructor ok

    shared_ptr<int> p3;
    p3 = p2;                  // Assignment ok
    *p1 = 5;

    // 5 5 5: Same value
    cout << *p1 << " " << *p2 << " " << *p3 << endl;

    auto p4=make_shared<int>(20);   // Preferred
}