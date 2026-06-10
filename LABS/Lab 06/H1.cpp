#include<iostream>
using namespace std;
class Vehicle{
public:
    string brand;
    int speed;
    void showVehicle(){
        cout<<"brand: "<<brand<<"\nspeed: "<<speed<<endl;
    }
};
class Car:public Vehicle{
public:
    string fuelType;
    void showCarDetails(){
        cout<<"brand: "<<brand<<"\nspeed: "<<speed<<endl;
        cout<<"fuel type: "<<fuelType<<endl;
    }
};
int main(){
   Car c1;
   c1.brand="Toyota";c1.speed=150;c1.fuelType="petrol";
   c1.showCarDetails();
}