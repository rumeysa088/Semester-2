#include<iostream>
using namespace std;

class device{
  string brand;
  float price;
  public:
  device(string b,float p){
    brand=b;price=p;
  }
  void displayInfo(){
    cout<<"Brand: "<<brand<<"Price: "<<price<<endl;
  }
  void specs(){
    cout<<"General device specifications"<<endl;
  }
};
class smartphone :public device{
   int ram;int storage;
   public:
   smartphone(int r,int s,string b,int p):device(b,p){
      ram=r;storage=s;
   }
   void specs(){
     cout<<"RAM: "<<ram<<"Storage"<<storage<<endl;
   }
   void camera(){
    cout<<"Camera: 108 MP";
   }
};
int main(){
 smartphone s1(8,256,"samsung",120000);
//  s1.brand="samsung";s1.price=120000;s1.ram=8;s1.storage=256;
 s1.displayInfo();s1.specs();s1.camera();
}