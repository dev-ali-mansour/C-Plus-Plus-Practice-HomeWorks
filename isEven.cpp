#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    cout << "is even1 =" << (num % 2 == 0) << endl;
    cout << "is even2 =" << (num - (num / 2) * 2 == 0) << endl;
    cout << "is even3 =" << (num % 10 == 0 || num % 10 == 2 || num % 10 == 4 || num % 10 == 6 || num % 10 == 8);
    return 0;
}