#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ostringstream oss;

    oss << "Mostufa ";
    oss << 50;
    oss << " years old\n";

    cout << oss.str();

    return 0;
}