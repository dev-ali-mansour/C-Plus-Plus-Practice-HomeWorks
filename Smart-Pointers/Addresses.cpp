#include <memory>   // Smart Pointers
#include <iostream>

using namespace std;

void test() {
    unique_ptr<int> p{new int{20}};

    // p is an object, So it has its own address
    // Inside it a row pointer
    // The raw pointer itself has an address
    // The raw pointer points to an address

    // Now we have 3 addresses
    int *raw_p = p.get();   // NOT ->

    // 20 0x2572f705b60 0xf4b85ff6a0 0xf4b85ff6a8
    cout << *raw_p << " " << raw_p << " " << &raw_p << " " << &p << endl;
    // std::addressof(p) btw same as &p
}

int main() {
    test();

    return 0;
}