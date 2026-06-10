#include <iostream>
using namespace std;
class BankAccount {
private:
    int balance;
    int accountNumber; /*Private members cannot be accessed directly from outside the class.
                        This protects sensitive data from accidental or unauthorized changes.*/
public:
    void setBalance(int b) {
        balance=b;
    }
    void setAccountNumber(int accNo) {
        accountNumber=accNo;
    }
    void showBalance() {
        cout <<"Balance: "<<balance<< endl;
    }
    void showAccountNumber() {
        cout <<"Account Number: "<<accountNumber<< endl;
    }
};
int main() {
    BankAccount acc;

    acc.setAccountNumber(12345);
    acc.setBalance(10000);
    acc.showAccountNumber();
    acc.showBalance();
    return 0;
}
