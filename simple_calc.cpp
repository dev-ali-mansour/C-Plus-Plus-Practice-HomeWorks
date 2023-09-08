#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char op;
    cin >> num1 >> op >> num2;

    if (op == '+')
        cout << num1 + num2;
    else if (op == '-')
        cout << num1 - num2;
    else if (op == '*')
        cout << num1 * num2;
    else if (op == '/')
        cout << num1 / num2;
    return 0;
}