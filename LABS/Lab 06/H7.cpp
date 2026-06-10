#include<iostream>
using namespace std;
class BankAccount{
public:
    int balance=10000;
    void showBalance(){cout<<"Balance: "<<balance<<endl;}
};
class SavingsAccount:private BankAccount{
public:
    void display(){
        cout<<"Accessing inside derived class:"<<endl;
        cout<<"Balance: "<<balance<<endl;
        showBalance();
    }
};
int main(){
    SavingsAccount s;
    s.display();   // Accessible (through public function)
    // s.balance;        // cant do
    // s.showBalance();  // cant do
    return 0;
}