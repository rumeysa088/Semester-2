#include<iostream>
using namespace std;
class Appliance {
protected: string brand;
public:
    void setBrand(string b) {brand = b;}
    void showBrand() {cout << "Brand: " << brand << endl;}
};
class WashingMachine : public Appliance {
public:
    void wash() {cout << "Washing clothes..." << endl;}
};
class SmartWashingMachine : public WashingMachine {
public:
    void smartControl() {cout << "Controlling washing machine thru mobile app..." << endl;}
};
int main() {
    SmartWashingMachine swm;
    swm.setBrand("Samsung");
    swm.showBrand();
    swm.wash();
    swm.smartControl();
    return 0;
}