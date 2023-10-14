#include <iostream>
#include <fstream>

using namespace std;

int main() {
    bool append = true;

    auto status = ios::in | ios::out | ios::app;

    if (!append)
        status = ios::in | ios::out | ios::app;      //overwrite

    string path = "/home/alimansour/Training/C++Course/HomeWorks/FilesAndStreams/names.txt";
    fstream file_handler(path.c_str(), status);

    if (file_handler.fail()) {
        cout << "Can't open the file\n";
        return 0;
    }

    string first, second;
    file_handler >> first >> second;
    cout << first << " " << second << endl;

    file_handler.clear();       // if any internal errors before writing

    file_handler << "\nibrahim";
    file_handler.close();

    return 0;
}