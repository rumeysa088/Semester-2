#include<iostream>
using namespace std;
class Point{
   public:
   int x,y;
   void print_point(){
     cout<<"("<<x<<","<<y<<")"<<endl;
   }
};
class Shape{
    public:
    int num_points;
    Point *points;
    float get_area;
};
class Triangle: public Shape{
    public:
    float get_area();
    Triangle(){
        num_points=3;
    }
       ~Triangle() {
        delete points;   
    }
    void set_points(Point *p){
        points=p;
    }
    void print_shape(){
        Point* temp=points;
        for(int i=0;i<num_points;i++){
           temp->print_point();
           temp++;
        }
    }

};
void create_triangle(){
    Triangle *t= new Triangle;
    Point p1,p2,p3;
    p1.x=p1.y=0;
    p2.x=p2.y=1;
    p3.x=p3.y=2;
   
    Point *p=new Point[3];
     p[0]=p1;
    p[1]=p2;
     p[2]=p3;
     t->set_points(p);
     t->print_shape();
}
int main(){
  create_triangle();
}