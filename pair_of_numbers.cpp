#include <iostream>

using namespace std;

int main() {
    int N, M, SUM;
    cin >> N >> M >> SUM;
    int cnt = 0;
    for (int i = 1; i < N; ++i) {
        int j = SUM - i; //i+j=SUM
        if (1 <= j && j <= M)
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}