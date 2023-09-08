#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N > 0) {
        string str;
        cin >> str;
        int length = str.length();
        if (length == 2) {
            while (length > 0) {
                if (((_tolower(str[0]) == _tolower('o') && (tolower(str[1]) == tolower('n'))) ||
                     (_tolower(str[0]) == _tolower('n') && (tolower(str[1]) == tolower('o')))))
                    cout << str << " ";
                length--;
            }
        }
        N--;
    }

    return 0;
}