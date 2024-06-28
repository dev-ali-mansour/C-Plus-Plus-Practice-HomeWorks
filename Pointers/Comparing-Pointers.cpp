#include <iostream>

using namespace std;

int main() {
    string str1 = "mostufa";
    string str2 = "mostufa";

    cout << (str1 == str2) << endl; // 1 (true)

    string *p1 = &str1;
    string *p2{&str2};  // C++ Style

    // BE CAREFUL: Do you want to compare the values or the addresses?
    cout << (p1 == p2) << endl; // 0 (false)
    cout<< (*p1 == *p2) << endl; // 1 (true)

    return 0;
}