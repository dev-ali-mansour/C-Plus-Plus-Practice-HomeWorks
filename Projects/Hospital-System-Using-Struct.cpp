#include <iostream>

using namespace std;
const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;
const int ADD = 1;
const int PRINT = 2;
const int GET = 3;
const int EXIT = 4;

struct hospital_queue {
    string names[MAX_QUEUE];
    int status[MAX_QUEUE];
    int len;
    int spec;

    hospital_queue() {
        len = 0;
        spec = -1;
    }

    hospital_queue(int _spec) {
        len = 0;
        spec = _spec;
    }

    bool add_end(string name, int st) {
        if (len == MAX_QUEUE)
            return false;
        names[len] = name, status[len] = st, ++len;
        return true;
    }

    bool add_front(string name, int st) {
        if (len == MAX_QUEUE)
            return false;

        // Shift right
        for (int i = len; i > 0; --i) {
            names[i] = names[i - 1];
            status[i] = status[i - 1];
        }
        names[0] = name, status[0] = st, ++len;
        return true;
    }

    void remove_front() {
        if (len == 0) {
            cout << "No patients at the moment. Have rest, Dr\n";
            return;
        }
        cout << names[0] << " Please go with the Dr\n";

        // Shift left
        for (int i = 0; i < len; ++i) {
            names[i] = names[i + 1];
            status[i] = status[i + 1];
        }
        --len;
    }

    void print() {
        if (len == 0) return;
        cout << "There are " << len << " patients in specialization " << spec << endl;
        for (int i = 0; i < len; ++i) {
            cout << names[i] << " ";
            if (status[i])
                cout << "urgent\n";
            else cout << "regular\n";
        }
        cout << endl;
    }

};

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


struct hospital_system {
    hospital_queue queues[MAX_SPECIALIZATION];

    hospital_system() {
        for (int i = 0; i < MAX_SPECIALIZATION; ++i) {
            queues[i] = hospital_queue(i);
        }
    }

    void run() {
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


    bool add_patient() {
        int spec, st;
        string name;
        cout << "Enter specialization, names, and status: ";
        cin >> spec >> name >> st;

        bool status;
        if (st == 0)
            status = queues[spec].add_end(name, st);
        else
            status = queues[spec].add_front(name, st);

        if (!status) {
            cout << "Sorry We can't add more patients for this specialization.\n";
            return false;
        }

        return true;
    }

    void print_patients() {
        cout << "*******************************\n";
        for (int spec = 0; spec < MAX_SPECIALIZATION; ++spec)
            queues[spec].print();
    }

    void get_next_patient() {
        int spec;
        cout << "Enter specialization: ";
        cin >> spec;
        queues[spec].remove_front();
    }
};


int main() {
    hospital_system system;
    system.run();

    return 0;
}