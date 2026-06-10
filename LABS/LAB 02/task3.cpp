#include<iostream>
using namespace std;
void square(int* num){
    *num=(*num)*(*num);
}
int main(){
    int a = 5;
    cout<<"Value Before: "<<a<<endl;
    square(&a);
    cout<<"Value After: "<<a<<endl;
    
}