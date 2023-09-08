#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    double last3 = num % 1000;
    int x1 = last3 / 100;
    int x2 = (last3 - x1*100) / 10;
    int x3 = last3 - x1*100 - x2*10;
    cout << x1 + x2 + x3;
    return 0;
}