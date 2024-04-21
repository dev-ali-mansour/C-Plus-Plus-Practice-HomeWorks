#include <iostream>

using namespace std;

int menu();
void read_2_numbers(double &a, double &b);
void add(double a, double b);
void subtract(double a, double b);
void multiply(double a, double b);
void divide(double a, double b);
void calculator_system();

const int ADD = 1;
const int SUBTRACT = 2;
const int MULTIPLY = 3;
const int DIVIDE = 4;
const int EXIT = 5;


int main() {
    calculator_system();

    return 0;
}

int menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "\nMenu:\n";
        cout << ADD << ") Add 2 numbers\n";
        cout << SUBTRACT << ") Subtract 2 numbers\n";
        cout << MULTIPLY << ") Multiply 2 numbers\n";
        cout << DIVIDE << ") Divide 2 numbers\n";
        cout << EXIT << ") Exit\n";

        cout << "\nEnter your menu choice [1 - 5]: ";
        cin >> choice;
        if (ADD > choice || choice > EXIT) {
            cout << "Invalid choice! Please try again\n";
            choice = -1;   // Loop keep working
        }
    }
    return choice;
}

void read_2_numbers(double &a, double &b) {
    cout << "Enter 2 numbers: ";
    cin >> a >> b;
}

void add(double a, double b) {
    cout << "a + b = " << a + b << endl;
}

void subtract(double a, double b) {
    cout << "a - b = " << a - b << endl;
}

void multiply(double a, double b) {
    cout << "a * b = " << a * b << endl;
}

void divide(double a, double b) {
    if (b != 0)
        cout << "a / b = " << a / b << endl;
    else
        cout << "can't divide by zero!\n";
}

void calculator_system() {
    cout << "Welcome to our simple calculator";
    int total_operations = 0;
    while (true) {
        int choice = menu();
        double a, b;

        if (choice == EXIT)
            break;

        total_operations++;

        read_2_numbers(a, b);

        if (choice == ADD)
            add(a, b);
        else if (choice == SUBTRACT)
            subtract(a, b);
        else if (choice == MULTIPLY)
            multiply(a, b);
        else
            divide(a, b);
    }
    cout << "Total Operations: " << total_operations;
}