#include <iostream>

using namespace std;

int main() {
    int matrix[100][100];
    int trans[100][100];
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            trans[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << trans[i][j]<<" ";
        }
        cout << endl;
    }


    return 0;
}