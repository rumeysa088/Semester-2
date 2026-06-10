#include<iostream>
using namespace std;
int main(){
    int a = 15;
    int* ptr=&a;
    cout<<"Value Before: "<<a<<endl;
    *ptr=20;
    cout<<"Value After: "<<a<<endl;
    
}