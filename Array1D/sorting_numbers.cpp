#include <iostream>
#include <cassert>

using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAX = 900 + 1;
    int frequency[MAX] = {0};
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        assert(0 <= value && value <= 500);
        frequency[value]++;
    }

    for (int i = 0; i <= 500; ++i) {
        while (frequency[i]){
            cout<<i<<" ";
            --frequency[i];
        }
    }

    return 0;
}