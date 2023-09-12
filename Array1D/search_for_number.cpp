#include <iostream>

using namespace std;

int main() {
    const int N = 500 + 1;
    int n, q, x, ans[N];

    for (int i = 0; i < N; ++i)
        ans[i] = -1;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ans[x] = i;
    }

    int num;
    cin >> q;
    while (q--) {
        cin >> num;
        cout << ans[num] << endl;
    }

    return 0;
}