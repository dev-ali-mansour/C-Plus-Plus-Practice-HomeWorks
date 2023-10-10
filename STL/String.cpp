#include <iostream>
#include <bits/stdc++.h> // Covers all you need typically

using namespace std;

int main() {
    string test = "hi abc abc abc abc";

    cout << test.substr(3) << endl;         // abc abc abc abc
    cout << test.substr(3, 3) << endl;   // abc
    cout << test.find("abc") << endl;        // 3

    // Starting the search at 6th character
    cout << test.find("abc", 5) << endl; // 7

    cout << "ali at: " << test.find("ali") << endl;         // 18446744073709551615
    cout << "ali at: " << (int) test.find("ali") << endl;   // -1

    // Functions that searches for a character from a given string
    cout << test.find_last_of("cab") << endl;           // 17
    cout << test.find_first_of("aic") << endl;          // 1
    cout << test.find_first_of("aic", 4) << endl;  // 5
    cout << test.find_first_not_of("aic") << endl;     // 0

    // replace from 4, 3 chars with x
    test.replace(4, 3, "x");
    cout << test << endl;

    return 0;
}