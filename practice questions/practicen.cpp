// #include<iostream>
// using namespace std;
// class shape{
//     int length;
//     int width;
// public:
//   shape(int len,int wid){
//           length=len;
//           width=wid;
//   }
//    void setter(int ulen,int uwid){
//        if(ulen<0 || uwid<0){cout<<"Length or width cant be negative!";return;}
//        length=ulen;
//        width=uwid;
//    }
//    int getLen(){
//      return length;
//    }
//    int getWid(){
//      return width;
//    }
//    void Area(){
//     cout<<"Area of a general shhape";
//    }
// };
// class rectangle : public shape{
//   public:
//    rectancle(){
//       shape(int len,int wid);
//    }
//    void area(){
//       int area=length*width;
//       cout<<"Area is "<<area<<endl;
//    }
// };
// int main(){
//     rectangle r1(10,20);
//     r1.setter(30,20);
//     cout<<"Length"<<r1.getLen()<<endl;
//      cout<<"width"<<r1.getWid()<<endl;
//       cout<<"Area"<<r1.Area()<<endl;
// }
#include<iostream>
using namespace std;
class shape{
      void area(){
        cout<<"area not defined";
      }
};
class circle : public shape{
    int radius;
    public:
    void setR(int r){
        radius=r;
    }
    int getR(){
        return radius;
    }
    void area(){
        int area=3.14*radius*radius;
        cout<<"Area "<<area<<endl;
    }
};
class triangle : public shape{
    int base;int height;
    public:
    void setB(int b,int h){
       base=b;height=h;
    }
   int getB(){
        return base;
    }
    int getH(){
        return height;
    }
    void area(){
        int area=0.5*base*height;
        cout<<"Area "<<area<<endl;
    }
};
int main(){
   circle c1;
   c1.setR(7);c1.area();
   class triangle t1;
   t1.setB(5,10);
   t1.area();
}