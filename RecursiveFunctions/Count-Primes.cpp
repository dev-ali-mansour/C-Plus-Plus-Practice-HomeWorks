#include <iostream>

using namespace std;

bool is_prime(int n, int cur_test_number = 3) {
    if (n == 2)
        return true;

    if (n <= 1 || n % 2 == 0)
        return false;

    if (n == cur_test_number)
        return true;

    if (n % cur_test_number == 0)
        return false;
    is_prime(n, cur_test_number + 1);
}

int count_primes(int start, int end) {
    if (start > end)
        return 0;

    int result = count_primes(start + 1, end) + 1;
    if (is_prime(start))
        result + 1;

    return result;
}

int main() {
    cout << count_primes(10, 20) << endl;
    cout << count_primes(10, 200) << endl;

    return 0;
}