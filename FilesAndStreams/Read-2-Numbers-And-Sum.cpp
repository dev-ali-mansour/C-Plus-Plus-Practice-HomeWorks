#include<iostream>

using namespace std;

int main() {
    freopen(R"(D:\Developing\Projects\C++\HomeWorks\FilesAndStreams\read_file.txt)", "rt", stdin);

    int x, y;
    cin >> x >> y;

    cout << x + y;

    return 0;
}