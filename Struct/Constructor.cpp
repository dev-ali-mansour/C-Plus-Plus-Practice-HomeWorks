#include <iostream>

using namespace std;

struct full_name {
    string first, middle, last;

    full_name() {
        // Empty constructor. Better always provide it.
        first = middle = last = "";
    }

    full_name(string _first, string _last = "") {
        first = _first;
        last = _last;
        middle = "";
    }

    void read() {
        cout << "Enter first middle last names: ";
        cin >> first >> middle >> last;
    }
};

int main() {
    full_name my_name = full_name("ali");
    cout << my_name.first << endl;

    full_name his_name = full_name("Ali", "Mansour");
    cout << his_name.last << endl;
    return 0;
}