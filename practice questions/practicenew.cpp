#include<iostream>
using namespace std;
class account{
    double balance;

public: 
        void setBalance(double ubalance){
            if(ubalance<0)cout<<"Balance cant be negative!";
             balance=ubalance;
        }
        double getBalance(){
            return balance;
        }
    virtual void displayInfo(){
        cout<<" Account Balance"<<balance<<endl;
    }
};
class savingAccount : public account{
   double interestRate;

public:
   
  void setinterestRate(double uinterestRate){
             
             interestRate=uinterestRate;
        }
        double getinterestRate(){
            return interestRate;
        }

    void displayInfo(){
        cout<<"\nSaving Account Balance"<<getBalance()<<"\nInterest Rate: "<<interestRate<<endl;
    };
};
int main(){
  savingAccount s1;
  s1.setBalance(5000);
  s1.setinterestRate(5);
  s1.displayInfo();
}