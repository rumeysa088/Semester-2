#include<iostream>
using namespace std;
class Vehicle{
   public:
   int speed;
   void showSpeed(){
        cout<<"Speed : "<<speed<<endl;
   }
};
class car: public Vehicle{
    public:
     void fuelType(){
        cout<<"Fuel type: Petrol";
     }
};
int main(){
    car c1;
   c1.speed=70;
   c1.showSpeed();
   c1.fuelType();
}