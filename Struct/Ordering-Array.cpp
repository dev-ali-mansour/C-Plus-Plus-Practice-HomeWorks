#include <iostream>
#include <algorithm>

using namespace std;

struct employee {
    string name;
    int age;
    double salary;
    char gender;

    void read_employee() {
        cout << "Enter employee 4 entries: ";
        cin >> name >> age >> salary >> gender;
    }

    void print_employee() {
        cout << name << " has salary " << salary << endl;
    }

    int get_age() {
        return age;
    }

    void set_age(int new_age) {
        age = new_age;
    }
};

const int MAX = 10000;
employee employees_arr[MAX];

int added = 0; // Number of employees

void print_employees() {
    cout << "******************\n";
    for (int i = 0; i < added; ++i) {
        employees_arr[i].print_employee();
    }
}

bool compare_name(employee &a, employee &b) {
    return a.name < b.name; //Smaller name first
}

bool compare_salary(employee &a, employee &b) {
    return a.salary > b.salary; // bigger salary first
}

bool compare_name_salary(employee &a, employee &b) {
    // smaller name first, if tie smaller salary
    if (a.name != b.name)
        return a.name < b.name;
    return a.salary < b.salary;
}

int main() {
    int arr[5] = {5, 1, 2, 3, 4};
    sort(arr, arr + 5);

    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " ";
    cout << endl;

    employees_arr[added++].read_employee();
    employees_arr[added++].read_employee();
    employees_arr[added++].read_employee();

    sort(employees_arr, employees_arr + added, compare_name);
    print_employees();

    sort(employees_arr, employees_arr + added, compare_salary);
    print_employees();

    sort(employees_arr, employees_arr + added, compare_name_salary);
    print_employees();

    return 0;
}