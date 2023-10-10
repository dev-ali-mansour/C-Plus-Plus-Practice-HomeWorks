#include <iostream>
#include <set>

using namespace std;

void print(multiset<string> &v) {
    for (string x: v)
        cout << x << " ";
    cout << endl;
}

int main() {
    multiset<string> strSet;  // Sorted & can repeat
    strSet.insert("ziad");
    strSet.insert("mostufa");
    strSet.insert("mostufa");
    strSet.insert("mostufa");
    strSet.insert("ali");


    print(strSet); // ali mostufa mostufa mostufa ziad

    if (strSet.count("mostufa"))
        cout << "YES\n";

//    set<string >::iterator it = strSet.find("mostufa");
    auto it = strSet.find("mostufa");

    if (it != strSet.end())
        strSet.erase(it);

    print(strSet); //ali mostufa mostufa ziad

    return 0;
}