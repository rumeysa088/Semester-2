#include<iostream>
#include<string>
using namespace std;

class Rectangle{
   int length;
   int breadth;
   int area;

public:
    Rectangle(){ length=1; breadth=1; }
    Rectangle(int len,int bred):length(len),breadth(bred){};

    void setlen(int len){length=len;}
    void setbred(int bred){breadth=bred;}

    void getArea(){ cout<<"Area: "<<length*breadth<<endl;}

    ~Rectangle(){cout<<"Rectangle Destroyed"<<endl;}
};
int main(){

    Rectangle r1;
    Rectangle r2(4,6);
    r1.setlen(2);
    r1.setbred(4);
    r1.getArea();
    r2.getArea();
    return 0;
}