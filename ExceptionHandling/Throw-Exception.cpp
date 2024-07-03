#include <iostream>

using namespace std;

struct BankAccount {
    int money = 1000;

    bool PayBill(int bill_value) {
        if (bill_value < 0)
            throw invalid_argument("Bill value can't be negative!");
        if (money >= bill_value) {
            money -= bill_value;
            return true;
        } else return false;
    }
};

int main() {
    BankAccount acct;
    cout<<acct.PayBill(100)<<endl;
    cout<<acct.PayBill(500000)<<endl;
    cout<<acct.PayBill(-10)<<endl;
    cout<<acct.PayBill(200)<<endl;  // Won't be processed

    return 0;
}