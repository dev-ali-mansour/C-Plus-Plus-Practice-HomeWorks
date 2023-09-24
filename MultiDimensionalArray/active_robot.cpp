#include <iostream>

using namespace std;

int main() {
    int n, m, k, r = 0, c = 0;

    cin >> n >> m >> k;

    // Direction from 1 to 4: up, right, down, left
    while (k--) {
        int dir, steps;
        cin >> dir >> steps;
        if (dir < 1 || dir > 4) {
            cout << "Invalid direction!\n";
            return 0;
        }

        if (dir == 1) {
            int mv = r - steps;
            if (mv < 0 || mv > n)
                r = n + mv;
            else r = mv;
        } else if (dir == 2) {
            int mv = c + steps;
            if (mv > m)
                c = mv % m;
            else c = mv;
        } else if (dir == 3) {
            int mv = r + steps;
            if (mv > n)
                r = mv % n;
            else r = mv;
        } else {
            int mv = c - steps;
            if (mv < 0 || mv > m)
                c = m + mv;
            else c = mv;
        }

        cout << "(" << r << ", " << c << ")\n";
    }

    return 0;
}