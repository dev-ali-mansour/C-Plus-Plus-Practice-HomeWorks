#include <iostream>

using namespace std;

int main() {
    int i = 1, n, even_count = 0;
    double odd_sum = 0, even_sum = 0;
    cin >> n;
    while (i <= n) {
        int num;
        cin >> num;
        if (i % 2 == 0) {
            even_sum += num;
            even_count++;
        } else {
            odd_sum += num;
        }
        i++;
    }
    double odd_average = odd_sum / (n - even_count);
    double even_average = even_sum / even_count;

    cout << odd_average << " " << even_average << endl;
    return 0;
}