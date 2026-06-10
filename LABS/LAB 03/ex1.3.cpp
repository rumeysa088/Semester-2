#include<iostream>
#include<string>
using namespace std;
class Car{
    public:
   string brand;
   string model;

   void display() { 
        cout << "Brand: " <<brand << endl;
        cout << "Model: " << model << endl;
    }
};

int main(){
   Car c;
   c.brand="toyota";
   c.model="corolla";
   c.display();
   return 0;
}