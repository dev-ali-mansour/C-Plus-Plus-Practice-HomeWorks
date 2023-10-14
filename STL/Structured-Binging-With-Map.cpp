#include <iostream>
#include <map>

using namespace std;

int main() {
    multimap<int, int> mp1;  // before c++11
    mp1.insert(pair<int, int>(1, 40));
    mp1.insert(pair<int, int>(1, 50));
    mp1.insert(pair<int, int>(1, 60));

    multimap<int, int> mp2{{1, 40},
                           {1, 50},
                           {3, 60}};

    for (const auto &[key, value]: mp2)
        cout << key << " " << value << endl;

    // return pair of iterators
    auto [it_start, it_end] = mp2.equal_range(1);

    for (auto it = it_start; it !=it_end ; ++it) {
    cout<<it->first<<" "<<it->second<<endl;
    //  1 40    1 50
    }
    return 0;
}