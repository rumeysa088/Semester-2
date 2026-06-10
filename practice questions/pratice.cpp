#include<iostream>
using namespace std;

class BankAccount{
    
  
    float balance;
    public:
    int accountNumber;
    string owner;
    BankAccount(float bal){
        if(bal>=0){balance=bal;}
        else{balance=0;cout<<"Balance cant be negative"<<endl;}
    }
    void deposit(int money){
        if(money>0){balance+=money;cout<<"Deposit successfull!"<<endl;}
        else{cout<<"Error!"<<endl;}
    }
   void withdraw(int amount){
    if(amount <= 0){
        cout << "Invalid amount!" << endl;
        return;
    }
    if(amount <= balance){
        balance -= amount;
        cout << "Withdrawal successful!" << endl;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}

   
};
int main(){
 BankAccount b(2000);
 b.deposit(500);
 b.withdraw(3000);
 b.withdraw(500);


return 0;
}