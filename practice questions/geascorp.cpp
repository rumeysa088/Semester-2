// #include<iostream>
// #include<string>
// using namespace std;
// class Customer{
//     string firstname;
//     string lastname;
//     string address;
// };
// class Robot{
//     int id;
//     int size;
//     string color;
//     float price;
// public:
//    Robot(){}
//    Robot(int id,int size,string color,float p=5000){this->id=id;this->size=size;this->color=color;price=p;}
// };
// class GeasCorp{
// public:
//     void takeOrder(Customer& c){ 
//         string color;
//         cout<<"Give color: "<<endl;
//         cin>>color;
//         Robot r(001,32,color);
//         cout<<"Order Taken..."<<endl;
//     }
// };


// int main(){
//    Customer c;
//    GeasCorp g;
//    g.takeOrder(c);
// }
#include <iostream>
#include <string>
using namespace std;

class Customer {
    string firstName;
    string lastName;
    string address;

public:
    Customer(string f, string l, string a)
        : firstName(f), lastName(l), address(a) {}

    void display() {
        cout << "Customer: " << firstName << " "
             << lastName << endl;
        cout << "Address: " << address << endl;
    }
};


class Robot {
    int id;
    int size;       // in ft
    string color;
    double price;

public:
    Robot() {}

    Robot(int i, int s, string c)
        : id(i), size(s), color(c), price(5000) {}

    void display() {
        cout << "Robot ID: " << id << endl;
        cout << "Size: " << size << " ft" << endl;
        cout << "Color: " << color << endl;
        cout << "Price: PKR " << price << endl;
    }
};


class GeassCorp {
public:
    Robot takeOrder(Customer &c) {

        string color;
        cout << "Enter desired color: ";
        cin >> color;

        Robot r(1, 32, color);   // sample robot

        cout << "\nOrder taken successfully!" << endl;
        cout << "Delivering robot to customer...\n" << endl;

        c.display();
        r.display();

        return r;   // deliver robot
    }
};


int main() {

    Customer c("Lelouch", "Vi Britannia",
               "Street 2, Area 11");

    GeassCorp g;

    Robot deliveredRobot = g.takeOrder(c);

    return 0;
}