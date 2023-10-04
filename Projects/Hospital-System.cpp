#include <iostream>

using namespace std;
const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;
const int ADD = 1;
const int PRINT = 2;
const int GET = 3;
const int EXIT = 4;

string names[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1];
int status[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1]; // 0 regular, 1 urgent
int queue_length[MAX_SPECIALIZATION]; // For each specialization, how many patients so far

int menu() {
    int choice;
    cout << "\nEnter your choice\n";
    cout << ADD << ")Add new patient\n";
    cout << PRINT << ")Print all patients\n";
    cout << GET << ")Get next patient\n";
    cout << EXIT << ")Exit\n";
    cin >> choice;

    return choice;
}

// Move each patient to the left. E.g. if patient in position 5, it will be in 4.
// Help in removing a patient.
void shift_left(int spec, string names_sp[], int status_sp[]) {
    int len = queue_length[spec];
    for (int i = 1; i < len; ++i) {
        names_sp[i - 1] = names_sp[i];
        status_sp[i - 1] = status_sp[i];
    }
    queue_length[spec]--;
}

//Move each patient to the right. E.g. if patient in position 5, it will be in 6.
// Helps in adding a patient.
void shift_right(int spec, string names_sp[], int status_sp[]) { // Critical to start from the end
    int len = queue_length[spec];
    for (int i = len - 1; i >= 0; --i) {
        names_sp[i + 1] = names_sp[i];
        status_sp[i + 1] = status_sp[i];
    }
    queue_length[spec]++;
}

bool add_patient() {
    int spec, st;
    string name;
    cout << "Enter specialization, names, and status: ";
    cin >> spec >> name >> st;
    int pos = queue_length[spec];
    if (pos >= MAX_QUEUE) {
        cout << "Sorry We can't add more patients for this specialization.\n";
        return false;
    }
    if (st == 0) {
        names[spec][pos] = name;
        status[spec][pos] = st;
        queue_length[spec]++;
    } else {
        // Urgent, add to begin. shift, then add
        shift_right(spec, names[spec], status[spec]);
        names[spec][0] = name;
        status[spec][0] = st;
    }

    return true;
}

void print_patients() {
    for (int i = 0; i < 20; ++i) {
        int len = queue_length[i];
        if (len > 0) {
            cout << "There are " << len << " patients in specialization " << i << endl;
            for (int j = 0; j < len; ++j) {
                cout << names[i][j] << " ";
                if (status[i][j] == 0)
                    cout << "regular\n";
                else cout << "urgent\n";
            }
            cout << endl;
        }
    }
}

void get_next_patient() {
    int spec;
    cout << "Enter specialization: ";
    cin >> spec;

    int len = queue_length[spec];
    if (len == 0) {
        cout << "No patients at the moment. Have rest, Dr\n";
        return;
    }

    cout << names[spec][0] << " Please go with the Dr\n";
    //Delete the patient in position 0
    shift_left(spec, names[spec], status[spec]);
}

void hospital_system() {
    while (true) {
        int choice = menu();

        if (ADD > choice || choice > EXIT) {
            cout << "Invalid choice! Please try again\n";
            continue;
        }
        if (choice == ADD)
            add_patient();
        else if (choice == PRINT)
            print_patients();
        else if (choice == GET)
            get_next_patient();
        else
            break;
    }
}

int main() {
    hospital_system();

    return 0;
}