#include <iostream>

using namespace std;

const int MAX = 10000;
string names[MAX];
int ages[MAX];
double salaries[MAX];
char genders[MAX];
int added = 0; // Number of employees

int menu() {
    cout << "Enter your choice:\n";
    cout << "1) Add a new employee\n";
    cout << "2) Print all employees\n";
    cout << "3) Delete by age\n";
    cout << "4) Update salary by name\n";

    int choice = -1;
    cin >> choice;

    while (choice < 1 || choice > 4) {
        cout << "Invalid choice! Try again\n";
    }

    return choice;
}

void read_employee() {
    cout << "Enter name: ";
    cin >> names[added];
    cout << "Enter age: ";
    cin >> ages[added];
    cout << "Enter salary: ";
    cin >> salaries[added];
    cout << "Enter gender(M/F): ";
    cin >> genders[added];
    ++added;
    cout << endl;
}

void print_employees() {
    for (int i = 0; i < added; ++i) {
        if (ages[i] != -1)
            cout << names[i] << " " << ages[i] << " " << salaries[i] << " " << genders[i] << "\n";
    }
    cout << endl;
}

void delete_by_age() {
    cout << "Enter start and end age: ";
    int start, end;
    cin >> start >> end;
    for (int i = 0; i < added; ++i) {
        if (ages[i] >= start && ages[i] <= end) {
            ages[i] = -1; // Let's mark a removed entry with -1 (lazy delete)
        }
    }
}

void update_salary_by_name() {
    cout << "Enter the name and salary: ";
    string name;
    double salary;
    cin >> name >> salary;
    bool is_found = false;
    for (int i = 0; i < added; ++i) {
        if (names[i] == name && ages[i] != -1) {
            salaries[i] = salary;
            is_found = true;
            break;
        }
    }
    if (!is_found)
        cout << "No employee with this name!";
    cout << endl;
}

void employee_system() {
    while (true) {
        int choice = menu();

        if (choice == 1)
            read_employee();
        else if (choice == 2)
            print_employees();
        else if (choice == 3)
            delete_by_age();
        else
            update_salary_by_name();
    }
}

int main() {
    employee_system();

    return 0;
}