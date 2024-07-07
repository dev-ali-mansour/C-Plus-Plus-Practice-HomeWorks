#include <iostream>
#include "Rectangle.h"

using namespace std;


int main() {
    Rectangle r1;
    r1.setWidth(5);
    r1.setHeight(10);
    cout << r1.computeArea() << endl;   // 50

    Rectangle r2(10, 3);
    cout << r2.computeArea() << endl;   // 30
    r2.setWidth(0);
    cout << r2.computeArea() << endl;   // 0


    return 0;
}