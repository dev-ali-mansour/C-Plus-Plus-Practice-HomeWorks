#include <iostream>

using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE]{0};

    int n = 20; // NOT const
    int *pArr = new int[n];

    for (int i = 0; i < n; ++i)
        pArr[i] = i;

    for (int i = 0; i < n; ++i)
        cout << pArr[i] << " ";
    cout << endl;


    delete[]pArr;   // free the array

    // Wrong and will compile
    //delete pArr;

    return 0;
}