#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string name;
    string contactInfo;
    string address;

public:
    User() {}
    User(string n, string ci, string a)
        : name(n), contactInfo(ci), address(a) {}

    virtual void display() const = 0; // PURE VIRTUAL

    string getName() const { return name; }
    void updateContact(string ci) { contactInfo = ci; }
    void updateAddress(string a) { address = a; }

    virtual ~User() {}
};

#endif