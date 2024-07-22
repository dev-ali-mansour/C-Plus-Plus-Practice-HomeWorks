#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>	// iota
using namespace std;

bool is_palindrome(const string& s) {
    return equal(s.begin(), s.end(), s.rbegin());
    //return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

int main() {
    vector<int> v { 1, 3, 2, 6, 3 };

    auto f = [](int i) {return i % 2 == 0;};

    // ALL is even
    bool status = all_of(v.cbegin(), v.cend(), f);	// false
    status = all_of(v.cbegin(), v.cend(), f);	// false
    status = any_of(v.cbegin(), v.cend(), f);	// true
    status = none_of(v.cbegin(), v.cend(), f);	// false

    string source = "1234567890";
    string target;	// 2345

    // copy the first 4 items starting from the beginning
    copy_n(source.begin() + 1, 4, back_inserter(target));

    int a[5] { 0 };
    iota(a, a + 5, 10); // {10,11,12,13,14}

    string letters(26, ' ');	// 26 spaces
    // ABCDEFGHIJKLMNOPQRSTUVWXYZ
    iota(letters.begin(), letters.end(), 'A');

    cout<<is_palindrome("ABA")<<"\n";
    cout<<is_palindrome("ABCA")<<"\n";
    cout<<is_palindrome("AA")<<"\n";

    return 0;
}
