#include <iostream>

using namespace std;

#ifndef HOMEWORKS_INVOICE_H
#define HOMEWORKS_INVOICE_H


class Invoice {
private:
    string name;
    int itemNumber;
    double price;
    int quantity;

public:
    Invoice();
    Invoice(string &name, int itemNumber, double price, int quantity);

    const string &getName() const;

    void setName(const string &name);

    int getItemNumber() const;

    void setItemNumber(int itemNumber);

    double getPrice() const;

    void setPrice(double price);

    int getQuantity() const;

    void setQuantity(int quantity);

    double getTotalPrice() const;

    void print();
};

#endif //HOMEWORKS_INVOICE_H
