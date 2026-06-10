#include<iostream>
using namespace std;
class Calculator{
public:
    void Area(int side){ cout<<"Area of square: "<<4*side<<endl;}
    void Area(int length,int width){cout<<"Area of Rectangle: "<<length*width<<endl;}
    void Area(double radius){cout<<"Area of Circle: "<<3.14*radius*radius<<endl;}
};
int main(){
    Calculator c;
    c.Area(4);
    c.Area(4,3);
    c.Area(2.6);
}