#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N > 0) {
        string str;
        cin >> str;
        if (str == "on" || str == "ON" || str == "On" || str == "oN" ||
            str == "no" || str == "NO" || str == "No" || str == "nO")
            cout << str << " ";

        /*if (str.length() == 2) {
            if (((_tolower(str[0]) == _tolower('o') && (tolower(str[1]) == tolower('n'))) ||
                 (_tolower(str[0]) == _tolower('n') && (tolower(str[1]) == tolower('o')))))
                cout << str << " ";
        }*/
        --N;
    }

    return 0;
}