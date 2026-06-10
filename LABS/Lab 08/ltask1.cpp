#include<iostream>
using namespace std;
class Rectangle{
    int length;
    int width;
public:
    Rectangle(int l,int w){
        if(l>0 && w>0){length=l;width=w;}
    else{length=0;width=0;}}
   friend void calc(Rectangle obj);
};
void calc(Rectangle obj){ 
    cout<<"Area: "<<obj.length*obj.width<<"\nPerimeter: "<<(2*obj.length)+(2*obj.width)<<endl;
}
int main(){
    int l;int p;
    cout<<"Enter length and width: ";
    cin>>l;cin>>p;
    Rectangle r(l,p);
    calc(r);
}