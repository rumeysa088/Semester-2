#include<iostream>
using namespace std;
template <class T>
class Calculator{
    T a;
    T b;
public:
    Calculator(T x,T y):a(x),b(y){}
    T add(){ return a+b;}
    T subtract(){ return a-b;}
    T multiply(){ return a*b;}
    T divide(){ return a/b;}
};
int main(){
    Calculator<int> c(4,2);
    cout<<"Addition: "<<c.add()<<endl;
    cout<<"Subtraction: "<<c.subtract()<<endl;
    cout<<"Multiplication: "<<c.multiply()<<endl;
    cout<<"Division: "<<c.divide()<<endl;
}