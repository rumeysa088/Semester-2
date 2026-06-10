#include<iostream>
using namespace std;
class GMS{
    const int ID;
    string name;
    int sessions;
    static int membersRegistered;
    static int totalSessions;
    static int nextID;
public:
   
    GMS(string n,int s):ID(nextID++),name(n),sessions(s){ membersRegistered++;totalSessions+=sessions;}
    void displayMember(){
        cout<<"ID: "<<ID<<"\nName: "<<name<<"\nSessions: "<<sessions<<endl;
    }
    int getSessions()const{ return sessions;}
    static void displayStats(){
        cout<<"Members Registered: "<<membersRegistered<<"\nTotal Sessions: "<<totalSessions<<endl;
    }
};
int GMS::membersRegistered=0;
int GMS::totalSessions=0;
int GMS::nextID=100;
int main(){
    string n;int s;
  
  GMS arr[3] = {
    GMS("Sara Ali",5),
    GMS("Omar Shah",3),
    GMS("Aisha Khan",4)
};
    for(int i=0;i<3;i++){
        arr[i].displayMember();
    }
    GMS::displayStats();
}


#include<iostream>
using namespace std;
class Menu{
    string name;
    float price;
public:
    Menu(){}
    Menu(string n,float p):name(n),price(p){}
    float getPrice(){return price;}
    void displayItem(){
        cout<<"Item: "<<name<<"\nPrice: "<<price<<endl;
    }
};
class Order{
    int orderID;
    Menu items[3];
    int itemCount=0;
public:
    Order(){}
    Order(int i):orderID(i){}
    void addItem(string n,float p){ 
        if(itemCount<3){
        items[itemCount]=Menu(n,p) ; 
        itemCount++;}
    }
    float CalcOrderTotal(){ float total=0;
        for(int i=0;i<itemCount;i++){
             total+=items[i].getPrice();
        }
        return total;
    }
    void displayOrder(){ cout<<"ID: "<<orderID<<endl;
        for(int i=0;i<itemCount;i++){
           items[i].displayItem();
        }
    }
};
class Table{
    int tableNo;
    Order arr[4];
    int CurrentOrders=0;
public:
    Table(int n):tableNo(n){}
    void addOrder(Order o){
        if(CurrentOrders < 4){
        arr[CurrentOrders] = o;
        CurrentOrders++;
    }
    }
    float totalBill(){ float bill=0;
        for(int i=0;i<CurrentOrders;i++){
            bill+=arr[i].CalcOrderTotal();
        } return bill;
    }
    void displayTable(){
        cout<<"Table No: "<<tableNo<<endl;
        for(int i=0;i<CurrentOrders;i++){
            arr[i].displayOrder();
        }
        cout<<"Total Bill: "<<totalBill()<<"$"<<endl;
    }
};
int main(){
  Table t1(1);
  Order o1(101);
  Order o2(102);
  o1.addItem("Burger",12.5);
  o1.addItem("Fries",4.0);
  o2.addItem("Pizza",18.0);
  t1.addOrder(o1);
  t1.addOrder(o2);
  t1.displayTable();
}

#include<iostream>
using namespace std;

class Device{
protected:
    string deviceName;
    float powerRating;
    float usageHour;
public:
    Device(){}
    Device(string n,float p,float u):deviceName(n),powerRating(p),usageHour(u){}

    float calculateEnergy(){
        return (powerRating * usageHour) / 1000; // kWh
    }

    void display(){
        cout<<deviceName<<": "<<powerRating<<"W, "<<usageHour<<" hours/day"<<endl;
    }

    float getEnergy(){
        return calculateEnergy();
    }
};

// Discount class
class Discount{
protected:
    float discountPercentage;
public:
    Discount(){
        discountPercentage = 15; // 15%
    }

    float applyDiscount(float totalCost){
        return totalCost * (1 - discountPercentage/100);
    }
};

// EntertainmentRoom
class EntertainmentRoom: public Device, public Discount{
    int deviceCount;
    Device devices[5];

public:
    EntertainmentRoom(){
        deviceCount = 0;
    }

    void addDevice(Device d){
        if(deviceCount < 5){
            devices[deviceCount] = d;
            deviceCount++;
        }
    }

    float calcTotalEnergy(){
        float energy = 0.0;
        for(int i=0;i<deviceCount;i++){
            energy += devices[i].getEnergy();
        }
        return energy;
    }

    int findHighestEdevice(){
        float maxEnergy = 0;
        int index = 0;

        for(int i=0;i<deviceCount;i++){
            if(devices[i].getEnergy() > maxEnergy){
                maxEnergy = devices[i].getEnergy();
                index = i;
            }
        }
        return index;
    }

    void displayEnergySummary(){
        cout<<"Entertainment Room Devices:"<<endl;

        for(int i=0;i<deviceCount;i++){
            devices[i].display();
        }

        float totalEnergy = calcTotalEnergy();
        cout<<"Total Energy Consumption: "<<totalEnergy<<" kWh"<<endl;

        float totalCost = totalEnergy * 0.15;
        cout<<"Total Cost before discount: $"<<totalCost<<endl;

        float finalCost = applyDiscount(totalCost);
        cout<<"Total Cost after discount: $"<<finalCost<<endl;

        int idx = findHighestEdevice();
        cout<<"Highest Energy Consuming Device: ";
        devices[idx].display();
    }
};

int main(){
    EntertainmentRoom room;

    room.addDevice(Device("TV",100,6));
    room.addDevice(Device("Gaming Console",200,4));
    room.addDevice(Device("Sound System",150,5));

    room.displayEnergySummary();

    return 0;
}