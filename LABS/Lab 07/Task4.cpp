#include<iostream>
using namespace std;
class Vehicle{
public:
    virtual void startEngine(){cout<< "Vehicle starting..."<<endl;}
};
class Car:public Vehicle{
public:
     void startEngine(){cout<< "Car starting..."<<endl;}
};
class Bike:public Vehicle{
public:
     void startEngine(){cout<< "Bike starting..."<<endl;}
};
class Truck:public Vehicle{
public:
     void startEngine(){cout<< "Truck starting..."<<endl;}
};
int main(){
    Vehicle v;Car c;Bike b;Truck t;
    v.startEngine();
    c.startEngine();
    b.startEngine();
    t.startEngine();
}