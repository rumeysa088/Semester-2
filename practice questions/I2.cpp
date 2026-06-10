#include<iostream>
#include<string>
using namespace std;

class Animal{
public:
 void speak(){
    cout<<"Animal speaks"<<endl;
 }
    
};

class Dog : public Animal{
    public:
     void speak(){
    cout<<"Dog barks"<<endl;
 }
};

int main() {
    Animal a1; a1.speak();
    Dog d1; d1.speak();

    return 0;
}
