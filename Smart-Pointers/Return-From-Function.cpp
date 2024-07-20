#include <memory>
#include <iostream>

using namespace std;

unique_ptr<int> getInstance() {
    unique_ptr<int> p{new int{20}};
    return p;
}

int main() {
    unique_ptr<int> x = getInstance();     // Moving object

    cout << *x << endl;

    return 0;
}