#include <iostream>
#include <vector>

using namespace std;

class Address {
private:
    string name;
    string address;
    string city;

public:
    const string &getName() const {
        return name;
    }

    void setName(const string &name_) {
        this->name = name_;
    }

    const string &getAddress() const {
        return address;
    }

    void setAddress(const string &address_) {
        this->address = address_;
    }

    const string &getCity() const {
        return city;
    }

    void setCity(const string &city_) {
        this->city = city_;
    }
};

class Package {
public:
    virtual double getTotalCost() const = 0;

    virtual ~Package() {}
};

class StandardPackage : public Package {
private:
    Address senderAddress;
    Address receiverAddress;
    double weightKg;
    double pricePerKg;

public:
    StandardPackage(const Address &senderAddress, const Address &receiverAddress, double weightKg, double pricePerKg) :
            senderAddress(senderAddress), receiverAddress(receiverAddress), weightKg(weightKg), pricePerKg(pricePerKg) {
    }

    double getTotalCost() const override {
        return weightKg * pricePerKg;
    }

    const Address &getSenderAddress() const {
        return senderAddress;
    }

    void setSenderAddress(const Address &senderAddress) {
        this->senderAddress = senderAddress;
    }

    const Address &getReceiverAddress() const {
        return receiverAddress;
    }

    void setReceiverAddress(const Address &receiverAddress) {
        this->receiverAddress = receiverAddress;
    }

    double getWeightKg() const {
        return weightKg;
    }

    void setWeightKg(double weightKg) {
        this->weightKg = weightKg;
    }

    double getPricePerKg() const {
        return pricePerKg;
    }

    void setPricePerKg(double pricePerKg) {
        this->pricePerKg = pricePerKg;
    }
};

class TwoDayPackage : public StandardPackage {
private:
    double fixedFee;

public:
    TwoDayPackage(const Address &senderAddress, const Address &receiverAddress, double weightKg, double pricePerKg,
                  double fixedFee) :
            StandardPackage(senderAddress, receiverAddress, weightKg, pricePerKg), fixedFee(fixedFee) {
    }

    double getTotalCost() const override {
        return StandardPackage::getTotalCost() + fixedFee;
    }

    double getFixedFee() const {
        return fixedFee;
    }

    void setFixedFee(double fixedFee_) {
        this->fixedFee = fixedFee_;
    }
};

class HeavyPackage : public StandardPackage {
private:
    const double limitKg = 100;
    double extraPricePerKg;

public:
    HeavyPackage(const Address &senderAddress, const Address &receiverAddress, double weightKg, double pricePerKg,
                 double extraPricePerKg) :
            StandardPackage(senderAddress, receiverAddress, weightKg, pricePerKg), extraPricePerKg(extraPricePerKg) {
    }

    double getTotalCost() const override {
        double cost = StandardPackage::getTotalCost();
        if (getWeightKg() > limitKg)
            cost += (getWeightKg() - limitKg) * extraPricePerKg;
        return cost;
    }

    double getExtraPricePerKg() const {
        return extraPricePerKg;
    }

    void setExtraPricePerKg(double extraPricePerKg_) {
        this->extraPricePerKg = extraPricePerKg_;
    }
};

class PaymentCard {
private:
    string cardNumber;
    double expiryDate;
};

class CreditCard : public PaymentCard {
};

class DebitCard : public PaymentCard {
};

class Shipment {
private:
    vector<Package *> packages;
    PaymentCard *paymentCard;

public:
    void addPackage(StandardPackage *package) {
        packages.push_back(package);
    }

    void setPaymentCard(PaymentCard *paymentCard_) {
        this->paymentCard = paymentCard_;
    }

    double getTotalCost() const {
        double cost = 0;
        for (auto package: packages)
            cost += package->getTotalCost();
        return cost;
    }
};

class Customer {
private:
    vector<Shipment *> shipments;
    vector<PaymentCard *> paymentCards;

public:
    void addShipment() {}

    void addPaymentCard() {}
};


int main() {


    return 0;
}