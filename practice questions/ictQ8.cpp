#include<iostream>
using namespace std;
class person{
    public:
   string name;
   int age;
   void displayInfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
   }
};
class student : public person{
   public: 
   int rollno;

   void displayRollno(){
     cout<<"Roll no: "<<rollno<<endl;
   }
};
int main(){
   student s1;
    s1.name="rumaisa";
    s1.age=17;
    s1.rollno=585;
    s1.displayInfo();
    s1.displayRollno();
}