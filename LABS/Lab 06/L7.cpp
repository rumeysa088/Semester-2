#include<iostream>
using namespace std;
class Base{
public:
    int publicVar=1;
protected:
    int protectedVar=2;
private:
    int privateVar=3;
};
class PublicDerived:public Base{
public:
    void show(){
        cout<<"PublicDerived publicVar: "<<publicVar<<endl;
        cout<<"PublicDerived protectedVar: "<<protectedVar<<endl;
        // cout<<privateVar; // Not accessible
    }
};
class ProtectedDerived:protected Base{
public:
    void show(){
        cout<<"ProtectedDerived publicVar: "<<publicVar<<endl;
        cout<<"ProtectedDerived protectedVar: "<<protectedVar<<endl;
        // cout<<privateVar; // Not accessible
    }
};
class PrivateDerived:private Base{
public:
    void show(){
        cout<<"PrivateDerived publicVar: "<<publicVar<<endl;
        cout<<"PrivateDerived protectedVar: "<<protectedVar<<endl;
        // cout<<privateVar; // Not accessible
    }
};
int main(){
    PublicDerived pd;
    pd.show();
    cout<<"Access publicVar through PublicDerived: "<<pd.publicVar<<endl;
    // cout<<pd.protectedVar;  Not accessible
    // cout<<pd.privateVar;   Not accessible
    cout<<endl;
    ProtectedDerived protd;
    protd.show();
    // cout<<protd.publicVar; Not accessible (became protected)
    cout<<endl;
    PrivateDerived privd;
    privd.show();
    // cout<<privd.publicVar; Not accessible (became private)
    return 0;
}