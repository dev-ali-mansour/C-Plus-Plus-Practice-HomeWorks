#include <iostream>
#include <map>
#include <vector>

using namespace std;

void print(const map<string, int> &mp) {
    // You can iterate on map and set normally like vector
//    for (const pair<string, int> &item: mp)
    for (const auto &item: mp)
        cout << item.first << "-" << item.second << " | ";
    cout << endl;
}

int main() {
    map<string, int> mp;    // Array with index not integer
    mp["mostufa"] = 10;
    mp["Saad"] = 20;
    mp["mostufa"] = 30;
    mp["Mostufa"] = 40;
    mp["Ali"] = 50;

    print(mp);      // Ali-50 | Mostufa-40 | Saad-20 | mostufa-30 |

    auto it = mp.find("Saad");

    if (it != mp.end())
        mp.erase(it);

    print(mp);      // Ali-50 | Mostufa-40 | mostufa-30 |

    map<char, vector<int>> my_data;
    vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);

    my_data['A'] = x;
    x.push_back(4);

    cout << my_data['A'].size() << endl;  // 3
    cout << x.size() << endl;             // 4    (2 copies)

    vector<int> x2 = my_data['A'];        // 3rd copy
    vector<int> &x3 = my_data['A'];       // The same memory

    return 0;
}