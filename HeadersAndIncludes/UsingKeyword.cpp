#include <iostream>

using namespace std;

namespace Customer {
    int first = 1, second = 2;
}

namespace Admin {
    int total = 5;
}

//Let first be visible through the whole file
using Customer::first;

int main() {
    // Easier for repetitive usage
    // But be careful of local collisions
    cout << first << endl;
    cout << first << endl;

    // second is NOT visible
//    cout<<second<<endl;
//    cout<<second<<endl;

    // Let totla be visible through the function
    using Admin::total;
    cout << total << endl;

    return 0;
}