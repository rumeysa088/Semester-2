#include<iostream>
#include<string>
using namespace std;
class Bank{
    string city;
    string branchcode;
    string supervisor;
    const float interestRate
    static float loan;
public:
    Bank(){}
    Bank(string c,string b,string s,float r):city(c),branchcode(b),supervisor(s),interestRate(r){}
    void issueLoan(customer& c,float amount){if(amount<=c.getincome()){cout<<"Loan granted";loan+=amount;}}
};float Bank::loan=0;
class Customer{
    string firstname;
    string lastname;
    string NIC;
    string address;
    string city;
    float income;
    bool taxFiler;
public:
    Customer(){}
    Customer(string f,string l,string n,string a,string c,float i,bool t):firstname(f),lastname(l),NIC(n),address(a),city(c),income(i),taxFiler(t){}
    float getincome(){return income;}
};

int main(){

}