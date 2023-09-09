#include <iostream>

using namespace std;

int main() {
    int N, M, SUM;
    cin >> N >> M >> SUM;
    int cnt = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            if (i + j == SUM) cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}