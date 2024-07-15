#include <iostream>
#include <vector>

using namespace std;

vector<int> operator+(vector<int> &c1, vector<int> &c2) {
    if ((int) c1.size() > (int) c2.size()) {
        for (int i = 0; i < (int) c1.size(); ++i)
            c1[i] += c2[i];
        return c1;

    } else {
        for (int i = 0; i < (int) c2.size(); ++i)
            c2[i] += c1[i];
        return c2;
    }
}

int main() {
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {10, 20};

    vector c = a + b;

    for (int i = 0; i < (int) c.size(); ++i) {
        cout << c[i] << " ";    // 11 22 3 4
    }
}