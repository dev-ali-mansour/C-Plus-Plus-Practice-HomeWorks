#include <iostream>

using namespace std;

int main() {
    int n, steps = 0;
    cin >> n;

    char arr[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = '.';
        }
    }

    char current = 'o';
    while (true) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        for (int r = 0; r < n; ++r) {
            bool is_same = true;
            for (int c = 1; c < n; ++c) {
                if (arr[r][c] != arr[r][c - 1] || (arr[r][c] == '.' && arr[r][c - 1] == '.')) {
                    is_same = false;
                    break;
                }

            }
            if (is_same) {
                cout << current << " player won!\n";
                return 0;
            }
        }

        for (int c = 0; c < n; ++c) {
            bool is_same = true;
            for (int r = 1; r < n; ++r) {
                if (arr[r][c] != arr[r - 1][c] || (arr[r][c] == '.' && arr[r - 1][c] == '.')) {
                    is_same = false;
                    break;
                }
            }
            if (is_same) {
                cout << current << " player won!\n";
                return 0;
            }
        }

        bool is_same = true;
        for (int i = 1; i < n; ++i) {
            if (arr[i][i] != arr[i - 1][i - 1] || (arr[i][i] == '.' && arr[i - 1][i - 1] == '.')) {
                is_same = false;
                break;
            }
        }
        if (is_same) {
            cout << current << " player won!\n";
            return 0;
        }

        int R = 0, C = n - 1;
        is_same = true;
        while (R < n - 1 && C > 0) {
            if (arr[R][C] != arr[R + 1][C - 1] || (arr[R][C] == '.' && arr[R + 1][C - 1] == '.')) {
                is_same = false;
                break;
            }
            R++;
            C--;
        }
        if (is_same) {
            cout << current << " player won!\n";
            return 0;
        }


        if (steps == n * n) {
            cout << "tie\n";
            return 0;
        }

        if (current == 'x')
            current = 'o';
        else
            current = 'x';

        cout << "Player " << current << " turn. Enter empty location (r,c): ";
        int r, c;

        cin >> r >> c;
        r--, c--;
        while (r > n || c > n || arr[r][c] != '.') {
            cout << "Invalid location! Try again: ";
            cin >> r >> c;
            r--, c--;
        }
        arr[r][c] = current;
        steps++;
    }
}