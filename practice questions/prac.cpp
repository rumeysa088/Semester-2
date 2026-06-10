#include<iostream>
#include<cstring>
using namespace std;
class Account{
    public:
    char* name;
    float balance;

    Account(){
        name=nullptr;
        balance=0.0;
    }
    Account(char* n,float bal){
          balance=bal;
          name=new char[strlen(n)+1];
          strcpy(name,n);
    }
    Account(const Account &ac){
           balance=ac.balance; //error
           name=new char[strlen(ac.name)+1];
           strcpy(name,ac.name);
    }
    void display(){
        cout<<"Name: "<<name<<"\nBalance: "<<balance<<endl;
    }
    ~Account(){
        delete[] name;
    }
};
int main(){
  Account a1("Rumaisa",500);
  Account a2=a1;
  a1.display();
  a2.display();
  cout<<"after modification\n";
  a2.balance=90;
  a2.name="Ali";
  a1.display();
  a2.display();

//   Account arr[3];
//   for(int i=0;i<3;i++){
//     arr[i]
//   }
}