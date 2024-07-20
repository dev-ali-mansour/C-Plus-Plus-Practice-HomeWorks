#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

void test1() {
    int n = 5;
    unique_ptr<int[]> p1{new int[n]};
    unique_ptr<int[]> p2{new int[n]()};
    unique_ptr<int[]> p3 = make_unique<int[]>(n);

    // Always use make_unique
    // Are they the same? No :)
    // p1 created memory and didn't initialize (faster)
    // p2 and p3 initialize to 0 [safer / slower]
    // In practice: stl::vector/array is enough typically

    for (int i = 0; i < n; ++i)
        p1[i] = 7;
}

void test2() {
    // Be careful: Undefined behavior for freeing memory
    unique_ptr<int> p{new int{5}};
    *p = 10;
}

void fastInitialize() {
    int n = 100000;
    unique_ptr<int[]> p1{new int[n]};

    // You can get a pointer array to do fast initialization
    int *p = p1.get();

    // In integers: use memset ONLY with 0 and -1
    memset(p, -1, n * sizeof(int));    // Now arr: -1 -1 -1 -1 -1

    char str[] = "Hello";
    memset(str, 't', sizeof(str));  // ttttt
}

int main() {
    test1();
    test2();
    fastInitialize();

    return 0;
}