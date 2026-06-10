#include <iostream>
using namespace std;
class Transaction {
protected:
    int accountNumber;
    double amount;
public:
    Transaction(int accNum, double amt) : accountNumber(accNum), amount(amt) {}
    virtual void processTransaction() = 0;
};
class Deposit : public Transaction {
public:
    Deposit(int accNum, double amt) : Transaction(accNum, amt) {}
    void processTransaction() override {
        cout << " Deposit Transaction" << endl;
        cout << "Account: " << accountNumber << "\nAmount: " << amount << endl;
        cout << "Status: Amount Deposited Successfully" << endl << endl;
    }
};
class Withdrawal : public Transaction {
public:
    Withdrawal(int accNum, double amt) : Transaction(accNum, amt) {}
    void processTransaction() override {
        cout << "Withdrawal Transaction" << endl;
        cout << "Account: " << accountNumber << "\nAmount: " << amount << endl;
        cout << "Status: Amount Withdrawn Successfully" << endl << endl;
    }
};
class Transfer : public Transaction {
private:
    int targetAccountNumber;
public:
    Transfer(int accNum, double amt, int targetAcc) : Transaction(accNum, amt), targetAccountNumber(targetAcc) {}
    void processTransaction() override {
        cout << "Transfer Transaction" << endl;
        cout << "From Account: " << accountNumber << "\nTo Account: " << targetAccountNumber << "\nAmount: " << amount << endl;
        cout << "Status: Transfer Completed Successfully" << endl << endl;
    }
};
int main() {
    Deposit acc(1001,5000);
    acc.processTransaction();
    return 0;
}
