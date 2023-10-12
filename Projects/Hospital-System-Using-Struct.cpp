#include <iostream>
#include <deque>
#include <vector>

using namespace std;
const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;
const int ADD = 1;
const int PRINT = 2;
const int GET = 3;
const int EXIT = 4;

struct hospital_queue {
    // We might use priority_queue<pair<int, string>> que;
    // for direct insert front/back
    // But it is slower + won't allow printing

    deque<pair<string, int>> que;
    int spec;

    hospital_queue() {
        spec = -1;
    }

    hospital_queue(int _spec) {
        spec = _spec;
    }

    bool add_end(string &name, int st) {
        auto item = make_pair(name, st);
        que.push_back(item);
        return true;
    }

    bool add_front(string &name, int st) {
        auto item = make_pair(name, st);
        que.push_front(item);
        return true;
    }

    void remove_front() {
        if (que.empty()) {
            cout << "No patients at the moment. Have rest, Dr\n";
            return;
        }
        auto item = que.front();
        que.pop_front();
        cout << item.first << " Please go with the Dr\n";
    }

    void print() {
        if (que.empty()) return;
        cout << "There are " << que.size() << " patients in specialization " << spec << endl;
        for (auto &item: que) {
            cout << item.first << " ";
            if (item.second)
                cout << "urgent\n";
            else cout << "regular\n";
        }
        cout << endl;
    }
};

struct hospital_system {
    vector<hospital_queue> queues;

    hospital_system() {
        queues = vector<hospital_queue>(MAX_SPECIALIZATION);

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

    bool add_patient() {
        int spec, st;
        string name;
        cout << "Enter specialization, names, and status: ";
        cin >> spec >> name >> st;

        if (queues[spec].que.size() == MAX_QUEUE) {
            cout << "Sorry We can't add more patients for this specialization.\n";
            return false;
        }
        if (st == 0)
            queues[spec].add_end(name, st);
        else
            queues[spec].add_front(name, st);
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