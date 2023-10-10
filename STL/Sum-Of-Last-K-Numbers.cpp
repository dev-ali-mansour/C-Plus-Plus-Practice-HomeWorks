#include <iostream>
#include <queue>

using namespace std;

struct last_k_numbers_sum_stream {
    int k, sum = 0;
    queue<int> q;

    last_k_numbers_sum_stream(int _k) {
        k = _k;
    }

    int next(int new_num) {
        q.push(new_num);
        sum += new_num;

        if ((int) q.size() > k) {
            sum -= q.front();
            q.pop();
        }

        return sum;
    }
};

int main() {
    last_k_numbers_sum_stream processor(4);
    int num;
    while (cin >> num)
        cout << processor.next(num) << endl;

    return 0;
}