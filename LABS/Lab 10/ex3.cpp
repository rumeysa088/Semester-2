#include<iostream>
using namespace std;
int main(){
    int age;
    cout<<"Enter Age: ";
    cin>>age;
    try{
        if(age<18)
        throw "Error! User Underage..";
    }
    catch(const char* s){
        cout<<s;
    }
    cout << "Program continues normally..." << endl;
}