#include<iostream>
using namespace std;
class Device{
public:
    void powerOn(){cout<<"Device Power ON"<<endl;}
};
class Computer:public Device{
public:
    void processData(){cout<<"Computer Processing Data"<<endl;}
};
class Network{
public:
    void connectNetwork(){cout<<"Connected to Network"<<endl;}
};
class Server:public Computer,public Network{
public:
    void hostWebsite(){cout<<"Server Hosting Website"<<endl;}
};
int main(){
Server s;
s.powerOn();
s.processData();
s.connectNetwork();
s.hostWebsite();
return 0;
}