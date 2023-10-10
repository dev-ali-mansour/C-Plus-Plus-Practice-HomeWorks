#include <iostream>

using namespace std;

int count_lowers(const string &str) {
    int cnt = 0;
    for (auto it = str.begin(); it != str.end(); ++it) {
        char ch = *it;
        cnt += (islower(ch) > 0);
    }
    return cnt;
}

int main() {
    string str="My name is Ali";
    cout << "Lower characters: " << count_lowers(str) << endl;

    return 0;
}