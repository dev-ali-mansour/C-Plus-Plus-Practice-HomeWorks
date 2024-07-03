#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int>v(10);

    // Wrong but it may not crash
    int t = v[25];
    cout<<t<<endl;

    // at validates and throws out_of_range exception
    t=v.at(25);
    cout<<"bye";    // Won't be displayed

    return 0;
}