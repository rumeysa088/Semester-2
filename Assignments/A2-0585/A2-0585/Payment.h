#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>
using namespace std;

class Payment {
protected:
    string paymentID;
    int amount;

public:
    Payment() {}
    Payment(string id,int amt):paymentID(id),amount(amt){}

    virtual void processPayment() const = 0; // PURE VIRTUAL

    int getAmount() const { return amount; }

    virtual ~Payment() {}
};

#endif