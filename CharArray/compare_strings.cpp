#include <iostream>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int size = str1.size();

    if (str2.size() < str1.size())
        size = str2.size();

    int smaller = -1;
    for (int i = 0; smaller == -1 && i < size; ++i) {
        if (str1[i] != str2[i]) {
            if (str1[i] < str2[i]) smaller = 0;
            else smaller = 1;
        }
    }

    if (smaller == -1) {
        if (str1.size() <= str2.size()) smaller = 0;
        else smaller = 1;
    }
    if (smaller == 0) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}