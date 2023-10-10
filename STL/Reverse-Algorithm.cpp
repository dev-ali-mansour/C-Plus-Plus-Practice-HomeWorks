#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> &v) {
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v(5);

    for (int i = 0; i < (int) v.size(); ++i) {
        v[i] = 10 - i;
    }

    print(v); // 10 9 8 7 6

    reverse(v.begin(), v.end());
    print(v); //6 7 8 9 10

    v.clear(); // now array is empty

    return 0;
}