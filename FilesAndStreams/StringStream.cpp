#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string str = "Ali 36 years";
    istringstream iss(str);

    string name;
    int age;
    iss >> name >> age;
    cout << age << endl;

    cout << "======================\n";

    ostringstream oss;
    oss << "Ali ";
    oss << 50;
    oss << " years old\n";
    cout << oss.str();

    return 0;
}