#include <iostream>

using namespace std;

struct full_name {
    string first, middle, last;

    void read() {
        cout << "Enter first middle last names: ";
        cin >> first >> middle >> last;
    }
};

struct employee {
    full_name emp_name;
    int age;
    double salary;

    void read() {
        emp_name.read();
        cout << "Enter age and salary: ";
        cin >> age >> salary;
    }

    void print() {
        cout << emp_name.first << " has salary " << salary << endl;
    }
};

int main() {
    employee emp;
    emp.read();
    emp.print();

    return 0;
}