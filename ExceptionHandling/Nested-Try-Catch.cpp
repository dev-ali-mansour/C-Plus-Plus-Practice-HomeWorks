#include <iostream>

using namespace std;

int main() {
    try {
        try {
            throw 17;
        } catch (int n) {
            cout << "Oh exception ";
            throw;
        }
    } catch (int n) {
        cout << "Got it";
    }

    return 0;
}