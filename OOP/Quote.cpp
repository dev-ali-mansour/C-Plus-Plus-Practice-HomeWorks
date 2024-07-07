#include <iostream>

using namespace std;

class Quote {
private:
    int internal;

    string GetQuote() {
        return "The way to get started is to quit talking and begin doing";
    }

public:
    int external;

    Quote() {
        internal = 3, external = 7;
    }

    void print() {
        cout << GetQuote();
    }
};

int main() {
    Quote q;
    cout << q.external << endl;
    q.print();

    //q.internal;     // Can't access
    //q.GetQuote();   // Can't call

    return 0;
}