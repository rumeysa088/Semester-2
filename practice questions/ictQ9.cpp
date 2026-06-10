#include<iostream>
using namespace std;
class shape{
   public:

   virtual void area(){
     cout<<"Area of shape: "<<endl;
   }
};
class rectangle:public shape{
     public: 
     int length;
     int width;

     void area(){
        int area=length*width;
        cout<<"Area of shape: "<<area<<endl;
     }
};
int main(){
   rectangle r1;
   r1.length=5;
   r1.width=7;
   r1.area();
}