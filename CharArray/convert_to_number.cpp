#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    int number = 0;
    for (int i = 0; i < (int) str.size(); ++i) {
        number = number * 10 + (str[i] - '0');
    }

    cout << number << " " << number * 3 << endl;
    return 0;
}