#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    map<string, vector<string >> mp;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;

        string cur_full_name, str;
        vector<string> names;
        for (int j = 0; j < len; ++j) {
            cin >> str;

            if (j)
                cur_full_name += " ";
            cur_full_name += str;
            names.push_back(cur_full_name);
        }

        for (auto &st: names) {
            mp[st].push_back(cur_full_name);
        }
    }

    int q;
    for (int i = 0; i < q; ++i) {
        int len;
        cin >> len;
        string cur_full_name, str;
        for (int j = 0; j < len; ++j) {
            cin >> str;
            if (j)
                cur_full_name += " ";
            cur_full_name += str;
        }
        if (mp.count(cur_full_name)) {
            for (auto &st: mp[cur_full_name]) {
                cout << st << endl;
            }
        } else
            cout << "No such sub-full name\n";
    }

    return 0;
}