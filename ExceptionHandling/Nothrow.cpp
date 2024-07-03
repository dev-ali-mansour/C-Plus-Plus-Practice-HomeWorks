#include <iostream>
#include <new>

using namespace std;

int main() {
    int sz = 10;    // Huge enough to take your whole memory

    try {   // Way1)
        int *ptr1 = new int[sz];
        delete[]ptr1;
        ptr1 = nullptr;
    } catch (bad_alloc &ex) {
        cerr << "Failed to allocate memory: " << ex.what() << endl;
    }

    int *ptr2 = new(nothrow)int[sz];    // Way2)
    if (!ptr2) cout << "Failed!\n";
    else {
        cout << "Succeeded!\n";
        delete[]ptr2;
        ptr2 = nullptr;
    }

    return 0;
}