#include<iostream>
using namespace std;
class Animal{
    public:
     void eats(){
        cout<<"Animal is Eating\n";
     }
};
class dog : public Animal{
    public:
    void barks(){
       cout<<"Dog is Barking\n";
    }
};
int main(){
  dog d1;
   d1.eats();
   d1.barks();
}