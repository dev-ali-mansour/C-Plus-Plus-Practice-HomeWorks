#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    int q;
    cin >> q;
    for (int x = 0; x < q; ++x) {
        int i, j, r, c;
        cin >> i >> j >> r >> c;

        int count = 0;
        for (int k = 0; k < r; ++k) {
            for (int l = 0; l < c; ++l) {
                bool is_prime = true;
                int val = arr[i + k][j + l];
                if (val <= 1)
                    is_prime = false;
                for (int ix = 2; ix < val / 2; ++ix) {
                    if (val % ix == 0)
                        is_prime = false;
                }
                if (is_prime)
                    count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}