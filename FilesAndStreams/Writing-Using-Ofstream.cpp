#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin(R"(D:\Developing\Projects\C++\HomeWorks\FilesAndStreams\read_file.txt)");
    if (fin.fail()) {
        cout << "Can't open the file\n";
        return 0;
    }
    int x, y;
    fin >> x >> y;
    fin.close();

    ofstream fout(R"(D:\Developing\Projects\C++\HomeWorks\FilesAndStreams\my_output.txt)");

    if (fout.fail()) {
        cout << "Can't open the output file\n";
        return 0;
    }
    fout << x + y;
    fout.close();

    return 0;
}