#include<iostream>
#include<string>
using namespace std;


class Rectangle{
     int length;
     int width;

     public:
     Rectangle(){
        length=1;
        width=1;
     }
     Rectangle(int l,int w){
        length=l;
        width=w;
     }
     void area(int length,int width){
        int area=length*width;
        cout<<"area is "<<area<<endl;
     }
     int getL(){
        return length;
     }
     int getW(){
        return width;
     }
};
int main(){
    Rectangle r1(3,4);
    int length=r1.getL();
    int width=r1.getW();
    r1.area(length,width);
    return 0;
}