#include <memory>
#include <iostream>

using namespace std;

void print1(unique_ptr<int> p) {      // Pass by value
    if (p != nullptr)
        cout << *p << endl;
}

void print2(unique_ptr<int> &p) {      // Pass by reference
    if (p != nullptr) {
        cout << *p << endl;
        // They can destroy your pointer! Be careful
        p.reset();
    }
}

void print3(const unique_ptr<int> &p) {       // Pass by reference
    if (p != nullptr) {
        cout << *p << endl;
        *p = 10;    // Value can be changed
        //unique_ptr<int> &p2 = p;
        //p.reset(new int{7});
        // Good: No one can store or play with it
    }
}

int main() {
    unique_ptr<int> p1{new int{20}};    // Direct initialization

    unique_ptr<int> &p2 = p1;       // Alias Ok: still one owner

    //print1(p2);     // Use of deleted copy constructor
    print1(std::move(p2));  // Ok, pass it BUT don't use it after return

    p2.reset(new int{30});
    print2(p2);     // Perfect pass it, Then you can use it after return
    //print2(std::move(p2));    // CE: temporary object to non const reference
    print3(std::move(p2));  //Ok now: const reference


    return 0;
}