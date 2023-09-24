#include <iostream>

using namespace std;

int main() {
    int arr[100][100];
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool is_mountain = true; // If no neighbours, will remain true!

            // Check the 8 neighbours using dir array
            for (int d = 0; d < 8 && is_mountain; ++d) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (arr[i][j] <= arr[ni][nj])
                        is_mountain = false;
                }
            }

            if (is_mountain)
                cout << i << " " << j << "\n";
        }
    }

    return 0;
}