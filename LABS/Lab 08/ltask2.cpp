#include<iostream>
using namespace std;
class Engine{
    int horsepower;
public:
    Engine(int h):horsepower(h){}
    friend class Mechanic;
};
class Mechanic{
public:
    void showHP(Engine e){ cout<<"Horse Power: "<<e.horsepower<<endl;}
    void upgradeHP(Engine& e,int a){ if( e.horsepower+a>=100 && e.horsepower+a<=1000) 
        {e.horsepower+=a;}}
};
int main(){
    Engine e(520);
    Mechanic m;
    m.showHP(e);
    m.upgradeHP(e,40);
    m.showHP(e);
}