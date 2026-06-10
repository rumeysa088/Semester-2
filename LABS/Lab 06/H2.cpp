#include<iostream>
using namespace std;
class Shape{
public:
    int radius;
};
class Circle:public Shape{
public:
    int area(){return (3.14*radius*radius);}
};
int main(){
   Circle c;c.radius=2;
   cout<<"Area of circle: "<<c.area()<<endl;
}