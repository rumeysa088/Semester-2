#include<iostream>
#include<string>
using namespace std;
class SIM{
    string carrier;

    public:
    SIM(){}
    SIM(string c){
        carrier=c;
    }
    void showCarrier(){
         cout<<"Carrier: "<<carrier<<endl;
    };
};
class Mobile{
    string model;
    public:
    SIM s;
    Mobile(string m,string c):s(c){
        model=m;
    }
    void showModel(){
        cout<<"Model: "<<model<<endl;
        s.showCarrier();
    }

};
int main(){
  Mobile m1("A2+","telenor");
  Mobile m2("S24","zong");
  m1.showModel();
  m2.showModel();
}