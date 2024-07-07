#include "Invoice.h"

Invoice::Invoice() {
    Invoice::name = "";
    Invoice::itemNumber = 0;
    Invoice::price = 0;
    Invoice::quantity = 0;
}

Invoice::Invoice(string &name, int itemNumber, double price, int quantity) {
    Invoice::name = name;
    Invoice::itemNumber = itemNumber;
    Invoice::price = price;
    Invoice::quantity = quantity;
}

const string &Invoice::getName() const {
    return name;
}

void Invoice::setName(const string &name) {
    Invoice::name = name;
}

int Invoice::getItemNumber() const {
    return itemNumber;
}

void Invoice::setItemNumber(int itemNumber) {
    Invoice::itemNumber = itemNumber;
}

double Invoice::getPrice() const {
    return price;
}

void Invoice::setPrice(double price) {
    Invoice::price = price;
}

int Invoice::getQuantity() const {
    return quantity;
}

void Invoice::setQuantity(int quantity) {
    Invoice::quantity = quantity;
}

double Invoice::getTotalPrice() const {
    return Invoice::price * Invoice::quantity;
}

void Invoice::print() {
    cout << Invoice::name << ", " << Invoice::itemNumber << ", "
         << Invoice::price << ", " << Invoice::quantity << ", "
         << Invoice::getTotalPrice() << endl;
}