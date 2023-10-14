#include <iostream>
#include <sstream>      // istringstream

using namespace std;

int main() {
    string str = "Mostufa 23 years";
    istringstream iss(str);

    string name;
    int age;

    iss >> name >> age;

    cout << name << endl;
    cout << age << endl;

    return 0;
}