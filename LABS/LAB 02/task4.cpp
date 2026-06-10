#include<iostream>
using namespace std;
int main(){
    int* a = new int;
    cout<<"Enter value for a:"<<endl;
    cin>>(*a);
    cout<<"Value: "<<*a<<endl;
    delete a;
    a=nullptr;

}