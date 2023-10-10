#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print(set<string> &v) {
    for (const string &x: v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    set<string> strSet; //Sorted & Unique
    strSet.insert("ziad");
    strSet.insert("mostufa");
    strSet.insert("mostufa");
    strSet.insert("mostufa");
    strSet.insert("ali");

    print(strSet); // ali mostufa ziad

    if (strSet.count("mostufa"))
        cout << "YES\n";

//    set<string >::iterator it = strSet.find("mostufa");
    auto it = strSet.find("mostufa");

    if (it != strSet.end())
        strSet.erase(it);

    print(strSet); //ali ziad

    return 0;
}