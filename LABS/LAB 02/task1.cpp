#include<iostream>
using namespace std;
int main(){
    int a = 15;
    int* ptr=&a;
    cout<<"Value: "<<a<<endl;
    cout<<"Address: "<<ptr<<endl;
    cout<<"Value using ptr: "<<*ptr<<endl;
}