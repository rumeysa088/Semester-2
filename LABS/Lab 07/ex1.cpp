#include<iostream>
using namespace std;
class Calculator{
public:
    int multiply(int a,int b){ return a*b;}
    int multiply(int a,int b,int c){return a*b*c;}
    double multiply(double c,double d){return c*d;}
};
int main(){
    Calculator c;
    cout<<c.multiply(4,3)<<endl;
    cout<<c.multiply(4,3,2)<<endl;
    cout<<c.multiply(4.6,3.3)<<endl;
}