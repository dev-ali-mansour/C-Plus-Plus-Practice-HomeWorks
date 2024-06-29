#include <iostream>
#include <vector>

using namespace std;

struct Employee {
    int id;
    string name;

    Employee(int num, string str) {
        id = num, name = str;
    }

    Employee() {
        id = -1;
        name = "";
    }

    void print() {
        cout << id << " " << name << endl;
    }
};

int main() {
    Employee e1(10, "mostafa");
    e1.print();     // 10 mostafa

    //int *x{new int(50)};
    Employee *e2{new Employee(20, "belal")};
    e2->print();    // 20 belal

    Employee *e3 = new Employee();
    (*e3).print();  // -1

    Employee *e4 = e2;
    Employee *e5{&e1};

    Employee &e6 = *e2;
    e2->id = 111;
    e6.print();     // 111 belal

    vector<Employee *> vec;
    vec.push_back(e2);
    vec.push_back(&e6);

    // delete ONLY the "new" created
    delete e2;
    delete e3;
    e2 = e3 = nullptr;

    return 0;
}