#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Employee {
public:
    int id;
    int salary;
    string name;

    Employee(int id_, int salary_, string name_) :
            id(id_), salary(salary_), name(name_) {}

    bool operator<(const Employee &c2) {
        return tie(id, salary, name) <
               tie(c2.id, c2.salary, c2.name);
    }

    void print() const {
        cout << id << " " << name << " " << salary << endl;
    }
};

class EmployeeComparatorSalary {
public:
    bool operator()(const Employee &c1, const Employee &c2) {
        return c1.salary < c2.salary;
    }
};

void test1() {
    vector<Employee> emps;

    emps.push_back({9, 500, "Ali"});
    emps.push_back({1, 1000, "Mustafa"});
    emps.push_back({5, 700, "Hani"});

    sort(emps.begin(), emps.end());  // Overloaded <

    for (auto &emp: emps)
        emp.print();
}

void test2() {
    vector<Employee> emps;

    emps.push_back({9, 500, "Ali"});
    emps.push_back({1, 1000, "Mustafa"});
    emps.push_back({5, 700, "Hani"});

    EmployeeComparatorSalary comparator = EmployeeComparatorSalary();
    sort(emps.begin(), emps.end(), comparator);  // Overloaded <

    for (auto &emp: emps)
        emp.print();
}

int main() {
    test1();

    cout << "Sort By Salary\n";
    test2();

    return 0;
}