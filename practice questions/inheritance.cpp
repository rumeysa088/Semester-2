#include<iostream>
using namespace std;
class Parent{
    public:
    int x;
    protected:
    int y;
    private:
    int z;
};
class Child: Parent{
       public:
       
       void init(){
        x=10;y=20;
        cout<<"x"<< x<<"y"<<y;
       }
};
int main(){

}