#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<string, vector<string>> mp1;

    string key1 = "ali";
    vector<string> value1 = {"name1", "name2"};
    mp1[key1] = value1;

    string key2 = "john";
    vector<string> value2 = {"hey", "How are you"};
    mp1[key2] = value2;

    for (const auto &pair: mp1) {
        const string &key = pair.first;
        const vector<string> &value = pair.second;
        cout << key << endl;
        // Use them
    }
    // You can remove const from all of them

    return 0;
}