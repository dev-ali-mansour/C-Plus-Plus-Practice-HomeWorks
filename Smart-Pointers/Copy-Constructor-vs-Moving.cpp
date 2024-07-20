#include <memory>   // Smart Pointers
#include <iostream>

using namespace std;

void test() {
    unique_ptr<int> p1{new int{20}};

    // CE: Use of deleting copy constructor
    // unique_ptr<int> p2{p1};

    // We can't use copy constructor,
    // But we can move p1 internals to p2
    // Useful for function calls in some scenarios
    unique_ptr<int> p2{std::move(p1)};
    // Now don't use p1 anymore. Another pointer has ownership.

    if (p1 == nullptr)
        cout << "Yeah\n";     // Yeah

    //Force delete
    p2 = nullptr;    // Exception in assignment
    p2.reset();     // Also set to nullptr
}

int main() {

}