#include<iostream>
using namespace std;
class Account {
protected:
    int accountNumber;
public:
    void setAccountNumber(int accNo) {accountNumber = accNo;}
    void showAccount() {cout << "Account Number: " << accountNumber << endl;}
};
class SavingsAccount : public Account {
public:
    void calculateInterest(double balance) {
        double interest = balance * 0.05;   // 5% interest
        cout << "Interest: " << interest << endl;
    }
};
class CurrentAccount : public Account {
public:
    void calculateOverdraft(double amount) {cout << "Overdraft Facility Used: " << amount << endl;}
};
int main() {
    SavingsAccount s;
    CurrentAccount c;
    s.setAccountNumber(101);
    c.setAccountNumber(202);
    cout << "Savings Account Details:" << endl;
    s.showAccount();
    s.calculateInterest(10000);
    cout << "\nCurrent Account Details:" << endl;
    c.showAccount();
    c.calculateOverdraft(5000);
    return 0;
}