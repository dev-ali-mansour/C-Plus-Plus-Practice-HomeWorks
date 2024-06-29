#include <iostream>

using namespace std;

int max(int a, int b, int c);
int max(int a, int b, int c, int d);
int max(int a, int b, int c, int d, int e);
int max(int a, int b, int c, int d, int e, int f);

int main() {
    cout << max(5, 10, 6, 22, 30, 50) << endl;
    return 0;
}

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int max(int a, int b, int c, int d) {
    return max(max(a, b, c), d);
}

int max(int a, int b, int c, int d, int e) {
    return max(max(a, b, c, d), e);
}

int max(int a, int b, int c, int d, int e, int f) {
    return max(max(a, b, c, d, e), f);
}