#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyMap {
private:
    vector<string> vec_strs;
    vector<int> vec_ints;
    int idx;

    int getIndex(const string str) {
        int pos = -1;
        for (int i = 0; i < (int) vec_strs.size(); ++i) {
            if (vec_strs[i] == str) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            pos++;
            vec_strs.push_back(str);
            vec_ints.push_back(0);
        }
        return pos;
    }

public:
    MyMap() {
        idx = 0;
    }

    int &operator[](const string str) {
        getIndex(str);
        return vec_ints.at(getIndex(str));
    }

    vector<string> operator[](int pos) const {
        vector<string> vec;
        for (int i = 0; i < (int) vec_strs.size(); ++i) {
            if (vec_ints[i] == pos) {
                vec.push_back(vec_strs[i]);
            }
        }
        sort(vec.begin(), vec.end());
        return vec;
    }

    void resetIterator() {
        idx = 0;
    }

    virtual bool hasNext() {
        return idx != vec_strs.size();
    }

    pair<string, int> getNext() {
        idx++;
        return make_pair(vec_strs[idx - 1], vec_ints[idx - 1]);
    }

    void clear() {
        vec_strs.clear();
        vec_ints.clear();
        idx = 0;
    }
};

int main() {
    MyMap map;

    map["mostafa"] = 20;
    map["mostafa"] = 40;
    map["sayed"] = 20;
    map["ali"] = 20;

    cout << map["mostafa"] << endl;    //40

    vector<string> v = map[20];
    for (const auto &s: v)
        cout << s << endl;  // ali  sayed

    map.resetIterator();
    while (map.hasNext()) {
        auto p = map.getNext();
        cout << p.first << " " << p.second << endl;
    }
    map.clear();

    return 0;

}