#include<iostream>
using namespace std;
class Shape{
public:
    void Draw(){cout<< "Drawing Shape..."<<endl;}
};
class Circle:public Shape{
public:
    void Draw(){cout<< "Drawing Circle..."<<endl;}
};
class Rectangle:public Shape{
public:
    void Draw(){cout<< "Drawing Rectangle..."<<endl;}
};
int main(){
    Shape s; Circle c; Rectangle r;
    s.Draw(); c.Draw(); r.Draw();
}