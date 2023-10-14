#include<iostream>

using namespace std;

int main() {
    freopen("/home/alimansour/Training/C++Course/HomeWorks/FilesAndStreams/read_file.txt", "rt", stdin);

    int x, y;
    cin >> x >> y;

    cout << x + y;

    return 0;
}