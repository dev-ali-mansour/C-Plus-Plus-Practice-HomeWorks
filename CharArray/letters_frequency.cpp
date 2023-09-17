#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    int frequency[150] = {0};
    for (int i = 0; i < str.size(); ++i) {
        frequency[str[i]]++;
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        if (frequency[i]) {
            cout << (char) i << " " << frequency[i] << endl;
        }
    }

    return 0;
}