#include <iostream>
#include "Invoice.h"

using namespace std;

int main() {
    string name="Ali Mansour";
    Invoice inv(name,1,1500.50,3);
    inv.print();

    return 0;
}