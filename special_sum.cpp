#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T > 0) {
        int N;
        cin >> N;
        int cnt_N = 1, sum = 0;
        while (cnt_N <= N) {
            int value;
            cin >> value;
            int cnt_deep = cnt_N;
            int result = 1;
            while (cnt_deep > 0) {
                result *= value;
                cnt_deep--;
            }
            sum += result;
            cnt_N++;
        }
        cout << sum << "\n";
        T--;
    }

    return 0;
}