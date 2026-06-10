#include<iostream>
using namespace std;
class Driver {
public:
    void drive() { cout << "Driving the vehicle..." 
        << endl; }
};
class Mechanic {
public:
    void repair(){cout<<"Repairing the vehicle..." 
        << endl; }
};
class Technician:public Driver,public Mechanic {
};
int main() {
    Technician t;
    t.drive();  
    t.repair(); 
    return 0;
}